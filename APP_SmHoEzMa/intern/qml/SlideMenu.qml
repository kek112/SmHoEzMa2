import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

//App Menu which contains all the menu buttons and the coresponding
Drawer {
//    Keys.forwardTo: parent
    //    property string menuColor: "red"
    property var mainItem: mainViewButton.stackItem
    property bool isOpen: false

    //signal which sends the corrseponding item of the pressed button
    //this gets handled in the MainView
    signal menuButtonPressed(var item)

    //central handling of Button presses
    ButtonGroup {
        id: viewButtonGroup
        onClicked: {
            menuButtonPressed(button.stackItem)
            closeMenu()
        }
    }

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

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }


}
