import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: light_emergency
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: light_button
            width: (light_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(light_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            Image
            {
                id: light_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: light_text_a
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("FRONT")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text {
                id: light_text_b
                text: qsTr("LJUS")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: parent.width /8
                color:"White"
            }
        }
        Button
        {
            id: emergency_button
            width: (emergency_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(emergency_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 5
            Image
            {
                id: emergency_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: emergency_text_a
                anchors.bottom: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("NÖD")
                font.pointSize: parent.width /8
                color:"White"
            }
            Text {
                id: emergency_text_b
                text: qsTr("ANROP")
                anchors.top: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: parent.width /8
                color:"White"
            }
           }
    }

}

