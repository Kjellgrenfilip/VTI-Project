import QtQuick 2.0
import QtQuick.Controls 2.0

import "Imports" 1.0

//import QtMultimedia


Item {
    id: reverse_horn
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"

        Button
        {
            id: reverse_button
            objectName: "reverse"
            width: (reverse_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(reverse_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            enabled: false

            onPressed: buttonHandler.reversePressed()

            Image
            {
                id: reverse_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: reverse_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BACK")
                font.pointSize: parent.width /8
                color:"White"
            }
            SequentialAnimation {
                id: reverseAnimation
                objectName: "reverse_animation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation {
                    target: reverse_image
                    property: "source"
                    to: "desk_ikoner/yellow.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: reverse_image
                    property: "source"
                    to: "desk_ikoner/button69.png"
                    duration: MyConst.animation_duration
                }
            }
            states: [
                State {
                    name: "default";
                    PropertyChanges {
                        target: reverse_image
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges {
                        target: reverseAnimation
                        running: false
                    }
                    PropertyChanges {
                        target: reverse_button
                        enabled: true
                    }
                },
                State {
                    name: "warning";
                    PropertyChanges {
                        target: reverse_button
                        enabled: true
                    }
                }
            ]

        }
        Button
        {
            id: horn_button
            objectName: "horn"
            width: (horn_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(horn_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            enabled: false

//          onPressed: { buttonHandler.hornPressed(); sound.play() }
            onPressed: { buttonHandler.hornPressed() }

//            SoundEffect {
//                id: sound
//                source: "sounds/S_info.wav"
//            }


            Image
            {
                id: horn_image
                anchors.fill: parent
                source: "desk_ikoner/siren5.png"
            }

            states: [
                State {
                    name: "default";
                    PropertyChanges {
                        target: horn_button
                        enabled: true
                    }
                }
            ]
        }
    }
}


