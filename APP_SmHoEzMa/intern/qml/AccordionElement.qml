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
            font.pointSize: 10
            text: title
        }

    }
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
            root.height += contentItem.height + itemCounter*20
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
              "Name":"test",
              "IP":"test",
              "GeraeteNummer":2,
              "Heat":2,
              "Light":null,
              "Colour":null,
              "Saturation":null,
              "Switch":null,
              "Brightness":null
           },
           {
              "DeviceID":2,
              "Name":"test2",
              "IP":"1.2.3.4",
              "GeraeteNummer":2,
              "Heat":null,
              "Light":null,
              "Colour":32,
              "Saturation":null,
              "Switch":null,
              "Brightness":null
           }
        ]
      */

    //This is function Karls fault because of his ugly json structure
    //(apparently it was to hard to create a array in the json that only contains the neccesary settings [as i heard it has something to do how the data is stored in the database])
    function createContent() {

        var contentObject = JSON.parse(contentJson)
        var settingsObject;
        var nameObject;
        var textString;

        itemCounter = 0;

        //check what of the settings are set and crete the corresponding items
        if(contentObject.Heat != null){
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Heat";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            textString = contentObject.Heat + "°C";
            settingsObject.text = textString;
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
//            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        if(contentObject.Light != null){
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Light";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            textString = contentObject.Light + "L";
            settingsObject.text = textString;
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
//            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        if(contentObject.Switch != null)
        {
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "On/Off";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Switch {}', contentLayout);
            settingsObject.checked = contentObject.Switch
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
//            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        if(contentObject.Brightness != null){
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Brightness";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {}', contentLayout);
            settingsObject.from = 0;
            settingsObject.to = 254;
            settingsObject.stepSize = 1
            settingsObject.value = contentObject.Brightness;
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        if(contentObject.Saturation != null){
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Saturation";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {}', contentLayout);
            settingsObject.from = 0;
            settingsObject.to = 254;
            settingsObject.stepSize = 1
            settingsObject.value = contentObject.Saturation;
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        if(contentObject.Hue != null){
            nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = "Hue";
            //Layout information
            nameObject.Layout.column = 0
            nameObject.Layout.row = itemCounter
//            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true

            settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {id: control; background: Image{source: "qrc:/ColorSpectrum"; x: control.leftPadding*2; anchors.verticalCenter: parent.verticalCenter; height: control.handle.height/2; width: control.width - control.leftPadding*2 - control.rightPadding*2}}', contentLayout);
            settingsObject.from = 0;
            settingsObject.to = 65535;
            settingsObject.stepSize = 1
            settingsObject.value = contentObject.Hue;
            //Layout information
            settingsObject.Layout.column = 1
            settingsObject.Layout.row = itemCounter
            settingsObject.Layout.fillWidth = true
            settingsObject.Layout.fillHeight = true
            settingsObject.Layout.alignment = Qt.AlignRight | Qt.AlignVCenter

            itemCounter++
        }
        /*
          //Code of the old json
        for(var i = 0; i < contentObject.length; i++) {
            var nameObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Label {}', contentLayout);
            nameObject.text = contentObject[i].Type;
            nameObject.Layout.row = i
            nameObject.Layout.column = 0
            nameObject.Layout.fillWidth = true
            nameObject.Layout.fillHeight = true
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
                settingsObject = Qt.createQmlObject('import QtQuick 2.0;import QtQuick.Controls 2.4; Slider {id: control; background: Image{source: "qrc:/ColorSpectrum"; x: control.leftPadding; y: control.topPadding; height: 5; width: control.width - control.leftPadding - control.rightPadding}}', contentLayout);
                settingsObject.from = 0;
                settingsObject.to = 65535;
                settingsObject.value = contentObject[i].Value;
//                settingsObject.style = hueSliderStyle;
                settingsObject.Layout.fillWidth = true
                settingsObject.Layout.fillHeight = true
                break;
            }
        }
        */
    }
}
