import QtQuick 2.0
import QtQuick.Shapes 1.15
import "../Imports" 1.0

Item{
    anchors.fill: parent
    Rectangle
    {
        id: top
        color: MyConst.black
        anchors.top: parent.top
        width: parent.width
        height: 2
    }
    Rectangle
    {
        id: left
        color: MyConst.black
        anchors.left: parent.left
        height: parent.height
        width: 2
    }
    Rectangle
    {
        id: right
        color: MyConst.shadow
        anchors.right: parent.right
        height: parent.height
        width: 2
    }
    Rectangle
    {
        id: bottom
        color: MyConst.shadow
        anchors.bottom: parent.bottom
        height: 2
        width: parent.width
    }
   /* Shape
    {
        id: triangleBlack
        width: parent.width
        height: parent.height
        //anchors.top: parent.top
        ShapePath {
            fillColor: MyConst.yellow
            startX: 0; startY: 0
            PathLine { x: 36; y: 0 }
            PathLine { x: 0; y: 36 }
            PathLine { x: 0; y: 0 }
        }

    }
    Shape
    {
        id: triangleShadow
        width: 36
        height: 36
        //anchors.top: parent.top
        ShapePath {
            fillColor: MyConst.blue
            startX: 36; startY: 36
            PathLine { x: 36; y: 0 }
            PathLine { x: 0; y: 36 }
            PathLine { x: 36; y: 36 }
        }

    }*/
}
