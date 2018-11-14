import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

//App Menu which
Item {
    Keys.forwardTo: parent
    property string menuColor: "red"
    property var mainItem: mainViewButton.stackItem

    //signal which sends the corrseponding item of the pressed button
    //this gets handled in the MainView
    signal menuButtonPressed(var item)

    //central handling of Button presses
    ButtonGroup {
        id: menuButtonGroup
        onClicked: {
            menuButtonPressed(button.stackItem)
        }
    }

    Rectangle {
        color: menuColor

        anchors.fill: parent

        //Layout that holds all menu buttons
        ColumnLayout {
            anchors.fill: parent
            spacing: 0
            MenuEntry {
                id: mainViewButton
                entryText: "Devices"
                iconSource: "qrc:/DeviceHubIcon"

                Layout.fillWidth: true

                ButtonGroup.group: menuButtonGroup
                stackItem: DeviceListView {}
            }
            MenuEntry {
                entryText: "Settings"
                iconSource: "qrc:/SettingsIcon"

                Layout.fillWidth: true

                ButtonGroup.group: menuButtonGroup
            }
            MenuEntry {
                entryText: "Sleep"
                iconSource: "qrc:/AddIcon"

                Layout.fillWidth: true

                ButtonGroup.group: menuButtonGroup
            }
            MenuEntry {
                entryText: "Info"
                iconSource: "qrc:/InfoIcon"

                Layout.fillWidth: true

                ButtonGroup.group: menuButtonGroup
                stackItem: InfoView {}
            }
            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }


}
