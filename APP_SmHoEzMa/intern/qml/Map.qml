import QtQuick 2.9
import QtQuick.Controls 1.2
import QtLocation 5.6
import QtPositioning 5.6


//Only contains the Map and a function to set a marker to the current position
Item {
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map

        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate( 50.9793, 11.0282)
        zoomLevel: 18

        MapQuickItem {
            id: marker
            anchorPoint.x: image.width/2
            anchorPoint.y: image.height
            coordinate: QtPositioning.coordinate( 50.9793, 11.0282)

            sourceItem: Image {
                id: image
                source: "qrc:/marker.png"
                width: 20
                height: 30
            }
        }

        PositionSource {
            id: positionSource
            active: true
            Component.onCompleted:  {
                var currentPosition = positionSource.position.coordinate;
                map.center = currentPosition;
                marker.coordinate = currentPosition;
            }
        }


    }

    function setPostion() {
        var currentPosition = positionSource.position.coordinate;
        map.center = currentPosition;
        marker.coordinate = currentPosition;
        return currentPosition;
    }
}

