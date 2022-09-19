import QtQuick 2.0
import QtQuick.Controls 2.0
//import
//import "other files/desk_ikoner"

Item
{
    id: power
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
            text: qsTr("SPÄNNING")
            font.pointSize: power.width / 25 // gives warning
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
        rows: 3
        columns: 2
        anchors.margins: 30
        // clickable pantograph up
        Button
        {
            width: parent.width / 2 - 5
            height: parent.height / 3 - 5
            Image
            {

                id: pont_up
                anchors.fill: parent
                source: "desk_ikoner/Up.png"
            }
        }
        // non-clickable power indicator
        Button
        {
            width: parent.width / 2 -5
            height: parent.height / 3 - 5

            Image
            {
                id:pont_charge
                anchors.fill: parent
                source: "desk_ikoner/indicator_frameR.png"
            }
            text: "0V"
        }
        //clickable pantograph down
        Button
        {
            width: parent.width / 2 -5
            height: parent.height / 3 - 5
            Image
            {
                id:pont_down
                anchors.fill: parent
                source: "desk_ikoner/Down.png"
            }

        }
        // non-clickable current indicator?
        Button
        {
            width: parent.width / 2 -5
            height: parent.height / 3 - 5
            Image
            {
                id:sp
                anchors.fill: parent
                source: "desk_ikoner/yellow.png"
            }
            text: "0-SP"
        }
        //clickable main breaker
        Button
        {
            width: parent.width / 2 -5
            height: parent.height / 3 - 5
            Image
            {
                id: h_bryt
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "H-BRYT"
        }
        //clickable heating
        Button
        {
            width: parent.width / 2 -5
            height: parent.height / 3 - 5
            Image
            {
                id:tågv
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "TÅGV."
        }
    }
}
