import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Item
{
    id: brakes
    anchors.fill: parent

    Rectangle       //Grey fram around ButtonGroup
    {
        anchors.fill: parent
        color: "transparent"
        border.width: 10
        border.color: "grey"
        radius: 50
    }

    Rectangle       //Rectangle to hold the text
    {
        width: parent.width / 2
        height: 30
        x: parent.width / 4
        color: MyConst.backgroundColor
        Text
        {
            id: brake
            text: qsTr("BROMS")
            font.pointSize: brakes.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: gridBrakes
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {

            id: parkButton
            objectName: "parkingBrake"
            width: (parkButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(parkButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

            onPressed: buttonHandler.parkBrakeClicked()

            Image
            {
                id: parkImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text
            {
                id: parkText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("PARK")
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
                    target: parkImage
                    source: "desk_ikoner/yellow.png"
                }
                PropertyChanges {
                    target: parkButton
                    enabled: false
                }
            },
            State
            {
                name: "active";
                PropertyChanges
                {
                    target: parkImage
                    source:"desk_ikoner/yellow.png"
                }
            },
            State
            {
                name: "inactive";
                PropertyChanges
                {
                    target: parkImage
                    source:"desk_ikoner/button69.png"
                }
            }
        ]
        }

        Button
        {
            id: brakeIndicator
            objectName: "brake_indicator"
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {
                id: brakeImage
                anchors.fill: parent
                source: "desk_ikoner/indicator_frame_green.png"
            }
            Text
            {
                id: brakeTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BROMS")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text
            {
                id: brakeTextB
                text: qsTr("FRÅN")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                //y:broms.y + 30
                font.pointSize: parent.width /8
                color:"White"
            }
            states:
                [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: brakeImage
                        source:"desk_ikoner/indicator_frameR.png"
                    }
                    PropertyChanges
                    {
                        target: brakeTextB
                        text: qsTr("TILL")
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: brakeImage
                        source:"desk_ikoner/indicator_frame_green.png"
                    }
                }
            ]
        }
        Button
        {
            id: electricityBrake
            objectName: "electricityBrake"
            width: (electricityBrake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(electricityBrake.pressed) ? parent.height / 2 - 10 : parent.height / 2- 5

            onPressed:  buttonHandler.electricityBrakeClicked()
            Image
            {
                id: electricityBrakeImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text
            {
                id: electricityBrakeTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("ELBR")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text
            {
                id: electricityBrakeTextB
                text: qsTr("TILL")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                //y:broms.y + 30
                font.pointSize: parent.width /8
                color:"White"
            }
            states:
                [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: electricityBrakeImage
                        source:"desk_ikoner/yellow.png"
                    }
                    PropertyChanges
                    {
                        target: electricityBrakeTextB
                        text: qsTr("FRÅN")
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: electricityBrakeImage
                        source:"desk_ikoner/button69.png"
                    }
                }
            ]

        }
        Button
        {
            id: magneticBrake
            objectName: "magneticBrake"
            width: (magneticBrake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(magneticBrake.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

            onPressed:  buttonHandler.magneticBrakeClicked()
            onReleased:  buttonHandler.magneticBrakeReleased()
            onCanceled:  buttonHandler.magneticBrakeReleased()

            Image
            {
                id: mgImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text
            {
                id: mgText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("MG")
                font.pointSize: parent.width /8
                color:"White"
            }
            states:
                [
                State
                {
                    name: "active";
                    PropertyChanges {
                        target: mgImage
                        source:"desk_ikoner/redButton.png"
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges {
                        target: mgImage
                        source:"desk_ikoner/button69.png"
                    }
                }
            ]
        }
    }
}
