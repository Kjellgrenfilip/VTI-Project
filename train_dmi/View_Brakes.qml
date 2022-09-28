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
            id: name
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
            width: (park_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(park_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

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
                name: "off"; when:park_button.pressed
                PropertyChanges {
                    target: park_image
                    source:"desk_ikoner/button69.png"
                }
            }
        ]
        }

        Button
        {
            id: broms_button
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {
                id: broms_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
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
        }
        Button
        {
            id: elbr_button
            width: (elbr_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(elbr_button.pressed) ? parent.height / 2 - 10 : parent.height / 2- 5
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
                    name: "on"; when:elbr_button.pressed
                    PropertyChanges {
                        target: park_image
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
                        target: park_image
                        source:"desk_ikoner/button69.png"
                    }
                }
            ]

        }
        Button
        {
            id: mg_button
            width: (mg_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(mg_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
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
        }
        states: [
            State {
                name: "on"; when:mg_button.pressed
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
