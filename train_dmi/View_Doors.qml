import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: doors
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
            font.pointSize: doors.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: grid_doors
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {
            id: door_left_button
            width: (door_left_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(door_left_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id: door_left_image
                anchors.fill: parent
                source: "desk_ikoner/doorleft.png"
            }
        }
        Button
        {
            id:door_right_button
            width: (door_right_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(door_right_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id:door_right_image
                anchors.fill: parent
                source: "desk_ikoner/doorright.png"
            }
        }
        Button
        {
            id:avgang_button
            width: (avgang_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(avgang_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id: avgang_image
                anchors.fill: parent
                source: "desk_ikoner/avgang.png"
            }

        }
        Button
        {
            id:closed_button
            width: (closed_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(closed_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id: closed_image
                anchors.fill: parent
                source: "desk_ikoner/closed.png"
            }
        }

    }
}
