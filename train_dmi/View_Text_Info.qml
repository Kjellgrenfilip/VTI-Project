import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0
Item {
    id: text_info
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        Rectangle
        {
            width: parent.width*7/8 -5
            height: parent.height - 5
            color: "transparent"
            border.width: 10
            border.color: "grey"
            radius: 25
//            Text {
//                id: text_info_a
//                anchors.left: parent.left
//                anchors.top: parent.top
//                anchors.margins: 15
//                text: qsTr("hello")
//                color:"White"
//            }
//            Text {
//                id: text_info_b
//                //anchors.fill: parent
//                anchors.top: text_info_a.bottom
//                anchors.left: parent.left
//                anchors.leftMargin: 15
//                anchors.topMargin: 3

//                text: qsTr("world")
//                color:"White"
//            }

        }
//        TextArea
//        {
//            id: text_area_info
//            anchors.fill: parent
//            readOnly: true
//            color: "White"
//            text: qsTr("\n  Try to edit me!")



//        }
//        Text {
//            id: hello
//            text: qsTr("")
//        }


    }
    Button
    {
        id: kvitt_button
        objectName: "receipt"
        width:(kvitt_button.pressed) ? parent.width / 8 - 10 : parent.width / 8 - 5
        height: (kvitt_button.pressed) ? parent.height/2 - 10 : parent.height/2 - 5
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        Image
        {
            id: fel_kvitt_image
            anchors.fill: parent
            source: "desk_ikoner/button69.png"
        }
        Text {
            id: fel_kvitt_a
            anchors.bottom: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("FEL")
            font.pointSize: parent.width /8
            color:"White"
        }
        Text {
            id: fel_kvitt_b
            text: qsTr("KVITT.")
            anchors.top: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            //y:broms.y + 30
            font.pointSize: parent.width /8
            color:"White"
        }
        //property string data: " " // should be what is changed in textmodule to update the text
        onClicked: buttonHandler.receiptClicked();
//            data: ""
//            states:[
//            State {
//                name: "on"
//                hello.text: qstr("hello")
//                }

//            },
//                State {
//                    name: "off"
//                    PropertyChanges {
//                        target: pont_down
//                        source:"desk_ikoner/Down.png"

//                    }
//                }
//            ]
    }
}


