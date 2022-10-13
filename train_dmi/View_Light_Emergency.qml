import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0
Item {
    id: lightEmergency
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: lightButton
            width: (lightButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(lightButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            Image
            {
                id: lightImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text
            {
                id: lightTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("FRONT")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text
            {
                id: lightTextB
                text: qsTr("LJUS")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: parent.width /8
                color:"White"
            }
            states:
            [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: lightImage
                        souce: "desk_ikoner/button69.png"
                    }
                    PropertyChanges {
                        target: lightWarningAnimation
                        running: false

                    }
                },
                State {
                    name: "warning"
//                    PropertyChanges {
//                        target: object

//                    }
                }
            ]
            SequentialAnimation
            {
                id: lightWarningAnimation
                objectName: "lightWarningAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: lightImage
                    property: "source"
                    to: "desk_ikoner/yellow.png"
                    duration: MyConst.animationDuration
                }
                PropertyAnimation
                {
                    target: lightImage
                    property: "source"
                    to: "desk_ikoner/button69.png"
                    duration: MyConst.animationDuration
                }
            }
            onPressed: buttonHandler.lightPressed()
        }
        Button
        {
            id: emergencyButton
            width: (emergencyButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(emergencyButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            Image
            {
                id: emergencyImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text
            {
                id: emergencyTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("NÖD")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text
            {
                id: emergencyTextB
                text: qsTr("ANROP")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: parent.width /8
                color:"White"
            }
        }
    }
}

