import QtQuick 2.11
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3

/*
    MainView
    The root view of the app that controlls all other views.
    Contains the StackView that gets the diffrent Views from the "SlideMenu".
*/
ApplicationWindow {
    id: mainView
    visible: true

    //for testing purposes on desktop
    height: 480//960
    width: 270//540

    property int headerHeight: 48

    //Setting the Style of the App
    //this is usally passed down from the parent to the children
    //https://doc.qt.io/qt-5.11/qtquickcontrols2-material.html
    Material.accent: Material.LightBlue
    Material.foreground: "black"
    Material.primary: "#cde7ff"

    //function that controls the state of the menu and menu button
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
            //Optional settings button that only shows if the curren view has the "settingsMenu" property
            //When this button is pressed it tries to open the "Menu" via the "settingsMenu" --> if the "settingsMenu" does not implement the open function nothing happens
            ToolButton {
                text: "⋮"
                font.pointSize: 27
                onClicked: {
                    //Place the "Menu" in the top right corner and show it
                    mainStack.currentItem.settingsMenu.x = mainView.width - mainStack.currentItem.settingsMenu.width
                    mainStack.currentItem.settingsMenu.y = 0
                    mainStack.currentItem.settingsMenu.open()
                }
                //Checks if the current view has the "settingsMenu" property. Thanks to the property bindings this automaticaly updates if the "currentItem" changes
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



    //The Slide Menu that contains all the other views
    SlideMenu {

        id: menu

        y: header.height
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


        //Pushing items on the main stack based on menu button pressed. This function is triggerd by a signal in "SlideMenu"
        onMenuButtonPressed: {
            mainStack.push(item)
            if(mainStack.depth <= 1) {
                menuButton.menuButtonState = "menu"
            }

        }

    }

    //NOTE: WIP
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
