
import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item{
    anchors.fill: parent
    id: mainItem
    Frame{
        id: leftFrame;
        anchors.left: mainItem.left;
        width: parent.width/4
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
        GridLayout{
            anchors.fill: parent;
            columns: 1;
            rows: 4;
            rowSpacing: 4;


            Rectangle{
                       color: "red";
                       border.color: "white";
                       border.width: 2;
                       Layout.fillHeight: true
                       Layout.fillWidth: true
                       //Layout.rowSpan: 3
                       //Layout.row: 4
                       Layout.preferredHeight: (parent.height*3)/7
                       Buttontest2{}

                     }
            Rectangle{
                        color: "yellow";
                        border.color: "white";
                        border.width: 2;
                        //height: 100;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        //Layout.rowSpan: 2
                        Layout.preferredHeight: (parent.height*2)/7
                        Buttontest{}
                     }

            Rectangle{
                        color: "blue";
                        border.color: "white";
                        border.width: 2;
                        //height: 100;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        //Layout.rowSpan: 1
                        Layout.preferredHeight: (parent.height*1)/7

                     }
            Rectangle{
                        color: "blue";
                        border.color: "white";
                        border.width: 2;
                        //height: 100;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        //Layout.rowSpan: 1
                        Layout.preferredHeight: (parent.height*1)/7

                     }



        }
    }
    Frame{
        id: bottomFrame
        anchors.bottom: mainItem.bottom;
        anchors.horizontalCenter: mainItem.horizontalCenter;
        width: mainItem.width-leftFrame.width-rightFrame.width;
        height: mainItem.height/6;

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
        width: parent.width/4
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

