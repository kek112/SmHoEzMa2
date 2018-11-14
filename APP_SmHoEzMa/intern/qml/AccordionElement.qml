import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

//A single device
//This Object needs to be able to be partially hidden so only the title and an arrow of som sort are visible to indicate that this can be opened and closed

Rectangle {
    id: root
    property bool colabsed: false
    property string title: "Title"
    property string contentJson: ""

    color: "transparent"
    border.color: "black"
    border.width: 3
    radius: 5

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
            text: title
        }

    }
    MouseArea {
        anchors.fill: parent
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
                Layout.preferredHeight: 3
                Layout.preferredWidth: mainLayout.width - (root.border.width * 2 + 6)
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
            root.height += contentItem.height + 22
        }
//        console.log(contentItemLayout.width + "x" + contentItemLayout.height)
    }
    Component.onCompleted: {
        createContent()
        updateSize()
    }
    SliderStyle {
        id: hueSliderStyle
        groove: Image {
            source: "qrc:/ColorSpectrum"
        }
    }

    /*
    [
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
      */

    function createContent() {
        /*
    var SettingsSliderString = 'import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Item {
    property string settingsName: "name"
    property int sliderFrom: 0
    property int sliderTo: 255
    RowLayout {
        anchors.fill: parent
        Label {
            text: settingsName
        }
        Slider {
            id: slider
            from: sliderFrom
            to: sliderTo
        }
    }
    function setValue(_value) {
        slider.value = _value
    }
    function getValue() {
        return slider.value
    }
}'
    var SettingsSensorString = 'import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Item {
    property string settingsName: "name"
    property int settingsValue: 0
    property string settingsUnit: "°C"

    RowLayout {
        anchors.fill: parent
        Label {
            text: settingsName
        }
        Label {
            text: settingsValue + settingsUnit
        }
    }
}'

            case "Saturation":
                settingsObject = Qt.createQmlObject(SettingsSliderString, contentLayout)
                settingsObject.Layout.row = i
                settingsObject.Layout.column = 0
                settingsObject.settingsName = "Saturation"
                seetingsObject.setValue(contentObject[i].Value)
                break;
            case "Brightness":
                settingsObject = Qt.createQmlObject(SettingsSliderString, contentLayout)
                settingsObject.Layout.row = i
                settingsObject.Layout.column = 0
                settingsObject.settingsName = "Brightness"
                seetingsObject.setValue(contentObject[i].Value)
                break;
            case "Heat":
                settingsObject = Qt.createQmlObject(SettingsSliderString, contentLayout)
                settingsObject.Layout.row = i
                settingsObject.Layout.column = 0
                settingsObject.settingsName = "Heat"
                settingsObject.settingsValue = contentObject[i].Value
                settingsObject.settingsUnit = "°C"
                break;
            case "Light":
                settingsObject = Qt.createQmlObject(SettingsSliderString, contentLayout)
                settingsObject.Layout.row = i
                settingsObject.Layout.column = 0
                settingsObject.settingsName = "Light"
                settingsObject.settingsValue = contentObject[i].Value
                settingsObject.settingsUnit = "Lm"
                break;
*/

        var contentObject = JSON.parse(contentJson)
        for(var i = 0; i < contentObject.length; i++) {
            var nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = contentObject[i].Type;
            nameObject.Layout.row = i
            nameObject.Layout.column = 0
            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true
            var settingsObject;
            switch(contentObject[i].Type) {
            case "Heat":
            case "Light":
                settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
                var textString = contentObject[i].Value + (contentObject[i].Type == "Heat" ? "°C" : "L");
                settingsObject.text = textString;
                settingsObject.Layout.column = 1
                settingsObject.Layout.row = i
                settingsObject.Layout.fillWidth = true
                settingsObject.Layout.fillHeight = true
                break;
            case "Saturation":
            case "Brightness":
                settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {}', contentLayout);
                settingsObject.from = 0;
                settingsObject.to = 254;
                settingsObject.value = contentObject[i].Value;
                settingsObject.Layout.fillWidth = true
                settingsObject.Layout.fillHeight = true
                break;
            case "Hue":
                settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {}', contentLayout);
                settingsObject.from = 0;
                settingsObject.to = 65535;
                settingsObject.value = contentObject[i].Value;
                settingsObject.style = hueSliderStyle;
                settingsObject.Layout.fillWidth = true
                settingsObject.Layout.fillHeight = true
                break;
            }
        }
    }
}
