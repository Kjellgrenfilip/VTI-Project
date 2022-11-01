import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import "Imports" 1.0

Item {
    anchors.fill: parent
    id: etcs
    Frame
    {
        width: parent.width/2;
        height: (parent.height/3)*2;
        anchors.horizontalCenter: etcs.horizontalCenter;
        anchors.verticalCenter: etcs.verticalCenter;
        background: Rectangle{
            anchors.fill: parent;
            color: MyConst.backgroundColor;
            border.color: "#bfbfbf";
            border.width: 2;
            Text{
                text: "ETCS_Panel";
                color:"white";
            }
            Rectangle
            {
                id: rectangleZ
                width: parent.width
                height: (15/MyConst.etcsHeight) * parent.height
                color:"purple"
            }

            Rectangle
            {
                id: rectangleA
                anchors.left: parent.left
                anchors.top:rectangleZ.bottom
                width:(54/MyConst.etcsWidth) * parent.width
                height:(300/MyConst.etcsHeight) * parent.height
                color: "blue"
                ETCS_A{}
            }
            Rectangle
            {
                id:rectangleB
                anchors.left: rectangleA.right
                anchors.top: rectangleZ.bottom
                width:(280/MyConst.etcsWidth) * parent.width
                height:(300/MyConst.etcsHeight) * parent.height
                color:"red"
            }
            Rectangle
            {
                id:rectangleD
                anchors.left: rectangleB.right
                anchors.top:  rectangleZ.bottom
                width:(246/MyConst.etcsWidth) * parent.width
                height:(300/MyConst.etcsHeight) * parent.height
                color:"white"
            }
            Rectangle
            {
                id: rectangleC
                anchors.left:parent.left
                anchors.top: rectangleB.bottom
                width:(334/MyConst.etcsWidth) * parent.width
                height:(50/MyConst.etcsHeight) * parent.height
                color: "grey"
            }
            Rectangle
            {
                id:rectangleE
                anchors.left: parent.left
                anchors.top: rectangleC.bottom
                width: (334/MyConst.etcsWidth) * parent.width
                height: (100/MyConst.etcsHeight) * parent.height
                color: "red"

            }
            Rectangle
            {
                id:rectangleY
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                width:(640/MyConst.etcsWidth) * parent.width
                height:(15/MyConst.etcsHeight) * parent.height
                color:"green"
            }
            Rectangle
            {
                id:rectangleG
                anchors.left:rectangleC.right
                anchors.top:rectangleD.bottom
                width: (246/MyConst.etcsWidth) * parent.width
                height: (150/MyConst.etcsHeight) * parent.height
                color: "orange"
            }
            Rectangle
            {
                id:rectangleF
                anchors.left:rectangleD.right
                anchors.right: parent.right
                anchors.bottom: rectangleY.top
                width: (60/MyConst.etcsWidth) * parent.width
                height: (450/MyConst.etcsHeight) * parent.height
                color: "blue"
            }
        }
    }
}

