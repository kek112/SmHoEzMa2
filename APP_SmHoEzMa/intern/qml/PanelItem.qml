import QtQuick 2.0;
import QtQuick.Controls 2.4;
Slider {
    id: control;
    Image{
        source: "qrc:/ColorSpectrum";
        x: control.leftPadding*2;
        anchors.verticalCenter: parent.verticalCenter;
        height: control.handle.height/2;
        width: control.width - control.leftPadding*2 - control.rightPadding*2
    }
}
