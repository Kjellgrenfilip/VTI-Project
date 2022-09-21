import QtQuick 2.0

Item {
    id: etcs
    height: 480;
    width: 640;
    anchors.horizontalCenter: parent.horizontalCenter;
    anchors.verticalCenter: parent.verticalCenter;
    Rectangle{
        anchors.fill: parent;
        color: "black";
        Text{
            text: "ETCS_Panel";
            color:"white";
        }
    }
}

