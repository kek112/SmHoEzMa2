import QtQuick 2.0
import QtQuick.Layouts 1.3

//A single device
//This Object needs to be able to be partially hidden so only the title and an arrow of som sort to indicate that this can be opened and closed

Rectangle {
    id: root
    property bool colabsed: true
    property string title: "Title"
    property string contentJson: ""

    color: "transparent"
    border.color: "black"
    border.width: 3
    radius: 5

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        //Header
        RowLayout {
            Image {
                id: headerImage
                Layout.preferredHeight: 24
                Layout.preferredWidth: 24
                source: colabsed ? "qrc:/ArrowDownIcon" : "qrc:/ArrowUpIcon"
            }
            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
//                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                verticalAlignment: Text.AlignVCenter
                text: title
            }
        }
        //This item contains all the information of the device and is shown/hiden based on the state of the element
        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
            ColumnLayout {
                //Seperator
                Rectangle {
                    id: seperator
                    Layout.preferredHeight: 5
                    Layout.preferredWidth: mainLayout.width - root.border.radius * 2 + 6
                    color: "grey"
                }
                GridLayout {
                    id: contentLayout
                }
            }
        }
    }
    function updateHeight() {
        root.height = border.width * 2 + headerImage.height
    }
    Component.onCompleted: updateHeight()

    function updateContent() {
        var contentObject = JSON.parse(contentJson)

    }
}
