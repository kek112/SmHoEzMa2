import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3

/*!
    \qmltype MainView
    \brief The root view of the app that controlls all other views.


    The MainView displays the app header, devices and the buttons to add and remove said devices.
    The device list is a custom made Accordion
*/
ApplicationWindow {
    id: mainView
    visible: true

    height: 480//960
    width: 270//540

    property int headerHeight: 48

    //Setting the Style of the App
    //this is usally passed down from the parent to the children
    //https://doc.qt.io/qt-5.11/qtquickcontrols2-material.html
    Material.accent: Material.LightBlue
    Material.foreground: "black"
    Material.primary: Material.Blue

    function processMenuPress() {
        if(menu.state == "open") {
            menu.state = "closed"
        }
        else if(mainStack.depth > 1) {
            mainStack.pop()
        }
        else {
            menu.state = "open"
        }
        if(menu.state == "open" || mainStack.depth > 1) {
            menuButton.menuButtonState = "back"
        }
        else {
            menuButton.menuButtonState = "menu"
        }
    }

    //Header bar with Menubutton and Title
    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            HamburgerIcon {
                id: menuButton
                iconColor: Material.foreground
                color: Material.primary
                onButtonClicked: {
                    processMenuPress()
                }
            }
            Text {
                text: "SmHoEzMa"
                font.pointSize: 15
            }
        }
    }

    //Main item stack wich can push and pop the UI Items
    //the views to the corresponding button are all handeld in the SlideMenu so they are not spread over multiple files
    StackView {
        id: mainStack
        anchors.fill: parent
        initialItem: menu.mainItem
    }



    property int animationDuration: 350
    SlideMenu {

        id: menu
        anchors.top: mainStack.top
        anchors.bottom: mainStack.bottom
//        y: 0
//        height: mainView.height
        width: mainView.width*0.8

        menuColor: "white"

        //set standard state
        state: "closed"
        //Define multiple animation states (x coordinate needs to be changed)
        states: [
            State {
                name: "closed"
                PropertyChanges { target: menu; x: menu.width*-1 }
            },
            State {
                name: "open"
                PropertyChanges { target: menu; x: 0 }
            }
        ]
        //Define transistion information like type and duration
        transitions: [
            Transition {
                PropertyAnimation { target: menu; properties: "x"; duration: animationDuration; easing.type: Easing.InOutQuad }
            }
        ]

        //pushing items on the main stack based on menu button pressed
        onMenuButtonPressed: {
            mainStack.push(item)
            if(mainStack.depth <= 1) {
                menuButton.menuButtonState = "menu"
            }

        }
        onCloseMenu: {
            state = "closed"
        }
//        onXChanged: {
//            if(menu.x > -(menu.width/2)) {
//                menu.state = "closed"
//                menu.state = "open"
//                menuButton.menuButtonState = "back"
//            }
//            else if(menu.x <= -(menu.width/2)) {
//                menu.state = "open"
//                menu.state = "closed"
//                menuButton.menuButtonState = "menu"
//            }
//        }

    }

    PropertyAnimation {id: closeMenuAnimation; target: menu; properties: "x"; to: -(menu.width); duration: animationDuration; easing.type: Easing.InOutQuad }
    PropertyAnimation {id: openMenuAnimation; target: menu; properties: "x"; to: 0; duration: animationDuration; easing.type: Easing.InOutQuad }

    MouseArea {
        id: slideArea

        width: 20
        anchors.top: menu.top
        anchors.left: menu.right
        anchors.bottom: menu.bottom

        property int lastMenuX;

        //check if menu is extended if yes close it otherwise relay the mousclick to the parent
        onClicked: {
            if(menu.state == "open") {
                menu.state = "closed"
                mouse.accepted = true
            } else {
                mouse.accepted = false
            }
        }
//        onPressed: {
//            lastMenuX = menu.x
//        }
//        onReleased: {
//            if(lastMenuX == menu.x) {
//                if(menu.state == "open") {
//                    menu.state = "closed"
//                    menuButton.menuButtonState = "menu"
//                } else {
//                    mouse.accepted = false
//                }
//            } else {
//                if(menu.x > -(menu.width/2)) {
//                    menu.state = "closed"
//                    menu.state = "open"
//                    menuButton.menuButtonState = "back"
//                }
//                else if(menu.x <= -(menu.width/2)) {
//                    menu.state = "open"
//                    menu.state = "closed"
//                    menuButton.menuButtonState = "menu"
//                }
//            }
//        }

        drag.target: menu
        drag.axis: Drag.XAxis
        drag.minimumX: -menu.width
        drag.maximumX: 0
    }

    //handling back key press or backspace on pc
    //currently only gets handeld when app displays mainView (other views propably take focus)
    Item {
        focus: true

        Keys.onPressed: {
            if (event.key == Qt.Key_Back || event.key == Qt.Key_Backspace) {
                if(menuButton.menuButtonState == "back") {
                    processMenuPress()
                    event.accepted = true;
                }
            }
        }
    }
}
