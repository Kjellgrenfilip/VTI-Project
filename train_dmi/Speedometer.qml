import QtQuick
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.0

Item {
    id: speedometer
    property real value : 0
    property real currentSpeed : 200
    property real currentAngle : 0
    property real angleBetweenTickmarks : 9.6
    property real startAngle : 126
    property string needleColor : "lightgrey"
    property real indicationAngle : 180+54+54
    property string arcColor : "yellow"
    property string range : "rangeD"

    width: 280; height: 300

    // Sets the background color behind the Speedometer!
    Rectangle
    {
        anchors.fill:  parent
        color: "#041122"
    }

    // Creates the arc around the Speedometer
    Shape {
        width: 280; height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top

        ShapePath {
            fillColor: "transparent"
            strokeColor: arcColor
            strokeWidth: 9

            PathAngleArc {
                centerX: parent.width/2; centerY: parent.height/2 - 5
                radiusX: 132.5; radiusY: 132.5
                startAngle: 126
                sweepAngle: indicationAngle
            }
        }
    }

    // Creates the Speedometer!
    Rectangle{
        id: speedometerNeedle
        width: 250; height: 250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.margins: 20
        color: "#041122"
        radius:  125

        // Creates the thick part of the needle!
        Rectangle {
            id: needleThick
            x: (parent.width/2) - width/2
            y: parent.height/2
            antialiasing: true
            width: 9
            height: 82
            color: needleColor
            transform: Rotation {
                origin.x: 4.5; origin.y: 0
                //Min = 54, Max = 306
                // Map the angle between min/max angle values and the speed min/max values
                angle: Math.min(Math.max(36, speedometer.value*2.6 + 36), 324)
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.0
                        damping: 1.0
                    }
                }
            }
        }
        // Creates the thin part of the needle
        Rectangle {
            id: needleThin
            x: (parent.width/2) - width/2
            y: parent.height/2
            antialiasing: true
            width: 3
            height: 105
            color: needleColor
            transform: Rotation {
                origin.x: 4.5; origin.y: 0
                //Min = 54, Max = 306
                // Map the angle between min/max angle values and the speed min/max values
                angle: Math.min(Math.max(36, speedometer.value*2.6 + 36), 324)
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.0
                        damping: 1.0
                    }
                }
            }
        }

        // Creates the inner circle of the speedometer arrow!
        Rectangle{
            height:50
            width:50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            radius: 25
            color: needleColor
            // Creates the text that show the speed
            Text {
                id: speedText
                text: qsTr(currentSpeed.toString())
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                font.bold: true
                font.pointSize: 25
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
        Repeater {
            id: tickmarkCreator
            model: speedometerNeedle.numOfTickmarks()
            Tick_Mark {
                alpha: (range == "rangeA") ?
                           (startAngle + speedometerNeedle.calculateAngle(index)) :
                           (startAngle + (index * speedometerNeedle.tickMarkAngle()))

                length: (index % ((range == "rangeA") ? 5 : 2) == 0) ? 25 : 15 // Makes every 5:th tickmark long.
                visibility: (index % ((range == "rangeA") ? 5 : 2) == 0) ? true : false // Makes every 5:th tickmark have a speedtext.
                speedValue: index * 10;
                tickMarkNum: index
            }
        }
    }
}


