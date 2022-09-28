import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
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
            font.pointSize: power.width / 25
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

   Grid  {
        id: grid
        spacing: 10
        //transformOrigin: Item.Center
        anchors.fill:parent
        //anchors.left: parent.right
        rows: 3
        columns: 2
        anchors.margins: 30
        // clickable pantograph up
        Button
        {
            id:pont_up_button
            width: (pont_up_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pont_up_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            //anchors.fill: parent

            onClicked: network.pontUpClicked()

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
            id:pont_charge_button
            width:  parent.width / 2 - 5
            height: parent.height / 3 - 7

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
            id:pont_down_button
            width: (pont_down_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pont_down_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
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
            id:sp_button
            width: parent.width / 2 - 5
            height: parent.height / 3 - 7
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
            id:h_bryt_button
            width: (h_bryt_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(h_bryt_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7

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
            id:tågv_button
            width: (tågv_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(tågv_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7

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
