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
        }
    }
}

