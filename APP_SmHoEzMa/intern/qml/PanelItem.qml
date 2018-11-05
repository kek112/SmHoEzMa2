import QtQuick 2.7
import QtQuick.Layouts 1.2

//https://stackoverflow.com/questions/39489562/proper-way-to-create-accordion-control-using-qml
Item {
    default property var contentItem: null
    property string title: "panel"
    id: root
    Layout.fillWidth: true
    height: 30
    Layout.fillHeight: current
    property bool current: false
    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        Rectangle {
            id: bar
            Layout.fillWidth: true
            height: 30
            color:  root.current ? "#81BEF7" : "#CEECF5"
            Text {
                anchors.fill: parent
                anchors.margins: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                text: root.title
            }
            Text {
                anchors{
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    margins: 10
                }
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text: "^"
                rotation: root.current ? "180" : 0
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    root.current = !root.current;
                    if(root.parent.currentItem !== null)
                        root.parent.currentItem.current = false;

                    root.parent.currentItem = root;
                }
            }
        }
        Rectangle {
            id: container
            Layout.fillWidth: true
            anchors.top: bar.bottom
            implicitHeight: root.height - bar.height
            clip: true
            Behavior on implicitHeight {
                PropertyAnimation { duration: 100 }
            }
        }
        Component.onCompleted: {
            if(root.contentItem !== null)
                root.contentItem.parent = container;
        }
    }
}
