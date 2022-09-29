import QtQuick 2.0
import QtQuick.Controls 2.0

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
                id: alarm_text
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
            id: nbo_button
            objectName: "emergency_brake"
            width: (nbo_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(nbo_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.horizontalCenter
            anchors.margins: 5

            onClicked: buttonHandler.nboClicked()

            Image
            {
                id: nbo_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: nbo_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("NBÖ")
                font.pointSize: parent.width /8
                color: "White"
            }
        }
        Button
        {
            id: fire_button
            objectName: "fire"
            width: (fire_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(fire_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.margins: 5

            onClicked: buttonHandler.fireClicked()

            Image
            {
                id: fire_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: fire_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BRAND")
                font.pointSize: parent.width /8
                color:"White"
            }
            states: [
                State {
                    name: "active";
                    PropertyChanges {
                        target: fire_image
                        source:"desk_ikoner/redButton.png"
                    }
                },
                State {
                    name: "inactive";
                    PropertyChanges {
                        target: fire_image
                        source:"desk_ikoner/button69.png"
                    }
                },
                State {
                    name: "warning";
                    PropertyChanges {
                        target: fire_image
                        source:"desk_ikoner/yellow.png"
                    }
                }
            ]
        }
    }
}
