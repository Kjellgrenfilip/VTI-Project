
import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "Imports" 1.0


Item{
    anchors.fill: parent
    id: mainItem

    Frame{
        id: leftFrame;
        anchors.left: mainItem.left;
        anchors.bottom: mainItem.bottom;
        width: parent.width/4
        height:(parent.height/6)*5;

        background: Rectangle{
            anchors.fill: parent;
            color: MyConst.backgroundColor;
            border.color: "#bfbfbf";
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
            anchors.margins: 10;

            //Each rectangle represents a group of buttons. Insert one ButtonGroup per rectangle.
            Rectangle{
                       id: powerButtons
                       color: "transparent";
                       border.color: "#bfbfbf";
                       border.width: 2;
                       Layout.fillHeight: true
                       Layout.fillWidth: true
                       Layout.preferredHeight: (parent.height*3)/7
                       //Call ButtonGroup qml file here.
                       View_Power{}

                     }

            Rectangle{
                        id: doorButtons
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.preferredHeight: (parent.height*2)/7
                        //Call ButtonGroup qml file here.
                        View_Doors{}
                     }

            Rectangle{
                        id: backhornButtons
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.preferredHeight: (parent.height*1)/7
                         //Call ButtonGroup qml file here.
                        View_Back_Horn{}
                     }
            Rectangle{
                        id: activationButtons
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.preferredHeight: (parent.height*1)/7
                         //Call ButtonGroup qml file here.
                        View_Activate{}
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
            color: MyConst.backgroundColor;
            border.color: "#bfbfbf";
            border.width: 2;

            Text{
            text: "bottom Desk PANEL";
            color: "white";

            }
        }
        Rectangle{
            id: textInfo
            color: "transparent";
            anchors.fill: parent;
            View_Text_Info{}

        }
    }
    Frame{
        id: rightFrame;
        anchors.right: mainItem.right
        anchors.bottom: mainItem.bottom
        width: parent.width/4
        height:(parent.height/6)*5;
        background: Rectangle{
            anchors.fill: parent;
            color: MyConst.backgroundColor;
            border.color: "#bfbfbf";
            border.width: 2;
            Text{
            text: "right Desk PANEL";
            color: "white";
            }
        }


        GridLayout{
            anchors.fill: parent;
            columns: 1;
            rows: 4;
            rowSpacing: 4;
            anchors.margins: 10;


            Rectangle{
                        id: breakButtons
                       color: "transparent";
                       border.color: "#bfbfbf";
                       border.width: 2;
                       Layout.fillHeight: true
                       Layout.fillWidth: true

                       Layout.preferredHeight: (parent.height*2)/7
                        View_Brakes{}

                     }
            Rectangle{
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;

                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Layout.preferredHeight: (parent.height*3)/7

                     }

            Rectangle{
                        id: lightEmergency
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;

                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Layout.preferredHeight: (parent.height*1)/7

                        View_Light_Emergency{}


                     }
            Rectangle{
                        id: alarmButtons
                        color: "transparent";
                        border.color: "#bfbfbf";
                        border.width: 2;

                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Layout.preferredHeight: (parent.height*1)/7
                        View_Alarm{}

                     }



        }
    }

}

