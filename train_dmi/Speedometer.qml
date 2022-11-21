import QtQuick
import QtQuick.Shapes 1.15

import QtQuick.Controls 2.15
Item
{
    id: speedometer
    property real value : 0
    property real currentSpeed : 65
    property real angleBetweenTickmarks : 9.6
    property real anglePerSpeedRange1 : 192 / 200;
    property real anglePerSpeedRange2 : 96 / 200;
    property real startAngle : 126
    property string needleColor : "lightgrey"
    property real indicationAngle : 180+54+54+5
    property string arcColor : "yellow"
    property string range : "rangeA"
    property bool hookActive: true
    width: 280; height: 300

    antialiasing: true

    // Sets the background color behind the Speedometer!
    Rectangle
    {
        anchors.fill:  parent
        color: "#041122"
    }

    // Creates the Speedometer!
    Rectangle
    {
        id: speedometerNeedle
        width: 250; height: 250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.margins: 20
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
                angle: (currentSpeed <= 200) ? (126-90)+currentSpeed * anglePerSpeedRange1 :  36 + 96 * 2 + (currentSpeed - 200) * anglePerSpeedRange2//(currentSpeed <= 200) ? 121 + 5 + currentSpeed * anglePerSpeedRange1 :  121 + 96 * 2 + 5 + (currentSpeed - 200) * anglePerSpeedRange2
                Behavior on angle
                {
                    SpringAnimation
                    {
                        spring: 1.0
                        damping: 1.0
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
                angle: (currentSpeed <= 200) ? (126-90)+currentSpeed * anglePerSpeedRange1 :  36 + 96 * 2 + (currentSpeed - 200) * anglePerSpeedRange2
                Behavior on angle
                {
                    SpringAnimation
                    {
                        spring: 1.0
                        damping: 1.0
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
                text: qsTr((currentSpeed).toString())
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.bold: true
                font.pointSize: 25
            }
        }
    }
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
            visibility: (index % ((range == "rangeA") ? 5 : 2) == 0) ? true : false // Makes every 5:th tickmark have a speedtext.
            speedValue: index * 10;
            tickMarkNum: index
        }
    }
    //Creates one CircularSpeedGauge.
    CircularSpeedGauge{
        id: gauge1
        objectName: "gauge1"
        haveHook: hookActive
    }
    CircularSpeedGauge{
    gaugeColor: "orange"
    gaugeWidth: 20
    startAngle1: (126+(currentSpeed*anglePerSpeedRange1))+5.5
    rY: 127
    rX: 127
    }
    CircularSpeedGauge{
        id: gauge3
        objectName: "gauge3"
        haveHook: false
    }
    CircularSpeedGauge{
        id: gauge4
        objectName: "gauge4"
        haveHook: false
    }
    CircularSpeedGauge{
        id: gauge5
        objectName: "gauge5"
        haveHook: false
    }
}


