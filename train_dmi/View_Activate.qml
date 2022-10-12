import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Item
{
    id: activate
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: activateButton
            objectName: "activate"
            width: (activateButton.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(activateButton.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.left: parent.left
            padding: 0
            background: Rectangle
            {
                anchors.fill: parent
                color: MyConst.backgroundColor
            }

            Image
            {
                id: activateImage
                anchors.fill: parent
                source: "desk_ikoner/power_green2.png"
            }

            onPressed: buttonHandler.activatePressed()

            SequentialAnimation
            {
                id: activateAnimation
                objectName: "activateAnimation"
                running: true
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: activateImage
                    property: "source"
                    to: "desk_ikoner/power_green2.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: activateImage
                    property: "source"
                    to: "desk_ikoner/power2.png"
                    duration: MyConst.animationDuration
                }
            }
            states: [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: activateImage
                        source:"desk_ikoner/power_green2.png"
                    }
                    PropertyChanges
                    {
                        target: activateAnimation
                        running: false
                    }
                }
            ]
        }

        Button
        {
            id: protectionButton
            objectName: "protection"
            width: (protectionButton.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(protectionButton.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false

            background: Rectangle
            {
                anchors.fill: parent
                color: MyConst.backgroundColor
            }

            Image
            {
                id: protectionImage
                anchors.fill: parent
                source: "desk_ikoner/power2.png"
            }
            SequentialAnimation
            {
                id: protectionAnimation
                objectName: "protectionAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: protectionImage
                    property: "source"
                    to: "desk_ikoner/power_green2.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: protectionImage
                    property: "source"
                    to: "desk_ikoner/power2.png"
                    duration: MyConst.animationDuration
                }
            }

            states:
             [
                State
                {
                    name: "blinking";
                    PropertyChanges
                    {
                        target: protectionAnimation
                        running: false
                    }
                    PropertyChanges
                    {
                        target: protectionButton
                        enabled: true
                    }
                }
            ]
        }

        Button
        {
            id: cartButton
            objectName: "cart"
            width: (cartButton.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(cartButton.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.right: parent.right
            enabled: true
            background: Rectangle
            {
                anchors.fill: parent
                color: MyConst.backgroundColor
            }
            Image
            {
                id: cartImage
                anchors.fill: parent
                source: "desk_ikoner/power_green2.png"
            }

            states:
                [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: cartButton
                        enabled: true
                    }
                    PropertyChanges
                    {
                        target: cartImage
                        source: "desk_ikoner/power_green2.png"
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: cartButton
                        enabled: false
                    }
                    PropertyChanges
                    {
                        target: cartImage
                        source: "desk_ikoner/power2.png"
                    }
                }
            ]
        }

        TextArea
        {
            id: activateText
            width: parent.width/9
            anchors.horizontalCenter: activateButton.horizontalCenter
            anchors.bottom:parent.bottom
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("AKTIVERING")
                font.pointSize: parent.width/3
                color: "White"
            }
        }

        TextArea
        {
            id: protectionText
            width: parent.width/9
            anchors.bottom:parent.bottom
            anchors.horizontalCenter: protectionButton.horizontalCenter
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("TÅGSKYDD")
                font.pointSize: parent.width/3
                color:"White"
            }
        }

        TextArea
        {
            id: cartText
            anchors.bottom:parent.bottom
            anchors.horizontalCenter: cartButton.horizontalCenter
            width: parent.width/9
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BYT HYTT")
                font.pointSize: parent.width/3
                color:"White"
            }
        }
    }
}
