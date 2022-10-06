import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0
/*known bug : text follows when button is pressed. this should not happen*/
Item {
    id: activate
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        Button
        {
            id: activate_button
            objectName: "activate"
            width: (activate_button.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(activate_button.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.left: parent.left
            padding: 0
            background: Rectangle{
                anchors.fill: parent
                color: MyConst.backgroundColor
            }

            Image
            {
                id: activate_image
                anchors.fill: parent
                source: "desk_ikoner/power_green2.png"
            }

            onPressed: buttonHandler.activatePressed()

            SequentialAnimation {
                id: activate_animation
                objectName: "activate_animation"
                running: true
                loops: Animation.Infinite
                PropertyAnimation {
                    target: activate_image
                    property: "source"
                    to: "desk_ikoner/power_green2.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: activate_image
                    property: "source"
                    to: "desk_ikoner/power2.png"
                    duration: MyConst.animation_duration
                }
            }
            states: [
                State {
                    name: "active";
                    PropertyChanges {
                        target: activate_image
                        source:"desk_ikoner/power_green2.png"
                    }
                    PropertyChanges {
                        target: activate_animation
                        running: false
                    }
                }
            ]



        }
        Button
        {
            id: protection_button
            width: (protection_button.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(protection_button.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle{
                anchors.fill: parent
                color: MyConst.backgroundColor
            }
            Image
            {
                id: protection_image
                anchors.fill: parent
                source: "desk_ikoner/power_green2.png"
            }


           }
        Button
        {
            id: cart_button
            width: (cart_button.pressed) ? parent.width / 4 -10 : parent.width / 4 - 5
            height:(cart_button.pressed) ? parent.height/(14/9) - 10 : parent.height/(14/9) - 5
            anchors.right: parent.right
            background: Rectangle{
                anchors.fill: parent
                color: MyConst.backgroundColor
            }
            Image
            {
                id: cart_image
                anchors.fill: parent
                source: "desk_ikoner/power_green2.png"
            }


           }
        TextArea
        {
            id: activate_text
            width: parent.width/9
            anchors.horizontalCenter: activate_button.horizontalCenter
            anchors.bottom:parent.bottom
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("AKTIVERING")
                font.pointSize: parent.width/3
                color: "White"
            }


        }
        TextArea
        {
            id: protection_text
            width: parent.width/9
            anchors.bottom:parent.bottom
            anchors.horizontalCenter: protection_button.horizontalCenter
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("TÅGSKYDD")
                font.pointSize: parent.width/3
                color:"White"
            }
        }
        TextArea
        {
            id: cart_text
            anchors.bottom:parent.bottom
            anchors.horizontalCenter: cart_button.horizontalCenter
            width: parent.width/9
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("BYT HYTT")
                font.pointSize: parent.width/3
                color:"White"
            }
       }
    }






}





