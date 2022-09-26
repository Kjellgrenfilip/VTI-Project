import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: brakes
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
                id: larm_text
                text: qsTr("LARM")
                font.pointSize: brakes.width / 20 // gives warning
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: nbo_button


            //width: parent.width / 2 - 5
            width: (nbo_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(nbo_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.horizontalCenter
            anchors.margins: 5
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
            id: brand_button
            width: (brand_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(brand_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.margins: 5
            Image
            {
                id: brand_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: brand_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BRAND")
                font.pointSize: parent.width /8
                color:"White"
            }
           }
    }

//    Grid
//    {
//        id: grid_alarm
//        spacing: 10
//        transformOrigin: Item.Center
//        anchors.fill:parent
//        anchors.left: parent.right
//        rows: 1
//        columns: 2
//        anchors.margins: 15

//    }
}
