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
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
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

            SequentialAnimation
            {
                id: emergencyBrakeWarningAnimation
                objectName: "emergencyBrakeAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: emergencyBrakeImage
                    property: "source"
                    to: "desk_ikoner/redButton.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: emergencyBrakeImage
                    property: "source"
                    to: "desk_ikoner/button69.png"
                    duration: MyConst.animationDuration
                }
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: emergencyBrakeImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeWarningAnimation
                        running: false
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
                        target: emergencyBrakeImage
                        source:"desk_ikoner/redButton.png"
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeWarningAnimation
                        running: false
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
                        width: (emergencyBrakeButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
                        height:(emergencyBrakeButton.pressed) ? parent.height - 40 : parent.height - 35
                        enabled: true
                    }
                    PropertyChanges
                    {
                        target: emergencyBrakeWarningAnimation
                        running: false
                    }
                }
            ]
        }

        Button
        {
            id: fireButton
            objectName: "fire"
            width: parent.width / 2 - 35
            height: parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.margins: 5
            enabled: false

            onPressed:  buttonHandler.firePressed()

            Image
            {
                id: fireImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
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

            SequentialAnimation
            {
                id: fireWarningAnimation
                objectName: "fireAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: fireImage
                    property: "source"
                    to: "desk_ikoner/redButton.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: fireImage
                    property: "source"
                    to: "desk_ikoner/button69.png"
                    duration: MyConst.animationDuration
                }
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: fireImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: fireWarningAnimation
                        running: false
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
                        source:"desk_ikoner/redButton.png"
                    }

                    PropertyChanges
                    {
                        target: fireWarningAnimation
                        running: false
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
                        width: (fireButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
                        height:(fireButton.pressed) ? parent.height - 40 : parent.height - 35
                        enabled: true
                    }
                    PropertyChanges
                    {
                        target: fireWarningAnimation
                        running: false
                    }
                }
            ]
        }
    }
}
