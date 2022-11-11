import QtQuick
import QtCharts 2.15

Item {
    id: root
    property real value : 0
    property real currentSpeed : 200
    property real angleBetweenTickmarks : 9.7
    property real startAngle : 144

    width: 270; height: 270

    // Sets the background color behind the Speedometer!
    Rectangle
    {
        anchors.fill:  parent
        color: "#041122"
    }

    // Somehow create a arc around the Speedometer
//    Rectangle {
//        anchors.fill: parent
//        color: "yellow"
//        radius: parent.width / 2
//    }

    // Creates the Speedometer!
    Rectangle{
        width: 250; height: 250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "#041122"
        radius:  125

        // Creates the needle!
        Rectangle {
            id: needle
            x: (parent.width/2) - width/2
            y: parent.height/2
            antialiasing: true
            width: 9
            height: 80
            color: "lightgrey"
            transform: Rotation {
                id: needleRotation
                origin.x: 4.5; origin.y: 0
                //Min = 54, Max = 306
                // Map the angle between min/max angle values and the speed min/max values
                angle: Math.min(Math.max(54, root.value*2.6 +54), 306)
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.0
                        damping: 1.0
                    }
                }
            }
        }

        // Creates the inner circle of the speedometer!
        Rectangle{
            height:50
            width:50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            radius: 25
            color: "lightgrey"
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

        // Creates the tickmarks!
        Repeater {
            id: tickmarkCreator
            model: 27
            Tick_Mark {
                alpha: (startAngle + (index * angleBetweenTickmarks))
                length: (index % 5 == 0) ? 25 : 15 // Makes every 5:th tickmark long.
            }
        }
    }
}


