import QtQuick 2.0
import QtQuick.Controls 2.4

Item {

    Label {
        id: titleLabel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        text: "\nSmart Home Easy Maker\n
SmHoEzMa"
        horizontalAlignment: Text.AlignHCenter
    }
    Label {
        anchors.top: titleLabel.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: "\n\nCreated by:\n
- Tobias Rieß\n
- Karl-Erik Kley\n
- Martin Lesser"
        horizontalAlignment: Text.AlignLeft
    }
}
