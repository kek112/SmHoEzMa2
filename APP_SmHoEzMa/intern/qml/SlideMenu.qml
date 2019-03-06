import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

//App Menu which contains all the menu buttons and the corresponding Objects
Drawer {
    property var mainItem: mainViewButton.stackItem
    property bool isOpen: false

    //signal which sends the corrseponding item of the pressed button
    //this gets handled in the "MainView"
    signal menuButtonPressed(var item)

    //The Buttons are all added to this "ButtonGroup" for easy button handling
    ButtonGroup {
        id: viewButtonGroup
        onClicked: {
            menuButtonPressed(button.stackItem)
            closeMenu()
        }
    }
    //Alternatively a single function could be written an set to the onClicked signal of the buttons

    //These functions are needed for better handling with the Menu Button States
    function openMenu() {
        open();
        isOpen = true;
    }
    function closeMenu() {
        close();
        isOpen = false;
    }

    //Layout that holds all menu buttons
    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        //One "MenuItem" is one button in the menu

        MenuItem {
            id: mainViewButton
            text: "Devices"
            icon.source: "qrc:/DeviceHubIcon"

            Layout.fillWidth: true

            ButtonGroup.group: viewButtonGroup
            property var stackItem: DeviceListView {
                apiIpAddress: settingsView.apiIpAddress
                homePosition: settingsView.homePosition
            }
        }
        MenuItem {
            text: "Settings"
            icon.source: "qrc:/SettingsIcon"

            Layout.fillWidth: true

            ButtonGroup.group: viewButtonGroup
            property var stackItem: SettingsView {
                id: settingsView
            }
        }

        MenuItem {
            text: "Info"
            icon.source: "qrc:/InfoIcon"

            Layout.fillWidth: true

            ButtonGroup.group: viewButtonGroup
            property var stackItem: InfoView {}
        }

        //Filler Item to push all buttons to the top
        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }


}
