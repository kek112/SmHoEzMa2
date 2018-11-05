import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    property var devices: []
    property int currentActiveElement: 0
    property int buttonSize: 48
    focus: true
    ScrollView {
        anchors.fill: parent
        spacing: 10
        GridLayout {
            id: mainLayout

        }
    }
    Button {
        anchors.bottom: parent.bottom
        text: "addDebug"
        onPressed: {
            createDeviceObjects("AccordionElement.qml", {"Layout.row": devices.length,
                                "Layout.column": 0,
                                "color": "red",
                                "Layout.preferredHeight": 50,
                                "Layout.preferredWidth": 50})
        }
    }
    Button {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        text: "Debug"
        onPressed: loadDevices()
    }


    //functions that create and remove the device views


    function removeDevice () {
        if(devices.length != 0) {
            var element = devices[devices.length-1]
            element.destroy()
            devices.splice(devices.length-1, 1)
        }
    }

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
    function loadDevices() {
        var obj = JSON.parse('
{
    "Devices":[
        {
            "Name":"Außentemperatur",
            "Ip":"10.10.10.10",
            "Settings":[
                { "Type":"Heat", "Value":15}
                ]
        },
        {
            "Name":"Flur Lampe",
            "Ip":"10.10.10.11",
            "Settings":[
                { "Type":"Saturation", "Value":100},
                { "Type":"Brightness", "Value":100}
                ]
        }
    ]
}');
        for(var i = 0; i < obj.Devices.length; i++) {
            var labelText = obj.Devices[i].Name
            var newObject = Qt.createQmlObject('import QtQuick 2.0; import QtQuick.Controls 2.2; Label {}',
                                               mainLayout,
                                               "dynamicSnippet1");
            newObject.Layout.preferredWidth= 50;
            newObject.Layout.preferredHeight= 50;
            newObject.text = labelText;
        }

    }

}
