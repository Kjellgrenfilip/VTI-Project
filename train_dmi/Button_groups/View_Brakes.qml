import QtQuick 2.0
import QtQuick.Controls 2.0
import "../Imports" 1.0

Item
{
    id: brakes
    anchors.fill: parent

    //Grey frame around button group
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        border.width: 5
        border.color: MyConst.darkGrey
        radius: 40
    }

    // Text for brakes button group
    Rectangle
    {
        width: parent.width / 2
        height: 30
        x: parent.width / 4
        color: MyConst.backgroundColor
        y: -1

        Text
        {
            id: brake
            text: qsTr("BROMS")
            font.pixelSize: brakes.width / 20 // gives warning
            color: MyConst.white
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.top
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

        // Button for parking brake
        Button
        {

            id: parkButton
            objectName: "parkingBrake"
            width: (parkButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(parkButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            onPressed: buttonHandler.parkBrakePressed()

            Image
            {
                id: parkImage
                anchors.fill: parent
                source: "../desk_ikoner/button69.png"
            }
            Text
            {
                id: parkText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("PARK")
                font.pixelSize: parent.width /8
                color: MyConst.white
            }

            states:
            [
            State
            {
                name: "default";
                PropertyChanges
                {
                    target: parkImage
                    source:"../desk_ikoner/yellow.png"
                }
                PropertyChanges
                {
                    target: parkButton
                    enabled: true
                }
            },
            State
            {
                name: "active";
                PropertyChanges
                {
                    target: parkImage
                    source:"../desk_ikoner/yellow.png"
                }
                PropertyChanges
                {
                    target: parkButton
                    enabled: true
                }
            },
            State
            {
                name: "inactive";
                PropertyChanges
                {
                    target: parkImage
                    source:"../desk_ikoner/button69.png"
                }
                PropertyChanges
                {
                    target: parkButton
                    enabled: true
                }
            }
            ]
        }

        // Button for the brake indicator
        Button
        {
            id: brakeIndicator
            objectName: "brakeIndicator"
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5

            Image
            {
                id: brakeImage
                anchors.fill: parent
                source: "../desk_ikoner/indicator_frame.png"
            }
            Text
            {
                id: brakeTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BROMS")
                font.pixelSize: parent.width /9
                color: MyConst.white
            }
            Text
            {
                id: brakeTextB
                text: qsTr("FRÅN")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: parent.width /9
                color: MyConst.white
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: brakeImage
                        source:"../desk_ikoner/indicator_frame_green.png"
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: brakeImage
                        source:"../desk_ikoner/indicator_frameR.png"
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
                        source:"../desk_ikoner/indicator_frame_green.png"
                    }
                }
            ]
        }

        // Button for the electric brake
        Button
        {
            id: electricityBrake
            objectName: "electricityBrake"
            width: (electricityBrake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(electricityBrake.pressed) ? parent.height / 2 - 10 : parent.height / 2- 5
            enabled: false

            onPressed:  buttonHandler.electricityBrakePressed()
            Image
            {
                id: electricityBrakeImage
                anchors.fill: parent
                source: "../desk_ikoner/button69.png"
            }
            Text
            {
                id: electricityBrakeTextA
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("ELBR")
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            Text
            {
                id: electricityBrakeTextB
                text: qsTr("TILL")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: electricityBrakeImage
                        source:"../desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: electricityBrake
                        enabled: true
                    }
                },
                State
                {                    
                    name: "active";
                    PropertyChanges
                    {
                        target: electricityBrakeImage
                        source:"../desk_ikoner/yellow.png"
                    }
                    PropertyChanges
                    {
                        target: electricityBrakeTextB
                        text: qsTr("FRÅN")
                    }
                    PropertyChanges
                    {
                        target: electricityBrake
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: electricityBrakeImage
                        source:"../desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: electricityBrake
                        enabled: true
                    }
                }
            ]
        }

        // Button for the magnetic brake
        Button
        {
            id: magneticBrake
            objectName: "magneticBrake"
            width: (magneticBrake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(magneticBrake.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            onPressed:  buttonHandler.magneticBrakePressed()
            onReleased:  buttonHandler.magneticBrakeReleased()
            onCanceled:  buttonHandler.magneticBrakeReleased()

            Image
            {
                id: mgImage
                anchors.fill: parent
                source: "../desk_ikoner/button69.png"
            }
            Text
            {
                id: mgText
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("MG")
                font.pixelSize: parent.width /8
                color: MyConst.white
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges {
                        target: mgImage
                        source:"../desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: magneticBrake
                        enabled: true
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges {
                        target: mgImage
                        source:"../desk_ikoner/redButton.png"
                    }
                    PropertyChanges
                    {
                        target: magneticBrake
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges {
                        target: mgImage
                        source:"../desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: magneticBrake
                        enabled: true
                    }
                }
            ]
        }
    }
}
