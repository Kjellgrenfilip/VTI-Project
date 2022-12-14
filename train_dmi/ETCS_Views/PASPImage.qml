import QtQuick 2.0

Item {
    id: pasp
    objectName: "pasp"
    anchors.fill: parent
    height: 300
    width: 300
    z: 50


    Rectangle
    {
        anchors.fill: parent
        objectName: "speed"
        color: "red"

        Image
        {
            id: image
            source: "symbols/Planning/PL_22.png"
            anchors.fill: parent
        }

        Text
        {
            id: text
            text: qsTr("text")
        }
    }
}
