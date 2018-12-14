import QtQuick 2.0
import QtGraphicalEffects 1.0

//This Object is just the AccordionElement with a DropShadow
//NOTE: the only reason this is in an extra file is for testing purposes and can theoretically be moved to the AccordionElement file (if there is enough time this should be moved)

Item {
    id: root
    //forwards the properties to the AccordionElement so that this Object and the AccordionElement can be used in the same Way
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

    //forwards functioncall

    function sleep() {
        element.sleep()
    }
    function home() {
        element.home()
    }
}
