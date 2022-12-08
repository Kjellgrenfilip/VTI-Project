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

        // The button for front lights
        Button
        {
            id: lightButton
            objectName: "light"
            width: (lightButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(lightButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            enabled: false

            Image
            {
                id: lightImage
                objectName: "lightImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: lightImageBlinking
                objectName: "lightImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/yellow.png"
                visible: false
            }

            Text
            {
                id: lightTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("FRONT")
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            Text
            {
                id: lightTextB
                text: qsTr("LJUS")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            states:
            [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: lightImage
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: lightImageBlinking
                        visible: false
                    }
                    PropertyChanges {
                        target: lightButton
                        enabled:true
                    }
                },
                State {
                    name: "warning"
                    PropertyChanges {
                        target: lightButton
                        enabled: true

                    }
                }
            ]
            onPressed: buttonHandler.lightPressed()
        }

        // The button for emergency call
        Button
        {
            id: emergencyButton
            objectName: "emergencyCall"
            width: (emergencyButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(emergencyButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            enabled: false

            Image
            {
                id: emergencyImage
                objectName: "emergencyCallImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }

            Text
            {
                id: emergencyTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("NÖD")
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            Text
            {
                id: emergencyTextB
                text: qsTr("ANROP")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            states: [
                State {
                    name: "default"
                    PropertyChanges {
                        target: emergencyButton
                        enabled: true
                    }
                    PropertyChanges {
                        target: emergencyImage
                        source: "desk_ikoner/redButton.png"
                    }
                }

            ]
            onPressed: buttonHandler.emergencyPressed()
        }
    }
}

