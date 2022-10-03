import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: reverse_horn
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"

        Button
        {
            id: reverse_button
            width: (reverse_button.pressed) ? parent.width / 2 -40 : parent.width / 2 - 35
            height:(reverse_button.pressed) ? parent.height - 40 : parent.height - 35
            anchors.margins: 5
            anchors.right: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Image
            {
                id: reverse_image
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            Text {
                id: reverse_text
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

            onPressed: buttonHandler.hornPressed()

            Image
            {
                id: horn_image
                anchors.fill: parent
                source: "desk_ikoner/siren5.png"
            }
        }
    }
}


