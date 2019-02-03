import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4


/*
  Custom Button for menu entrys
  Even though a "Button" has an in build icon function this can't be used as the content is always centerd instead of the wanted left alignment
  */
Button {
    Keys.forwardTo: parent
    id: root
    flat: true

    property string entryText: "Entry"
    property string iconSource: "qrc:/removeIcon"
    property int iconSizeDiffrence: 20

    //holds the corresbonding item of the menu entry
    property var stackItem: Item{}

    RowLayout {
        anchors.fill: parent
        Image {
            source: iconSource
            Layout.preferredHeight: root.height - iconSizeDiffrence;
            Layout.preferredWidth: root.height - iconSizeDiffrence;
        }
        Text {
            text: entryText
            font.pointSize: 13
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: true
        }
    }
}
