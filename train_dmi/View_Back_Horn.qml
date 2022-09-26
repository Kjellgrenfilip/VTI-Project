import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: back_horn
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"

        Button
        {
            id: back_button
            width: (back_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(back_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Image
            {
                id: back_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: back_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BACK")
                font.pointSize: parent.width /8
                color:"White"
            }

        }
        Button
        {

            id: horn_button
            width: (horn_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(horn_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Image
            {
                id: horn_image
                anchors.fill: parent
                source: "desk_ikoner/siren5.png"
            }
           }
    }

//    Grid
//    {
//        id: grid_back_horn
//        spacing: 10
//        transformOrigin: Item.Center
//        anchors.fill:parent
//        anchors.left: parent.right
//        rows: 1
//        columns: 2
//        anchors.margins: 30

//    }
}


