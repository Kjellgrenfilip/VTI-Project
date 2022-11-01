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
                width:640
                height:15
                color:"purple"
            }

            Rectangle
            {
                id: rectangleA
                anchors.left: parent.left
                anchors.top:rectangleZ.bottom
                width:54
                height:300
                color: "blue"
            }
            Rectangle
            {
                id:rectangleB
                anchors.left: rectangleA.right
                anchors.top: rectangleZ.bottom
                width:280
                height:300
                color:"red"
            }
            Rectangle
            {
                id:rectangleD
                anchors.left: rectangleB.right
                anchors.top:  rectangleZ.bottom
                width:246
                height:300
                color:"white"
            }
            Rectangle
            {
                id: rectangleC
                anchors.left:parent.left
                anchors.top: rectangleB.bottom
                width:334
                height:50
                color: "grey"
            }
            Rectangle
            {
                id:rectangleE
                anchors.left: parent.left
                anchors.top: rectangleC.bottom
                width: 334
                height: 100
                color: "red"

            }
            Rectangle
            {
                id:rectangleY
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                width:640
                height:15
                color:"green"
            }
            Rectangle
            {
                id:rectangleG
                anchors.left:rectangleC.right
                anchors.top:rectangleD.bottom
                width: 246
                height: 150
                color: "orange"
            }
            Rectangle
            {
                id:rectangleF
                anchors.left:rectangleD.right
                anchors.right: parent.right
                anchors.bottom: rectangleY.top
                width: 60
                height:450
                color: "blue"

            }

        }
    }
}

