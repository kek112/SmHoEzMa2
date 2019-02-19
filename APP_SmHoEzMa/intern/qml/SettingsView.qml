import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

//The "SettingsView" that contains a field to enter the API IP address and the map with a button to set the current location
Item {
    property string apiIpAddress: ""
    property var homePosition: null

    id: root
    GridLayout {
        anchors.fill: parent
       Label {
           text: "Server IP address:"
           Layout.row: 0
           Layout.column: 0
       }
       TextField {
           placeholderText: "___.___.___.___"   //IP Template
           Layout.row: 0
           Layout.column: 1
           inputMask: "000.000.000.000;_"
           onTextChanged: {
               apiIpAddress = text;
           }
       }
       Map {
           id: map
           Layout.row: 1
           Layout.column: 0
           Layout.columnSpan: 2
           Layout.fillHeight: true
           Layout.fillWidth: true
       }
       Button {
           text: "Set Home"
           Layout.row: 2
           Layout.column: 0
           Layout.columnSpan: 2
           Layout.alignment: Qt.AlignCenter
           Layout.fillWidth: true
           onPressed: {
               homePosition = map.setPostion()
           }
       }

    }
}
