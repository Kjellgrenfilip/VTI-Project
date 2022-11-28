import QtQuick
import QtQuick.Shapes 1.5
import QtQuick.Controls 2.0

import "Imports" 1.0

Item {
    id: circularGauge
    anchors.fill: parent

    property real value: 0
    property real gaugeWidth: 9
    property string gaugeColor: MyConst.darkGrey
    property string hookColor: "grey"
    property real hookWidth: 6
    property real hookLength: 20
    property bool haveHook: true
    property real startAngle1: 121
    property real rX: 132.5
    property real rY: 132.5
    property string type: "normal"  //Property to separate the thic and normal CSG's
    property real sweepDistance: 0

    function calcAngle()
    {

        return (value <= 200) ? 5 + value * anglePerSpeedRangeA1 - 2.5 : 96 * 2 + 5 + (value - 200) * anglePerSpeedRangeA2 - 2.5
    }

    function calcThicAngle()
    {
        //Creates the value of which how far the thic CSG has moved since the Vperm-hook.
        if(currentSpeed == 200)
        {
            sweepDistance = 5 + value * anglePerSpeedRangeA1
        }
        return (currentSpeed <= 200) ? 5 + value * anglePerSpeedRangeA1 - 2.5 : sweepDistance + (currentSpeed-200) * anglePerSpeedRangeA2 - 2.5
    }
    Shape
    {
        width: 280; height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        antialiasing: true

        ShapePath
        {
            fillColor: "transparent"
            strokeColor: gaugeColor
            strokeWidth: gaugeWidth

            PathAngleArc
            {
                centerX: 140; centerY: 135
                radiusX: rX; radiusY: rY
                startAngle: startAngle1
                sweepAngle: (type == "normal") ? circularGauge.calcAngle() : circularGauge.calcThicAngle() //currentSpeed-permittedspeed
            }
        }
    }

}
