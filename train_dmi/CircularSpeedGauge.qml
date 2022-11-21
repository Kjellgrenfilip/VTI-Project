import QtQuick
import QtQuick.Shapes 1.5
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    property real value: 0
    property real gaugeWidth: 9
    property string gaugeColor: "lightgrey"
    property string hookColor: "lightgrey"
    property real hookWidth: 6
    property real hookLength: 20
    property bool haveHook: true
    property real startAngle1: 121
    property real rX: 132.5
    property real rY: 132.5

    Shape {
        width: 280; height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        antialiasing: true

        ShapePath {
            fillColor: "transparent"
            strokeColor: (value <= 50) ? gaugeColor : "orange"
            strokeWidth: gaugeWidth

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: rX; radiusY: rY
                startAngle: startAngle1
                sweepAngle: (currentSpeed <= 200) ? 4 + currentSpeed * anglePerSpeedRange1 : 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
            }
        }
    }

    Tick_Mark
    {
        id: hook
        alpha: (currentSpeed <= 200) ? 121 + 4 + currentSpeed * anglePerSpeedRange1 :  121 + 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
        length: hookLength
        width1: hookWidth
        radius1: 137
        color1: hookColor
        visible: haveHook

    }
}
