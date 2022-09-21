
import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item{
    anchors.fill: parent
    id: mainItem
    Frame{
        id: leftFrame;
        anchors.left: mainItem.left;
        width: (parent.width-640) / 2 ;
        height:parent.height;
        background: Rectangle{
            anchors.fill: parent;
            color: "black";
            border.color: "white";
            border.width: 2;

            Text{
            text: "Left Desk PANEL";
            color: "white";
            }

        }
        Grid{
            id: leftGrid
            anchors.fill: parent;
            columns: 1;
            rows: 3;
            rowSpacing: 2;

        }
    }
    Frame{
        id: bottomFrame
        anchors.bottom: mainItem.bottom;
        anchors.horizontalCenter: mainItem.horizontalCenter;
        width: mainItem.width-leftFrame.width-rightFrame.width;
        height: mainItem.height-480;

        background: Rectangle{
            anchors.fill: parent;
            color: "black";
            border.color: "white";
            border.width: 2;

            Text{
            text: "bottom Desk PANEL";
            color: "white";

            }
        }
    }
    Frame{
        id: rightFrame;
        anchors.right: mainItem.right
        width: (parent.width-640) / 2 ;
        height:parent.height;
        background: Rectangle{
            anchors.fill: parent;
            color: "black";
            border.color: "white";
            border.width: 2;
        }
        Text{
        text: "right Desk PANEL";
        color: "white";
        }
    }
}

