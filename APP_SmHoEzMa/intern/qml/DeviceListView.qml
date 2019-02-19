import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtLocation 5.6
import QtPositioning 5.6

//This Object contains list of the devices ("AccordionElemt")
Item {
    id: root
    property int currentActiveElement: 0
    property int buttonSize: 48
    property int fullHeight: 0

    property string apiIpAddress: ""
    property var homePosition: null

    //This property needs to be set and needs to be a "Menu" type so the "MainView" can use it to display the 3 dot context menu
    property var settingsMenu: Menu {
        id: deviceSettingsMenu
        //The loaction of the menu should not be set here. (Even tho the mainView Object can be refrenced from aanother file it's not very good code style)
//        x: mainView.width - deviceSettingsMenu.width
//        y: 0
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

    //Simple "ScrollView" to allow a lot of devices
    ScrollView {
        id: mainScrollView
        anchors.fill: parent
        anchors.margins: 5
//        padding: 5

        //This "ListView" contains the actual Devices
        ListView {
            id: mainListView
            anchors.fill: parent

            spacing: 8

            //The model holds the data ("elementTitle", "content", "ipAddress")
            model: deviceModel

            //The accordion properties get set here with the data from the "ListModel"
            delegate: AccordionElementWShadow {
                title: elementTitle
                contentJson: content
                apiIpAddress: ipAddress
                width: mainScrollView.width
            }
        }
    }

    //The model holds the data ("elementTitle", "content", "ipAddress")
    //If the model is changed the "ListView" gets updated accordingly
    ListModel {
        id: deviceModel
    }

    //When the root item is finished loading it tries to load the devices
    Component.onCompleted: {
        loadDevices()
    }

    //Function to load the devices and show them on the ui
    //It first clears the "deviceModel" and then loads the devices from the json that gets requested from the api
    function loadDevices() {
        deviceModel.clear()
        var url = "http://"+apiIpAddress+":5003/api/alldevices";
        var xmlHttp = new XMLHttpRequest();
        xmlHttp.open( "GET", url, false ); // false for synchronous request
        xmlHttp.send();
        var json = xmlHttp.responseText;

        var obj = JSON.parse(json)
//      Example json
//        var obj = JSON.parse('
//        [
//           {
//              "DeviceID":1,
//              "Name":"Außen Temperatur",
//              "IP":"test",
//              "GeraeteNummer":2,
//              "Heat":10,
//              "Light":null,
//              "Colour":null,
//              "Saturation":null,
//              "Switch":null,
//              "Brightness":null
//           },
//           {
//              "DeviceID":2,
//              "Name":"Flur Lampe",
//              "IP":"1.2.3.4",
//              "GeraeteNummer":2,
//              "Heat":null,
//              "Light":null,
//              "Hue":10000,
//              "Saturation":100,
//              "Switch":false,
//              "Brightness":100
//           }
//        ]
//        ');

        for (var i = 0; i < obj.length; i++) {
            deviceModel.append({"elementTitle": obj[i].Name, "content": JSON.stringify(obj[i]), "ipAddress": apiIpAddress})
        }
    }

    //Calls the sleep function on all the objects in the "ListView"
    function sleepAllDevices() {
        for(var i = 0; i < mainListView.count; i++) {
            mainListView.currentIndex = i
            mainListView.currentItem.sleep()
        }
    }

    PositionSource {
        id: positionSource
        active: true
    }

    //activate worker thread every 5s --> calls "onMessage" every 5s
    Timer {
        interval: 5000; running: true; repeat: true
        onTriggered: worker.message(null)
    }

    //function is activatet in a thread to make sure it doesnt block the app
    WorkerScript {
        id: worker
        onMessage: {
            //check if the "homePosition" has been set
            if (homePosition != null) {
                //check if the person is closer than 50m to the "homePosition"
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
