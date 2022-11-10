import QtQuick

Item {
    id: root
    property real value : 0

    width: 250; height: 250

    Rectangle
    {
        anchors.fill:  parent
        color: "white"
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

//        Repeater {
//            id: tickMarkCreator
//            model: 3
//            Tick_Mark {
//                //id: tickMark1
//                alpha: (144 + (tickMarkCreator.index * 9.6))
//            }
//        }

        Tick_Mark {
            id: tickMark1
            alpha: (144)
        }
        Tick_Mark {
            id: tickMark2
            alpha: (144 + 9.6)
        }


    }
}


