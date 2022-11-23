import QtQuick
import QtQuick.Shapes 1.5
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    property real value: 0
    property real gaugeWidth: 9
    property string outerColor: "lightgrey"
    property string centerColor: "darkblue"
    property string innerColor: "orange"
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
            strokeColor: outerColor
            strokeWidth: 6

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: 134; radiusY: 134
                startAngle: 121
                sweepAngle: (currentSpeed <= 200) ? 4 + currentSpeed * anglePerSpeedRangeA1 : 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRangeA2
            }
        }
        ShapePath {
            fillColor: "transparent"
            strokeColor: centerColor
            strokeWidth: 1

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: 130.5; radiusY: 130.5
                startAngle: 121
                sweepAngle: (currentSpeed <= 200) ? 4 + currentSpeed * anglePerSpeedRangeA1 : 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRangeA2
            }
        }
        ShapePath {
            fillColor: "transparent"
            strokeColor: innerColor
            strokeWidth: 3

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: 128.5; radiusY: 128.5
                startAngle: 121
                sweepAngle: (currentSpeed <= 200) ? 4 + currentSpeed * anglePerSpeedRangeA1 : 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRangeA2
            }
        }
    }

    Tick_Mark
    {
        id: hook
        alpha: (currentSpeed <= 200) ? 121 + 4 + currentSpeed * anglePerSpeedRangeA1 :  121 + 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRangeA2
        length: hookLength
        width1: hookWidth
        radius1: 137
        color1: hookColor
        visible: haveHook

    }
}
