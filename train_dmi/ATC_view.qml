import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    anchors.fill: parent;
    visible: false;
    Frame{
        id: leftFrame;
        width: parent.width;
        height: parent.height/6;
        background: Rectangle{
            anchors.fill: parent;
            color: "black";
            border.color: "white";
            border.width: 2;

            Text{
            text: "ATC PANEL";
            color: "white";
            }

        }
        Grid{
        }
    }
}
