import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtLocation 5.6
import QtPositioning 5.6

Item {
    id: root
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
                apiIpAddress: ipAddress
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
        var url = "http://"+apiIpAddress+":5003/api/alldevices";
        var xmlHttp = new XMLHttpRequest();
        xmlHttp.open( "GET", url, false ); // false for synchronous request
        xmlHttp.send();
        var json = xmlHttp.responseText;

//                var http = new XMLHttpRequest()
//                var params = "num=22&num2=333";
//                http.open("GET", url, true);

//                // Send the proper header information along with the request
//                http.setRequestHeader("Content-type", "application/json");
//                //http.setRequestHeader("Content-length", params.length);
//                http.setRequestHeader("Connection", "close");

//                http.onreadystatechange = function() { // Call a function when the state changes.
//                            if (http.readyState == 4) {
//                                if (http.status == 200) {
//                                    console.log("ok")
//                                } else {
//                                    console.log("error: " + http.status)
//                                }
//                            }
//                        }
//                //http.send(params);
//        var json = http.responseText;
        var obj = JSON.parse(json)
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

    //activate worker thread every 5s
    Timer {
        interval: 5000; running: true; repeat: true
        onTriggered: worker.message(null)
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
