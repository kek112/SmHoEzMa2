import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtLocation 5.6
import QtPositioning 5.6

Item {
    id: test
    property var devices: []
    property int currentActiveElement: 0
    property int buttonSize: 48
    property int fullHeight: 0

    property string apiIpAddress: ""
    property var homePosition: null

    property var settingsMenu: Menu {
        id: deviceSettingsMenu
        x: mainView.width - deviceSettingsMenu.width
        y: 0
        MenuItem {
            text: "Sleep"
            onClicked: {
                mainStack.currentItem.sleepAllDevices();
            }
        }
        MenuItem {
            text: "Reload"
            onClicked: {
                mainStack.currentItem.loadDevices();
            }
        }
    }

    ScrollView {
        id: mainScrollView
        anchors.fill: parent
        anchors.margins: 5
//        padding: 5
        ListView {
            id: mainListView
            anchors.fill: parent

            spacing: 8

            model: deviceModel
            delegate: AccordionElementWShadow {
                title: elementTitle
                contentJson: content
                width: mainScrollView.width

            }

        }
    }

    ListModel {
        id: deviceModel
    }
    Component.onCompleted: {
        loadDevices()
    }

    //function to load the devices and show them on the ui
    //it first clears the deviceModel and then loads the devices from the json that gets loaded from the api
    //TODO: get data from server

    function loadDevices() {
        deviceModel.clear()
        var obj = JSON.parse('
        [
           {
              "DeviceID":1,
              "Name":"Außen Temperatur",
              "IP":"test",
              "GeraeteNummer":2,
              "Heat":10,
              "Light":null,
              "Colour":null,
              "Saturation":null,
              "Switch":null,
              "Brightness":null
           },
           {
              "DeviceID":2,
              "Name":"Flur Lampe",
              "IP":"1.2.3.4",
              "GeraeteNummer":2,
              "Heat":null,
              "Light":null,
              "Hue":10000,
              "Saturation":100,
              "Switch":false,
              "Brightness":100
           }
        ]
        ');
        for (var i = 0; i < obj.length; i++) {
            deviceModel.append({"elementTitle": obj[i].Name, "content": JSON.stringify(obj[i])})
        }
    }
    function sleepAllDevices() {
        for(var i = 0; i < mainListView.count; i++) {
            mainListView.currentIndex = i
            mainListView.currentItem.sleep()
        }
    }

    PositionSource {
        id: positionSource
        active: true
        Component.onCompleted:  {
            var currentPosition = positionSource.position.coordinate;
            map.center = currentPosition;
            marker.coordinate = currentPosition;
        }
    }

    //activate worker thread every 5s
    Timer {
        interval: 5000; running: true; repeat: true
        onTriggered: worker.sendMessage()
    }

    //function is activatet in a thread to make sure it doesnt block the app
    WorkerScript {
        id: worker
        onMessage: {
            //check if the homePosition has been set
            if (homePosition != null) {
                //check if the person is closer than 50m to the homePosition
                if(positionSource.position.coordinate.distanceTo(homePosition) < 50) {
                    //iterate through the devices and activate the home function which checks if the homecoming switch is activated --> activate light and deactivate homecoming
                    for(var i = 0; i < mainListView.count; i++) {
                        mainListView.currentIndex = i
                        mainListView.currentItem.home()
                    }
                }
            }


        }
    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    property var component;
    property var device;

    //this function loads the component contained in the file "AccordionElement.qml"
    function createDeviceObjects(fileName, settings) {
        component = Qt.createComponent(fileName);
        if (component.status == Component.Ready) {
            finishCreation();
        }
        else {
            component.statusChanged.connect(finishCreation(settings));
        }
    }
    //this function actually creates the object from the loaded component
    function finishCreation(settings) {
        if (component.status == Component.Ready) {
            console.log(devices.length)
            // apperantly this function runs multiple times, for an unknown reason the first times it runs devices.lenght = 0,
            //the second time it runs it uses the actual value and works as it should
            device = component.createObject(mainLayout, settings);

            if (device == null) {
                // Error Handling
                console.log("Error creating object");
            }
            else {
                devices.push(device)
                console.log(devices.length)
                currentActiveElement = devices.length-1
            }
        } else if (component.status == Component.Error) {
            // Error Handling
            console.log("Error loading component:", component.errorString());
        }
    }
    */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
