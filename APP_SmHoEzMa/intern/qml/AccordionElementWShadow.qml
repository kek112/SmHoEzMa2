import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    property string title: "Title"
    property string contentJson: ""
    height: element.height


    AccordionElement {
        id: element
        title: root.title
        contentJson: root.contentJson
        width: root.width
    }
    //Draws a shadow under the source (the accrodion element)
    DropShadow {
        id: rectShadow
        anchors.fill: source
        cached: true
        horizontalOffset: 3
        verticalOffset: 3
        radius: 8.0
        samples: 16
        color: "#80000000"
        smooth: true
        source: element
    }

    function sleep() {
        element.sleep()
    }
}
