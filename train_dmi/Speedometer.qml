import QtQuick
import QtQuick.Shapes 1.15

import QtQuick.Controls 2.15

import "Imports" 1.0
Item
{
    id: speedometer
    objectName: "speedometer"
    property real angleBetweenTickmarks : 9.6
    property real anglePerSpeedRangeA1 : 192 / 200;
    property real anglePerSpeedRangeA2 : 96 / 200;
    property real startAngle : 126
    property string needleColor : "lightgrey"
    property string range : "rangeA"
    //Properties that controls the if the Hooks are visible
    property bool targetHook: false
    property bool permittedHook: false
    property bool speedHook: false
    property bool smallSpeedHook: false

    property bool csgTopLayerHook: false
    property bool csgMiddleLayerHook: false

    //Speed Related Properties
    property real currentSpeed: 20
    property real permittedSpeed: 50
    property real targetSpeed: 60
    property real advisorySpeed: 0
    property real interventionSpeed: 0
    //properties related to the threeLayer CSG
    property string innerColor: MyConst.darkGrey
    property string centerColor: MyConst.darkGrey
    property string outerColor: MyConst.darkGrey

    property string topColor: MyConst.darkGrey
    property string thicColor: MyConst.darkGrey
    property string bottomColor: MyConst.darkGrey

    property real csgBottomLayerValue: 0
    property real csgMiddleLayerValue: 0
    property real csgTopLayerValue: 0
    property real csgThicLayerValue: 0
    //Properties related to visibility of different CSG's
    property bool bottomCSG: false
    property bool middleCSG: false
    property bool topCSG: false
    property bool thicCSG: false

    property string supervisionMode: ""

    width: 280; height: 300

    antialiasing: true

    // Sets the background color behind the Speedometer!
//    Rectangle
//    {
//        anchors.fill:  parent
//        color: "blue"
//    }

    // Creates the Speedometer!
    Rectangle
    {
        id: speedometerNeedle
        width: 250; height: 250
        //anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.margins: 10

        color: "#041122"
        radius:  125

        // Creates the thick part of the needle!
        Rectangle
        {
            id: needleThick
            x: (parent.width/2) - width/2
            y: parent.height/2
            antialiasing: true
            width: 9
            height: 82
            color: needleColor
            transform: Rotation
            {
                origin.x: 4.5; origin.y: 0
                //Min = 54, Max = 306
                // Map the angle between min/max angle values and the speed min/max values
                angle: (currentSpeed <= 200) ? (126-90)+currentSpeed * anglePerSpeedRangeA1 :  36 + 96 * 2 + (currentSpeed - 200) * anglePerSpeedRangeA2//(currentSpeed <= 200) ? 121 + 5 + currentSpeed * anglePerSpeedRange1 :  121 + 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
                Behavior on angle
                {
                    SmoothedAnimation
                    {
                        velocity: 50
                    }
                }
            }
        }
        // Creates the thin part of the needle
        Rectangle
        {
            id: needleThin
            x: (parent.width/2) - width/2
            y: parent.height/2
            antialiasing: true
            width: 3
            height: 105
            color: needleColor
            transform: Rotation
            {
                origin.x: 1.5; origin.y: 0
                //Min = 54, Max = 306
                //Map the angle between min/max angle values and the speed min/max values
                angle: (currentSpeed <= 200) ? (126-90)+currentSpeed * anglePerSpeedRangeA1 :  36 + 96 * 2 + (currentSpeed - 200) * anglePerSpeedRangeA2
                Behavior on angle
                {
                    SmoothedAnimation
                    {
                        velocity: 50
                    }
                }
            }
        }

        // Creates the inner circle of the speedometer arrow!
        Rectangle
        {
            height:50
            width:50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            radius: 25
            color: needleColor
            // Creates the text that show the speed
            Text
            {
                id: speedText
                text: qsTr(currentSpeed.toString())
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.margins: 2
                color: "black"
                font.bold: true
                font.pointSize: 25
            }
        }
    }
    //Calculates the sweepangles for the CSG's
    function calcCSGAngle(speed)
    {
        return (speed <= 200) ? 5 + speed * anglePerSpeedRangeA1 -4.18: 96 * 2 + 5 + (speed - 200) * anglePerSpeedRangeA2-4.18
    }
    //Calculates the angle for the TickMarks, angle to point to center. Used for RangeA mode
    function calculateAngle(index)
    {
        var angle = 0;
        for (var i = 0; i < index; i++)
        {
            if( i * 10 >= 200 )
                angle = angle + 4.8;
            else
                angle = angle + 9.6;
        }
        return angle;
    }

//Function that returns the number of tickmarks for different modes and speedometer scales.
    function numOfTickmarks()
    {
        if (range == "rangeA")
            return 41;
        if (range == "rangeB")
            return 26;
        if (range == "rangeC")
            return 19;
        if (range == "rangeD")
            return 15;
    }

    //returns the values of the angle between tickmarks in different modes.
    function tickMarkAngle()
    {
        if (range == "rangeB")
            return 11.5;
        if (range == "rangeC")
            return 15.95;
        if (range == "rangeD")
            return 20.5;
    }

    // Creates the tickmarks!
    Repeater
    {
        id: tickmarkCreator
        model: speedometer.numOfTickmarks()
        Tick_Mark
        {
            alpha: (range == "rangeA") ?
                       (startAngle + speedometer.calculateAngle(index)) :
                       (startAngle + (index * speedometer.tickMarkAngle()))

            length: (index % ((range == "rangeA") ? 5 : 2) == 0) ? 25 : 15 // Makes every 5:th tickmark long.
            visibility: (index % ((range == "rangeA") ? ((index >= 20) ? 10 : 5) : 2) == 0) ? true : false // Makes every 5:th tickmark have a speedtext.
            speedValue: index * 10;
            tickMarkNum: index
        }
    }
    //Creates the "thic" CircularSpeedGauge.
    CircularSpeedGauge
    {
        id: csgThic
        objectName: "sgThicLayer"
        gaugeWidth: 20
        visible: thicCSG
        value: ((csgThicLayerValue - 11) <= 0) ? 0 : csgThicLayerValue - 11
        gaugeColor: thicColor
        startAngle1: speedometer.calcCSGAngle(permittedSpeed) + 126 + 3
        rX: 127
        rY:127
        type: "thic"
    }
    //Creates the normal CircularSpeedGauge.
        CircularSpeedGauge
        {
            id: csgTop
            objectName: "csgTopLayer"
            visible: topCSG
            value: csgTopLayerValue
            gaugeColor: topColor
            Tick_Mark
            {
                alpha: 121+speedometer.calcCSGAngle(csgTopLayerValue) + 1.68
                length: 20
                tickWidth: 6
                placementRadius: 137
                tickmarkColor: topColor
                visible: csgTopLayerHook
            }
        }
    //Creates the three-layered CircularSpeedGauge.
    CircularSpeedGauge3
    {
        id: csgMiddle
        objectName: "csgMiddleLayer"
        //haveHook: speedHook
        visible: middleCSG
        value: csgMiddleLayerValue
        Tick_Mark
        {
            alpha: 121+speedometer.calcCSGAngle(csgMiddleLayerValue) + 1.68
            length: 14
            tickWidth: 6
            placementRadius: 130
            tickmarkColor: innerColor
            visible: csgMiddleLayerHook
        }
    }

//Creates the bottom darkgrey CircularSpeedGauge.
    CircularSpeedGauge
    {
        id: csgBottom
        objectName: "csgBottomLayer"
        visible: bottomCSG
        value: csgBottomLayerValue
        gaugeColor: bottomColor
    }

    Tick_Mark
    {
        id: vTargetHook
        visible: targetHook
        length: 20
        tickWidth:10
        alpha: 121+speedometer.calcCSGAngle(targetSpeed)
        placementRadius: 137
    }

    Tick_Mark
    {
        id: vPermHook
        visible: permittedHook
        length: 20
        tickWidth:10
        alpha: 121+speedometer.calcCSGAngle(permittedSpeed)
        placementRadius: 137
    }

}
