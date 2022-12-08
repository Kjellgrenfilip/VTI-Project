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

    // Grey border around the button group
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        border.width: 5
        border.color: MyConst.darkGrey
        radius: 40
    }

    // Text for doors button group
    Rectangle
    {
        width: parent.width / 2
        height: 30
        x: parent.width / 4
        color: MyConst.backgroundColor
        Text
        {
            text: qsTr("DÖRRAR")
            font.pixelSize: doors.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    // The grid containing the buttons for doors button group
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

        // The left door button
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
                    PropertyChanges
                    {
                        target: doorLeftButton
                        enabled: true
                    }
                },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                        target: doorLeftImage
                        visible:true
                     }
                     PropertyChanges
                     {
                        target: doorLeftImageBlinking
                        visible:false
                     }
                     PropertyChanges
                     {
                        target: doorLeftButton
                        enabled: true
                     }
                 }
             ]
        }

        // The right door button
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

            states:
                [
                State
                {
                     name: "default";
                     PropertyChanges
                     {
                        target: doorRightImage
                        visible:true
                     }
                     PropertyChanges
                     {
                        target: doorRightImageBlinking
                        visible:false
                     }
                     PropertyChanges
                     {
                        target: doorRightButton
                        enabled: true
                     }
                },
                State
                {
                     name: "warning"
                     PropertyChanges
                     {
                        target: doorRightButton
                        enabled: true
                     }
                },
                 State {
                     name: "inactive";
                     PropertyChanges
                     {
                        target: doorRightImage
                        visible:true
                     }
                     PropertyChanges
                     {
                        target: doorRightImageBlinking
                        visible:false
                     }
                     PropertyChanges
                     {
                        target: doorRightButton
                        enabled: true
                     }
                }
            ]
        }

        // The departure button
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
                font.pixelSize: parent.width /9
            }
            onPressed: buttonHandler.departureButtonPressed()

            states:
                [
                State
                {
                    name: "default";
                    PropertyChanges
                    {
                        target: departureImage
                        visible: true
                    }
                    PropertyChanges
                    {
                        target: departureImageBlinking
                        visible: false
                    }
                    PropertyChanges
                    {
                        target: departureButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning";
                    PropertyChanges
                    {
                        target: departureButton
                        enabled: true
                    }
                },
                State
                {
                     name: "inactive";
                     PropertyChanges
                     {
                        target: departureImage
                        visible:true
                     }
                     PropertyChanges
                     {
                        target: departureImageBlinking
                        visible:false
                     }
                     PropertyChanges
                     {
                        target: departureButton
                        enabled: false
                     }
                 }
             ]
        }

        // The button for closing doors
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

            states:
                [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: closedImage
                        visible:true
                    }
                    PropertyChanges
                    {
                        target: closedImageBlinking
                        visible:false
                    }
                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active"
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
                        visible:true
                    }
                    PropertyChanges
                    {
                        target: closedImageBlinking
                        visible:false
                    }
                    PropertyChanges
                    {
                        target: closedButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning"
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
