import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Item
{
    id: doors
    anchors.fill: parent
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
    }
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        border.width: 10
        border.color: "grey"
        radius: 50
    }
    Rectangle
    {
        width: parent.width / 2
        height: 30
        x: parent.width / 4
        color: MyConst.backgroundColor
        Text
        {
            text: qsTr("DÖRRAR")
            font.pointSize: doors.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: gridDoors
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {
            id: doorLeftButton
            objectName: "doorLeft"
            width: (doorLeftButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(doorLeftButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            onPressed: buttonHandler.leftDoorPressed()
            Image
            {
                id: doorLeftImage
                objectName: "doorLeftImage"
                anchors.fill: parent
                source: "desk_ikoner/doorleft.png"
                visible: true
            }
            Image
            {
                id: doorLeftImageBlinking
                objectName: "doorLeftImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/doorleftY.png"
                visible: false
            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: doorLeftButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
//                    PropertyChanges
//                    {
//                        target: doorLeftImage
//                        source: "desk_ikoner/doorleftY.png"
//                    }
                    PropertyChanges
                    {
                        target: doorLeftButton
                        enabled: true
                    }
//                    PropertyChanges
//                    {
//                        target: doorLeftAnimation
//                        running: false
//                    }
                },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: doorLeftImage
                         //source: "desk_ikoner/doorleft.png"
                         visible:true
                     }
                     PropertyChanges
                     {
                         target: doorLeftImageBlinking
                         //source: "desk_ikoner/doorleft.png"
                         visible:false
                     }
//                     PropertyChanges
//                     {
//                         target: doorLeftAnimation
//                         running: false
//                     }
                     PropertyChanges
                     {
                         target: doorLeftButton
                         enabled: true
                     }
                 }
             ]
        }
        Button
        {
            id:doorRightButton
            objectName: "doorRight"
            width: (doorRightButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(doorRightButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            Image
            {
                id:doorRightImage
                objectName: "doorRightImage"
                anchors.fill: parent
                source: "desk_ikoner/doorright.png"
                visible: true
            }
            Image
            {
                id:doorRightImageBlinking
                objectName: "doorRightImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/doorrightY.png"
                visible:false
            }

            onPressed: buttonHandler.rightDoorPressed()

//            SequentialAnimation
//            {
//                id: doorRightAnimation
//                objectName: "doorRightAnimation"
//                running: false
//                loops: Animation.Infinite
//                alwaysRunToEnd: true
//                PropertyAnimation
//                {
//                    target: doorRightImage
//                    property: "source"
//                    to: "desk_ikoner/doorrightY.png"
//                    duration: MyConst.animationDuration
//                }

//                PropertyAnimation
//                {
//                    target: doorRightImage
//                    property: "source"
//                    to: "desk_ikoner/doorright.png"
//                    duration: MyConst.animationDuration
//                }
//            }
            states:
                [
                State
                {
                     name: "default";
                     PropertyChanges
                     {
                         target: doorRightImage
                         //source: "desk_ikoner/doorright.png"
                         visible:true
                     }
                     PropertyChanges
                     {
                         target: doorRightImageBlinking
                         //source: "desk_ikoner/doorright.png"
                         visible:false
                     }
//                     PropertyChanges
//                     {
//                         target: doorRightAnimation
//                         running: false
//                     }
                     PropertyChanges
                     {
                         target: doorRightButton
                         enabled: true
                     }
                },
                State
                {
                     name: "warning"
//                     PropertyChanges
//                     {
//                         target: doorRightImage
//                         source: "desk_ikoner/doorrightY.png"
//                     }
                     PropertyChanges
                     {
                         target: doorRightButton
                         enabled: true
                     }
//                     PropertyChanges
//                     {
//                         target: doorRightAnimation
//                         running: false
//                     }
                },
                 State {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: doorRightImage
                         //source: "desk_ikoner/doorright.png"
                         visible:true
                     }
                     PropertyChanges
                     {
                         target: doorRightImageBlinking
                         visible:false
                     }
//                     PropertyChanges
//                     {
//                         target: doorRightAnimation
//                         running: false
//                     }
                     PropertyChanges
                     {
                         target: doorRightButton
                         enabled: true
                     }
                }
            ]
        }
        Button
        {
            id:departureButton
            objectName: "departure"
            width: (departureButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(departureButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            Image
            {
                id: departureImage
                objectName: "departureImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: departureImageBlinking
                objectName: "departureImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/green.png"
                visible: false
            }
            Text {
                id: departureText
                text: "KLART FÖR \n AVGÅNG"
                anchors.fill: parent
                anchors.margins:10
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "white"
                font.pointSize: parent.width /9
            }
            onPressed: buttonHandler.departureButtonPressed()

//            SequentialAnimation
//            {
//                id: departureAnimation
//                objectName: "departureAnimation"
//                running: false
//                loops: Animation.Infinite
//                alwaysRunToEnd: true
//                PropertyAnimation
//                {
//                    target: departureImage
//                    property: "source"
//                    to: "desk_ikoner/green.png"
//                    duration: MyConst.animationDuration
//                }

//                PropertyAnimation
//                {
//                    target: departureImage
//                    property: "source"
//                    to: "desk_ikoner/button69.png"
//                    duration: MyConst.animationDuration
//                }
//            }
            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                         target: departureImage
                         //source: "desk_ikoner/button69.png"
                         visible: true
                    }
                    PropertyChanges
                    {
                         target: departureImageBlinking
                         //source: "desk_ikoner/button69.png"
                         visible: false
                    }
//                    PropertyChanges
//                    {
//                        target: departureAnimation
//                        running: false
//                    }
                    PropertyChanges
                    {
                        target: departureButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
//                    PropertyChanges
//                    {
//                         target: departureImage
//                         source: "desk_ikoner/green.png"
//                    }
                    PropertyChanges
                    {
                        target: departureButton
                        enabled: true
                    }
//                    PropertyChanges
//                    {
//                        target: departureAnimation
//                        running: true
//                    }
                },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: departureImage
                         //source: "desk_ikoner/avgang.png"
                         visible:true
                     }
                     PropertyChanges
                     {
                         target: departureImageBlinking
                         //source: "desk_ikoner/avgang.png"
                         visible:false
                     }
//                   PropertyChanges
//                     {
//                         target: departureAnimation
//                         running: false
//                     }
                     PropertyChanges
                     {
                         target: departureButton
                         enabled: false
                     }
                 }
             ]
        }
        Button
        {
            id:closedButton
            objectName: "doorClose"
            width: (closedButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(closedButton.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            enabled: false

            Image
            {
                id: closedImage
                objectName: "doorCloseImage"
                anchors.fill: parent
                source: "desk_ikoner/closed.png"
                visible: true
            }
            Image
            {
                id: closedImageBlinking
                objectName: "doorCloseImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/closedG.png"
                visible: false
            }

            onPressed: buttonHandler.closeDoorPressed()

//            SequentialAnimation
//            {
//                id: doorCloseAnimation
//                objectName: "doorCloseAnimation"
//                running: false
//                loops: 3
//                //alwaysRunToEnd: true



//                PropertyAnimation
//                {
//                    target: closedImage
//                    property: "source"
//                    to: "desk_ikoner/closedG.png"
//                    duration: MyConst.animationDuration
//                }
//                PropertyAnimation
//                {
//                    target: closedImage
//                    property: "source"
//                    to: "desk_ikoner/closed.png"
//                    duration: MyConst.animationDuration
//                }
//            }
            states:
                [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: closedImage
                        //source: "desk_ikoner/closedG.png"
                        visible:true
                    }
                    PropertyChanges
                    {
                        target: closedImageBlinking
                        //source: "desk_ikoner/closedG.png"
                        visible:false
                    }
//                    PropertyChanges
//                    {
//                        target: doorCloseAnimation
//                        running: false
//                    }
                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active"
//                    PropertyChanges
//                    {
//                        target: closedImage
//                        source: "desk_ikoner/closedG.png"
//                    }
//                    PropertyChanges
//                    {
//                        target: doorCloseAnimation
//                        running: false
//                    }


                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: closedImage
                        //source: "desk_ikoner/closed.png"
                        visible:true
                    }
                    PropertyChanges
                    {
                        target: closedImageBlinking
                        //source: "desk_ikoner/closed.png"
                        visible:false
                    }
//                    PropertyChanges
//                    {
//                        target: doorCloseAnimation
//                        running: false
//                    }
                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning"
//                    PropertyChanges
//                    {
//                        target: doorCloseAnimation
//                        running: false
//                    }
                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                }
            ]
        }
    }
}
