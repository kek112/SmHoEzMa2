import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

//A single device
//This Object needs to be able to be partially hidden so only the title and an arrow of som sort are visible to indicate that this can be opened and closed

Rectangle {
    id: root
    property bool colabsed: false
    property string title: "Title"
    property string contentJson: ""

    property int itemCounter: 0
    property var switchObject: null
    property var homecomingObject: null

    color: "white"
    border.color: "black"
    border.width: 0
//    radius: 5

    //Header
    RowLayout {
        id: headerLayout
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        Image {
            id: headerImage
            Layout.preferredHeight: 24
            Layout.preferredWidth: 24
            source: colabsed ? "qrc:/ArrowDownIcon" : "qrc:/ArrowUpIcon"
        }
        Text {
            Layout.fillHeight: true
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
            font.bold: true
            text: title
        }

    }
    //press to collabse AccordionElement
    MouseArea {
        anchors.fill: headerLayout
        onClicked: {
            contentItem.visible = !contentItem.visible
            updateSize()
            colabsed = !colabsed
        }
    }

    //This item contains all the information of the device and is shown/hiden based on the state of the element
    Item {
        anchors.top: headerLayout.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        id: contentItem
        ColumnLayout {
            id: contentItemLayout
            anchors.fill: parent
            spacing: 0
            //Seperator
            Rectangle {
                id: seperator
                Layout.preferredHeight: 2
                Layout.preferredWidth: root.width - (root.border.width * 2 + 8)
                Layout.alignment: Qt.AlignCenter
                color: "grey"
                radius: 3
            }
            GridLayout {
                id: contentLayout
                Layout.alignment: Qt.AlignCenter
                Layout.margins: 5
            }
        }
    }

    function updateSize() {
        root.height = border.width * 2 + headerLayout.height
        if(contentItem.visible) {
            root.height += contentItem.height + itemCounter*25
        }
//        console.log(contentItemLayout.width + "x" + contentItemLayout.height)
    }
    Component.onCompleted: {
        createContent()
        updateSize()
    }

    /*
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
      */

    //TODO: connect settings to send the changes made in app to api
    //NOTE: rename switch to On/Off to make meaning clearer?
    function createContent() {

        var jsonOptionsList = ["Heat", "Light", "Switch", "Saturation", "Brightness", "Hue"]

        var contentObject = JSON.parse(contentJson)
        var settingsObject;
        var nameObject;
        var textString;

        itemCounter = 0;

        for(var i = 0; i < jsonOptionsList.length; i++) {
            var option = jsonOptionsList[i]
            //check if the option is set in the json --> create the corresponding label
            if(contentObject[option] != null) {
                nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
                nameObject.text = option;
                //Layout information
                nameObject.Layout.column = 0
                nameObject.Layout.row = itemCounter
                nameObject.Layout.fillWidth = true
                nameObject.Layout.fillHeight = true

                //create the UI element based on what type it is
                if(option == "Heat" || option == "Light") {
                    settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
                    textString = contentObject[option] + (option == "Heat" ? "°C" : "L");
                    settingsObject.text = textString;
                    //Layout information
                    settingsObject.Layout.column = 1
                    settingsObject.Layout.row = itemCounter
        //            settingsObject.Layout.fillWidth = true
                    settingsObject.Layout.fillHeight = true
                    settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

                    itemCounter++
                }
                else if(option == "Switch") {
                    settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Switch {}', contentLayout);
                    settingsObject.checked = contentObject[option]
                    switchObject = settingsObject
                    //Layout information
                    settingsObject.Layout.column = 1
                    settingsObject.Layout.row = itemCounter
        //            settingsObject.Layout.fillWidth = true
                    settingsObject.Layout.fillHeight = true
                    settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

                    itemCounter++
                }
                else if(option == "Saturation" || option == "Brightness") {
                    settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {}', contentLayout);
                    settingsObject.from = 0;
                    settingsObject.to = 254;
                    settingsObject.stepSize = 1
                    settingsObject.value = contentObject[option];
                    //Layout information
                    settingsObject.Layout.column = 1
                    settingsObject.Layout.row = itemCounter
                    settingsObject.Layout.fillWidth = true
                    settingsObject.Layout.fillHeight = true
                    settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

                    itemCounter++
                }
                else if(option == "Hue") {
                    settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {id: control; background: Item{}Image{source: "qrc:/ColorSpectrum"; x: control.leftPadding*2; anchors.verticalCenter: control.verticalCenter; height: control.handle.height/2; width: control.width - control.leftPadding*2 - control.rightPadding*2}}', contentLayout);
                    settingsObject.from = 0;
                    settingsObject.to = 65535;
                    settingsObject.stepSize = 1
                    settingsObject.value = contentObject[option];
                    //Layout information
                    settingsObject.Layout.column = 1
                    settingsObject.Layout.row = itemCounter
                    settingsObject.Layout.fillWidth = true
                    settingsObject.Layout.fillHeight = true
                    settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

                    itemCounter++
                }
            }
        }
        //create a Homecoming setting if the object has an on/off switch
        if(switchObject != null) {
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Homecoming";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//              nameObject.Layout.fillWidth = true
//              nameObject.Layout.fillHeight = true
            nameObject.horizontalAlignment = Text.AlignHCenter

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Switch {}', contentLayout);
            settingsObject.checked = false
            homecomingObject = settingsObject
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
//              settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
    }

    //check if the device can be switch off if yes do so
    function sleep() {
        if(switchObject != null) {
            switchObject.checked = false
        }
    }

    //turns on the device (if possible) if the homecoming setting is activated
    function home() {
        //check if the device has the homecomingObject (which it has if it has an on/off switch)
        if(homecomingObject != null) {
            //check if homecoming is activated and activate light and deactivate homecoming to prevent it be activated again unintentionally
            if(homecomingObject.checked == true) {
                switchObject.checked = true
                homecomingObject.checked = false
            }
        }
    }
}
