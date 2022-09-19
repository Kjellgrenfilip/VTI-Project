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
            id: name
            text: qsTr("DÖRRAR")
            font.pointSize: brakes.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: grid
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {

                id: pont_up
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: park
                text: qsTr("PARK")

            }
        }
        Button
        {
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {

                id: b
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: broms
                anchors.horizontalCenter: parent.horizontalCenter
                y:parent.y + parent.height/2
                text: qsTr("BROMS")
                font.pointSize: parent.width /15
                color:"White"
            }
            Text {
                id: bromon
                text: qsTr("FRÅN")
                anchors.horizontalCenter: parent.horizontalCenter
                //anchors.verticalCenter: parent.verticalCenter
                y:broms.y + 30
                font.pointSize: parent.width /15
                color:"White"
            }
        }
        Button
        {
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {

                id: c
                anchors.fill: parent
                source: "desk_ikoner/avgang.png"
            }

        }
        Button
        {
            width: parent.width / 2 - 5
            height: parent.height / 2 - 5
            Image
            {

                id: d
                anchors.fill: parent
                source: "desk_ikoner/closed.png"
            }
        }

    }
}
