import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Item {
    id: alarm
    anchors.fill: parent
    Rectangle
    {
        Rectangle
        {
            anchors.fill: parent
            color: "transparent"
            border.width: 10
            border.color: "grey"
            radius: 50
        }
        Rectangle
        {
            width: parent.width / 2
            height: 30
            x: parent.width / 4
            color: "#041122"
            Text
            {
                id: alarmText
                text: qsTr("LARM")
                font.pointSize: alarm.width / 25 // gives warning
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: emergencyBrakeButton
            objectName: "emergencyBrake"
            width: (emergencyBrakeButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(emergencyBrakeButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.horizontalCenter
            anchors.margins: 5
            enabled: false

            // onPressed: buttonHandler.emergencyBrakePressed()
            onPressed: buttonHandler.nboPressed()

            Image
            {
                id: emergencyBrakeImage
                objectName: "emergencyBrakeImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: emergencyBrakeImageBlinking
                objectName: "emergencyBrakeImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/redButton.png"
                visible: false
            }

            Text
            {
                id: emergencyBrakeText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("NBÖ")
                font.pointSize: parent.width /8
                color: "White"
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: emergencyBrakeImage
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeImageBlinking
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: emergencyBrakeImageBlinking
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeImage
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                        target: emergencyBrakeButton
                        enabled: true
                    }
                }
            ]
        }

        Button
        {
            id: fireButton
            objectName: "fire"
            width: (fireButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(fireButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.margins: 5
            enabled: false

            onPressed:  buttonHandler.firePressed()

            Image
            {
                id: fireImage
                objectName: "fireImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: fireImageBlinking
                objectName: "fireImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/redButton.png"
                visible: false
            }
            Text
            {
                id: fireText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BRAND")
                font.pointSize: parent.width /8
                color:"White"
            }

            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: fireImage
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: fireImageBlinking
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: fireButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: fireImage
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: fireImageBlinking
                        visible: true
                    }

                    PropertyChanges
                    {
                        target: fireButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                        target: fireButton
                        enabled: true
                    }
                }
            ]
        }
    }
}
