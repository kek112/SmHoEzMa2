import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    property var devices: []
    property int currentActiveElement: 0
    property int buttonSize: 48
    property int fullHeight: 0

    ScrollView {
        id: mainScrollView
        anchors.fill: parent
        padding: 5
        ListView {
            id: mainLayout
            anchors.fill: parent

            spacing: 5

            model: deviceModel
            delegate: AccordionElement {
                title: elementTitle
                contentJson: content
                width: parent.width
            }

        }
    }

    ListModel {
        id: deviceModel
    }
    Button {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        text: "Debug"
        onPressed: {
            if(deviceModel.count == 0) {
                loadDevices()
            }
            else {
                deviceModel.clear()
            }
        }
    }


    //functions that create and remove the device views
    function clearDevices () {
        if(devices.length != 0) {
            for(var i = devices.length-1; i <= 0; i++)
            {
                var element = devices[i]
                element.destroy()
                devices.splice(i, 1)
            }


        }
    }

    function loadDevices() {
        var obj = JSON.parse('
        [
           {
              "DeviceID":1,
              "Name":"außentemp",
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
              "Hue":1000,
              "Saturation":100,
              "Switch":true,
              "Brightness":100
           }
        ]
        ');
        for (var i = 0; i < obj.length; i++) {
            deviceModel.append({"elementTitle": obj[i].Name, "content": JSON.stringify(obj[i])})
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
