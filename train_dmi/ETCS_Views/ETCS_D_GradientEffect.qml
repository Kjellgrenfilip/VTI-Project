import QtQuick 2.0
import QtQuick.Shapes 1.15
import "../Imports" 1.0

Item
{
    anchors.fill: parent
    Rectangle
    {
        id: topBlack
        color: MyConst.black
        anchors.top: parent.top
        width: parent.width
        height: 1
    }
    Rectangle
    {
        id: topWhite
        color: MyConst.white
        anchors.top: parent.top
        anchors.margins: 1
        width: parent.width
        height: 1
    }
    Rectangle
    {
        id: left
        color: MyConst.white
        anchors.left: parent.left
        height: parent.height
        width: 1
    }
    Rectangle
    {
        id: bottom
        color: MyConst.black
        anchors.top: parent.top
        width: parent.width
        height: 1
    }
}
