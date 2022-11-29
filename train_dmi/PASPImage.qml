import QtQuick 2.0

Item {
    anchors.fill: parent
    Rectangle
    {
        height: 50
        width: 50
        objectName: "speed"
        color: "black"
        Image
        {
            id: image
            source: "symbols/Planning/PL_21.png"
        }

        Text
        {
            id: text
            text: qsTr("text")
        }
    }
}
