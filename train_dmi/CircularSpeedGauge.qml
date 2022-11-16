import QtQuick
import QtQuick.Shapes 1.5
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    property real value: 0
    property real gaugeWidth: 0
    property string gaugeColor: "lightgrey"
    property string hookColor: "lightgrey"
    property real hookWidth: 0
    property real hookLength: 0


    Shape {
        width: 280; height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        antialiasing: true

        ShapePath {
            fillColor: "transparent"
            strokeColor: (value <= 50) ? gaugeColor : "orange"
            strokeWidth: 9

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: 132.5; radiusY: 132.5
                startAngle: 121
                sweepAngle: (currentSpeed <= 200) ? 5 + currentSpeed * anglePerSpeedRange1 : 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
            }
        }
    }

    Tick_Mark
    {
        id: hook
        alpha: (currentSpeed <= 200) ? 121 + 5 + currentSpeed * anglePerSpeedRange1 :  121 + 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
        length: 20
        width1: 6
        radius1: 137
        color1: hookColor
        visible: (currentSpeed >= 50) ? true : false
    }
}
