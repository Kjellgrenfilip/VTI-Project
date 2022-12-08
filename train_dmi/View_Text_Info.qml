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

        // The area for showing received information
        Rectangle
        {
            width: parent.width*7/8 -5
            height: parent.height - 5
            color: "transparent"
            border.width: 5
            border.color: MyConst.darkGrey
            radius: 20
            Text
            {
                id: textAreaInfo
                objectName: "textInfo"
                anchors.fill: parent
                anchors.margins: 20
                Text
                {
                    id: textAreaInfoText
                    objectName: "textAreaInfoText"
                    anchors.fill: parent
                    color: MyConst.white
                    text: qsTr("")
                    font.pixelSize: parent.width/24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    // The button for acknowledging the received information
    Button
    {
        id: receiptButton
        objectName: "receipt"
        width:(receiptButton.pressed) ? parent.width / 8 - 10 : parent.width / 8 - 5
        height: (receiptButton.pressed) ? parent.height/2 - 10 : parent.height/2 - 5
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        enabled: false

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
            font.pixelSize: parent.width /8
            color: MyConst.white
        }
        Text
        {
            id: receiptB
            text: qsTr("KVITT.")
            anchors.top: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: parent.width /8
            color: MyConst.white
        }
        onPressed: buttonHandler.receiptPressed()

        states:
        [
            State {
                name: "default"
                PropertyChanges {
                    target: receiptButton
                    enabled: true
                }
            }
        ]
    }
}


