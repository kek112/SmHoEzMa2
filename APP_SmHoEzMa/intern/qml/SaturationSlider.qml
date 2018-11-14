import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Item {

    RowLayout {
        anchors.fill: parent
        Label {
            text: "Saturation"
        }
        Slider {
            id: slider
            from: 1
            value: 25
            to: 100
        }
    }
    function setValue(_value) {
        slider.value = _value
    }
    function getValue() {
        return slider.value
    }
}
