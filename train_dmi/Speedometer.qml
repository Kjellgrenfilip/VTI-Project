import QtQuick

Item {
    id: root
    property real value : 0

    width: 250; height: 250

    Rectangle
    {
        anchors.fill:  parent
        color: "#041122"
    }

    Rectangle{
        anchors.fill:  parent
        color: "#041122"
        radius:  125

        Rectangle {
            id: needle
            x: (parent.width/2) - width/2
            y: parent.height/2

            antialiasing: true
            //source: "needle.png"
            width: 9
            height: 80
            color: "lightgrey"
            transform: Rotation {
                id: needleRotation
                origin.x: 4.5; origin.y: 0
                //! [needle angle]
                //Min = 54, Max = 306
                angle: Math.min(Math.max(54, root.value*2.6 +54), 306)
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.0
                        damping: 1.0
                    }
                }
                //! [needle angle]
            }
        }
        Rectangle{
            height:50
            width:50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            radius: 25
            color: "lightgrey"
        }

        Rectangle {
            height: 10
            width: 10
            radius: 5
            color: "orange"

            x: 125 * Math.cos(0) + 115
            y: 125 * Math.sin(0) + 120
        }
        Rectangle {
            height: 10
            width: 10
            radius: 5
            color: "blue"

            x: 125 * Math.cos(Math.PI/2) + 120
            y: 125 * Math.sin(Math.PI/2) + 115
        }
        Rectangle {
            height: 10
            width: 10
            radius: 5
            color: "red"

            x: 125 * Math.cos(Math.PI) + 125
            y: 125 * Math.sin(Math.PI) + 120
        }
        Rectangle {
            height: 10
            width: 10
            radius: 5
            color: "white"

            x: 125 * Math.cos(3*Math.PI/2) + 120
            y: 125 * Math.sin(3*Math.PI/2) + 125
        }
    }
}


