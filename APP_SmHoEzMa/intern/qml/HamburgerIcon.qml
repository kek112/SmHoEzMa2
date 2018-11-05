import QtQuick 2.2


/*!
  Slight adjusted version of this Github gist
  https://gist.github.com/cyberbobs/8d62ab257d332914a72c
*/
Rectangle {
    Keys.forwardTo: parent
    width: 48
    height: 48

    //added a property to change the color of the MenuIcon
    property string iconColor: "white"
    property string menuState: "menu"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            menuState = menuState === "menu" ? "back" : "menu"
        }
    }

    MenuBackIcon {
        id: menuBackIcon
        anchors.centerIn: parent
        barColor: iconColor
        state: menuState
    }
}
