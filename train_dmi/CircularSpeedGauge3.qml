import QtQuick
import QtQuick.Shapes 1.5
import QtQuick.Controls 2.0

Item {
    id: threeLayerCSG
    anchors.fill: parent

    property real value: 0
    property real gaugeWidth: 9
    property real hookWidth: 6
    property real hookLength: 20
    property bool haveHook: true
    property real startAngle1: 121
    property real rX: 132.5
    property real rY: 132.5


    function calcAngle()
    {
        return (value <= 200) ? 5 + value * anglePerSpeedRangeA1 - 2.5 : 96 * 2 + 5 + (value - 200) * anglePerSpeedRangeA2 - 2.5
    }

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
                centerX: 140; centerY: 135
                radiusX: 134; radiusY: 134
                startAngle: 121
                sweepAngle: threeLayerCSG.calcAngle()+1
            }
        }
        ShapePath {
            fillColor: "transparent"
            strokeColor: centerColor
            strokeWidth: 1

            PathAngleArc {
                centerX: 140; centerY: 135
                radiusX: 130.5; radiusY: 130.5
                startAngle: 121 - ((360/(130.5*2*Math.PI))*2)
                sweepAngle: threeLayerCSG.calcAngle() +2*((360/(130.5*2*Math.PI))*2)

            }
        }///2,31 pixlar/grad     0,432 grader/pixlar.   0.432*1,5 = 0.648
        ShapePath {
            fillColor: "transparent"
            strokeColor: innerColor
            strokeWidth: 3

            PathAngleArc {
                centerX: 140; centerY: 135
                radiusX: 128.5; radiusY: 128.5

                startAngle: 121 - ((360/(128.5*2*Math.PI))*1.5)
                sweepAngle: threeLayerCSG.calcAngle() + 2*((360/(128.5*2*Math.PI))*1.5) +1

            }
        }
    }

    Tick_Mark
    {
        id: normalHook
        alpha: threeLayerCSG.calcAngle()+121
        length: hookLength
        tickWidth: hookWidth
        placementRadius: 137
        tickmarkColor: outerColor
        visible: speedHook

    }
   Tick_Mark
    {
        id: smallHook
        alpha: threeLayerCSG.calcAngle()+121
        length: 14
        tickWidth: 6
        placementRadius: 130
        tickmarkColor: innerColor
        visible: smallSpeedHook

    }
}
