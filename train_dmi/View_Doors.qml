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

            onPressed: buttonHandler.leftDoorClicked()
            Image
            {

                id: doorLeftImage
                anchors.fill: parent
                source: "desk_ikoner/doorleft.png"
            }

            SequentialAnimation
            {
                id: doorLeftAnimation
                objectName: "doorLeftAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: doorLeftImage
                    property: "source"
                    to: "desk_ikoner/doorleftY.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: doorLeftImage
                    property: "source"
                    to: "desk_ikoner/doorleft.png"
                    duration: MyConst.animationDuration
                }
            }
            states: [
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                        target: doorLeftImage
                        source: "desk_ikoner/doorleftY.png"
                    }
                },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: doorLeftImage
                         source: "desk_ikoner/doorleft.png"
                     }
                     PropertyChanges
                     {
                         target: doorLeftAnimation
                         running: false
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
            Image
            {

                id:doorRightImage
                anchors.fill: parent
                source: "desk_ikoner/doorright.png"
            }

            onPressed: buttonHandler.rightDoorClicked()

            SequentialAnimation
            {
                id: doorRightAnimation
                objectName: "doorRightAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: doorRightImage
                    property: "source"
                    to: "desk_ikoner/doorrightY.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: doorRightImage
                    property: "source"
                    to: "desk_ikoner/doorright.png"
                    duration: MyConst.animationDuration
                }
            }
            states:
                [
                 State
                {
                     name: "warning"
                     PropertyChanges
                     {
                         target: doorRightImage
                         source: "desk_ikoner/doorrightY.png"
                     }
                    },
                 State {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: doorRightImage
                         source: "desk_ikoner/doorright.png"
                     }
                     PropertyChanges
                     {
                         target: doorRightAnimation
                         running: false
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
            Image
            {

                id: departureImage
                anchors.fill: parent
                source: "desk_ikoner/avgang.png"
            }

            onPressed: buttonHandler.departureButtonClicked()

            SequentialAnimation
            {
                id: departureAnimation
                objectName: "departureAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: departureImage
                    property: "source"
                    to: "desk_ikoner/green.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: departureImage
                    property: "source"
                    to: "desk_ikoner/avgang.png"
                    duration: MyConst.animationDuration
                }
            }
            states:
                [
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                         target: departureImage
                         source: "desk_ikoner/green.png"
                    }
                    },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                         target: departureImage
                         source: "desk_ikoner/avgang.png"
                     }
                     PropertyChanges
                     {
                         target: departureAnimation
                         running: false
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
            Image
            {
                id: closedImage
                anchors.fill: parent
                source: "desk_ikoner/closedG.png"
            }
            onPressed: buttonHandler.closeDoorClicked()

            SequentialAnimation
            {
                id: doorCloseAnimation
                objectName: "doorCloseAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: closedImage
                    property: "source"
                    to: "desk_ikoner/closedG.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: closedImage
                    property: "source"
                    to: "desk_ikoner/closed.png"
                    duration: MyConst.animationDuration
                }
            }

               states:
                   [
                   State
                   {
                        name: "active"
                        PropertyChanges
                        {
                            target: closedImage
                            source: "desk_ikoner/closedG.png"
                        }
                        PropertyChanges
                        {
                            target: doorCloseAnimation
                            running: false
                        }
                       },
                    State
                   {
                        name: "inactive";
                        PropertyChanges
                        {
                            target: closedImage
                            source: "desk_ikoner/closed.png"
                        }
                        PropertyChanges
                        {
                            target: doorCloseAnimation
                            running: false
                        }
                    },
                   State
                   {
                       name: "warning"
                       PropertyChanges
                       {
                           target: closedImage
                           source: "desk_ikoner/closedG.png"
                       }
                   }
              ]
        }
    }
}
