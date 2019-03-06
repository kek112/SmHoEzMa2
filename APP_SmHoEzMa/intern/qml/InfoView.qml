import QtQuick 2.0
import QtQuick.Controls 2.4

//Simple "InfoView" containing a even simpler "Label"
Item {

    Label {
        id: titleLabel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        text: "\nSmart Home Easy Maker
SmHoEzMa\n
Created by:
Tobias Rieß
Karl-Erik Kley
Martin Lesser"
        horizontalAlignment: Text.AlignHCenter
    }
}
