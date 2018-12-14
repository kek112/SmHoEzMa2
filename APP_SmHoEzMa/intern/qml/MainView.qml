import QtQuick 2.11
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
    Material.primary: "#cde7ff"

    //function that controls menu and menu button
    function processMenuPress() {
        if(menu.isOpen) {
            menu.closeMenu()
        }
        else if(mainStack.depth > 1) {
            mainStack.pop()
        }
        else {
            menu.openMenu()
        }
        if(menu.isOpen || mainStack.depth > 1) {
            menuButton.menuButtonState = "back"
        }
        else {
            menuButton.menuButtonState = "menu"
        }
    }



    //Header bar with Menubutton, title and posibly a settings button
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
                Layout.fillWidth: true
            }
            ToolButton {
                text: "⋮"
                font.pointSize: 27
                onClicked: mainStack.currentItem.settingsMenu.open()
                visible: mainStack.currentItem.settingsMenu != null
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
//        anchors.top: mainStack.top
//        anchors.bottom: mainStack.bottom

//        property bool menuFullyOpened: menu.x == 0 ? true : (menu.x == -(menu.width) ? false : menuFullyOpened)

        y: header.height
//        height: mainView.height
        width: mainView.width*0.8
        height: mainView.height - header.height

        onClosed: {
            isOpen = false;
            if(mainStack.depth > 1) {
                menuButton.menuButtonState = "back"
            } else {
                menuButton.menuButtonState = "menu"
            }
        }
        onOpened: {
            isOpen = true;
            menuButton.menuButtonState = "back"
        }


        //pushing items on the main stack based on menu button pressed
        onMenuButtonPressed: {
            mainStack.push(item)
            if(mainStack.depth <= 1) {
                menuButton.menuButtonState = "menu"
            }

        }

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
