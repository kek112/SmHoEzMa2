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


    //Header bar with Menubutton and Title
    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            HamburgerIcon {
                id: menuButton
                iconColor: Material.foreground
                color: Material.primary
                onMenuStateChanged: {
                    menu.state = menuState === "menu" ? "closed" : "open"
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
//        height: mainStack.height
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
            menuButton.menuState = "menu" //automatically closes menu
        }
        onCloseMenu: {
            menuButton.menuState = "menu"
        }
    }

    //handling back key press
    //TODO: currently the Key is processed in a child (probably)
    //solutions: forward the KeyEvent or handle it in the corresponding object (this would mean the Key function needs to be written in every object, maybe a EventHandler can be used like in QtC++)
    Item {
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Back || event.key == Qt.Key_Backspace) {
                if(menu.state === "open") {
                    menuButton.menuState = "menu" //automatically closes menu
                }
                else if (mainStack.depth > 1) {
                    mainStack.pop()
                }
            }
        }
    }
}
