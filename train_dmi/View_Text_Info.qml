import QtQuick 2.15
import QtQuick.Controls 2.0
import "Imports" 1.0
Item {
    id: textInfo
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
            TextArea // should be textinput
            {
                id: textAreaInfo
                objectName: "textInfo"
                anchors.fill: parent
                anchors.margins: 20
                readOnly: true

                Text
                {
                    id: textAreaInfoText
                    objectName: "textAreInfoText"
                    anchors.fill: parent
                    color: "White"
                    text: qsTr("hello")
                    font.pointSize: parent.width/24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
           }
    Button
    {
        id: receiptButton
        objectName: "receipt"
        width:(receiptButton.pressed) ? parent.width / 8 - 10 : parent.width / 8 - 5
        height: (receiptButton.pressed) ? parent.height/2 - 10 : parent.height/2 - 5
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        Image
        {
            id: receiptImage
            anchors.fill: parent
            source: "desk_ikoner/button69.png"
        }
        Text
        {
            id: receiptA
            anchors.bottom: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("FEL")
            font.pointSize: parent.width /8
            color:"White"
        }
        Text
        {
            id: receiptB
            text: qsTr("KVITT.")
            anchors.top: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: parent.width /8
            color:"White"
        }
        onClicked: buttonHandler.receiptClicked();
    }
}


