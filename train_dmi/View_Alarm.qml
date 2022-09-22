import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: brakes
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "black"
    }
    Rectangle
    {
        anchors.fill: parent
        color: "black"
        border.width: 10
        border.color: "grey"
        radius: 50
    }
    Rectangle
    {
        width: parent.width / 2
        height: 30
        x: parent.width / 4
        color: "black"
        Text
        {
            id: larm_text
            text: qsTr("LARM")
            font.pointSize: brakes.width / 20 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: grid_alarm
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 1
        columns: 2
        anchors.margins: 30
        Button
        {
            id: nbo_button


            //width: parent.width / 2 - 5
            width: (nbo_button.pressed) ? parent.width / 2 - 5 : parent.width / 3
            height: parent.height - 5

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
            width: parent.width / 2 - 5
            height: parent.height - 5
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
}
