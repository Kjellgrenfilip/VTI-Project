import QtQuick 2.0
import QtQuick.Controls 2.0

import "Imports" 1.0

import QtMultimedia

Item
{
    id: reverseHorn
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"

        Button
        {
            id: reverseButton
            objectName: "reverse"
            width: (reverseButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(reverseButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            enabled: false

            onPressed: buttonHandler.reversePressed()

            Image
            {
                id: reverseImage
                objectName: "reverseImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: reverseImageBlinking
                objectName: "reverseImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/yellow.png"
                visible: false
            }
            Text
            {
                id: reverseText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BACK")
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
                        target: reverseImage
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: reverseImageBlinking
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: reverseButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                        target: reverseButton
                        enabled: true
                    }
                }
                ]
        }
        Button
        {
            id: hornButton
            objectName: "horn"
            width: (hornButton.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(hornButton.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            enabled: false

            onPressed: { buttonHandler.hornPressed(); sound.play() }

            SoundEffect
            {
                id: sound
                source: "sounds/mlg-airhorn.wav"
            }

            Image
            {
                id: hornImage
                anchors.fill: parent
                source: "desk_ikoner/siren5.png"
            }

            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: hornButton
                        enabled: true
                    }
                }
                ]
        }
    }
}


