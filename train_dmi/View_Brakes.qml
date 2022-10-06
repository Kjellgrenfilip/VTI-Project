import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
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
        color: "#041122"
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
        id: grid_brakes
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {

            id: park_button
            objectName: "parking_brake"
            width: (park_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(park_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

            onPressed: buttonHandler.parkBrakeClicked()

            Image
            {
                id: park_image
                anchors.fill: parent
                source: "desk_ikoner/yellow.png"
            }
            Text {
                id: park_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("PARK")
                font.pointSize: parent.width /8
                color: "White"

            }

        states: [
            State {
                name: "on";
                PropertyChanges {
                    target: park_image
                    source:"desk_ikoner/yellow.png"
                }
            },
            State {
                name: "off";
                PropertyChanges {
                    target: park_image
                    source:"desk_ikoner/button69.png"
                }
            }
        ]
        }

        Button
        {
            id: brake_indicator
            objectName: "brake_indicator"
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {
                id: broms_image
                anchors.fill: parent
                source: "desk_ikoner/indicator_frame_green.png"
            }
            Text {
                id: broms_text_a
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BROMS")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text {
                id: broms_text_b
                text: qsTr("FRÅN")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                //y:broms.y + 30
                font.pointSize: parent.width /8
                color:"White"
            }
            states: [
                State {
                    name: "on";
                    PropertyChanges {
                        target: broms_image
                        source:"desk_ikoner/indicator_frameR.png"
                    }
                    PropertyChanges {
                        target: broms_text_b
                        text: qsTr("TILL")
                    }
                },
                State {
                    name: "off";
                    PropertyChanges {
                        target: broms_image
                        source:"desk_ikoner/indicator_frame_green.png"
                    }
                }
            ]
        }
        Button
        {
            id: electricity_brake
            objectName: "electricity_brake"
            width: (electricity_brake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(electricity_brake.pressed) ? parent.height / 2 - 10 : parent.height / 2- 5

            onPressed:  buttonHandler.electricityBrakeClicked()
            Image
            {
                id: elbr_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: elbr_text_a
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("ELBR")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text {
                id: elbr_text_b
                text: qsTr("TILL")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                //y:broms.y + 30
                font.pointSize: parent.width /8
                color:"White"
            }
            states: [
                State {
                    name: "on";
                    PropertyChanges {
                        target: elbr_image
                        source:"desk_ikoner/yellow.png"
                    }
                    PropertyChanges {
                        target: elbr_text_b
                        text: qsTr("FRÅN")
                    }
                },
                State {
                    name: "off";
                    PropertyChanges {
                        target: elbr_image
                        source:"desk_ikoner/button69.png"
                    }
                }
            ]

        }
        Button
        {
            id: magnetic_brake
            objectName: "magnetic_brake"
            width: (magnetic_brake.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(magnetic_brake.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

            onPressed:  buttonHandler.magneticBrakeClicked()
            onReleased:  buttonHandler.magneticBrakeReleased()
            onCanceled:  buttonHandler.magneticBrakeReleased()

            Image
            {
                id: mg_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: mg_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("MG")
                font.pointSize: parent.width /8
                color:"White"
            }
            states: [
                State {
                    name: "on";
                    PropertyChanges {
                        target: mg_image
                        source:"desk_ikoner/redButton.png"
                    }
                },
                State {
                    name: "off";
                    PropertyChanges {
                        target: mg_image
                        source:"desk_ikoner/button69.png"
                    }
                }
            ]
        }
    }
}
