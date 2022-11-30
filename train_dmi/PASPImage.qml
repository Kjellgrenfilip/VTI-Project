import QtQuick 2.0
import QtQml 2.15

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
            source: "symbols/Planning/PL_21.png"
            anchors.fill: parent
        }

        Text
        {
            id: text
            text: qsTr("text")
        }
    }
}
