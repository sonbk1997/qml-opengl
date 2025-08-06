import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import Custom 1.0

Window {
    id: root
    width: 800
    height: 480
    visible: true
    color: "black"

    GuidelineOverlay {
        id: guideline
        anchors.fill: parent
        z: 1
        steeringAngle: slider.value
    }

    Rectangle {
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom
        color: "#333"

        Slider {
            id: slider
            anchors.centerIn: parent
            from: -10
            to: 10
            width: parent.width * 0.8
            value: 0
        }
    }
}
