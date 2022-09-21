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


    Grid
    {
        id: grid_activate
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 1
        columns: 3
        anchors.margins: 30
        Button
        {
            width: parent.width / 3 - 5
            height: parent.height - 5
            Image
            {
                id: activate_image
                anchors.fill: parent
                source: "desk_ikoner/power_green.png"
            }
            Text {
                id: activate_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: activate_image.bottom
                text: qsTr("AKTIVERING")
                font.pointSize: parent.width /8
                color: "White"

            }
        }
        Button
        {
            width: parent.width / 3 - 5
            height: parent.height - 5
            Image
            {
                id: protection_image
                anchors.fill: parent
                source: "desk_ikoner/power_green.png"
            }
            Text {
                id: protection_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: protection_image.bottom
                text: qsTr("TÅGSKYDD")
                font.pointSize: parent.width /8
                color:"White"
            }
           }
        Button
        {
            width: parent.width / 3 - 5
            height: parent.height - 5
            Image
            {
                id: cart_image
                anchors.fill: parent
                source: "desk_ikoner/power_green.png"
            }
            Text {
                id: cart_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: cart_image.bottom
                text: qsTr("BYT HYTT")
                font.pointSize: parent.width /8
                color:"White"
            }
           }
    }
}

