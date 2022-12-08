import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Grid
{
    id: activate
    anchors.fill: parent
    rows: 2
    columns: 3
    Rectangle
    {
        height : parent.height * 3 / 4
        width : parent.width/3
        color :  "transparent"
        //Activation button
        Button
        {
            id: activateButton
            objectName: "activate"
            width: activateButton.height
            height: (activateButton.pressed) ? parent.height -5 : parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 0
            background: Rectangle
            {
                anchors.fill: parent
                color: MyConst.backgroundColor
            }

            Image
            {
                id: activateImage
                anchors.fill: parent
                source: "desk_ikoner/power_green_3d.png"
            }

            onPressed: buttonHandler.activatePressed()

            SequentialAnimation
            {
                id: activateAnimation
                objectName: "activateAnimation"
                running: true
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: activateImage
                    property: "source"
                    to: "desk_ikoner/power_green_3d.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: activateImage
                    property: "source"
                    to: "desk_ikoner/power_white_3d.png"
                    duration: MyConst.animationDuration
                }
            }
            states: [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: activateImage
                        source:"desk_ikoner/power_green_3d.png"
                    }
                    PropertyChanges
                    {
                        target: activateAnimation
                        running: false
                    }
                }
            ]
        }

    }
    Rectangle
    {
        height : parent.height * 3 / 4
        width : parent.width/3
        color: "transparent"
        //Train protection button
        Button
        {
            id: protectionButton
            objectName: "protection"
            width: protectionButton.height
            height: (protectionButton.pressed) ? parent.height -5 : parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: false

            onPressed: buttonHandler.protectionPressed()

            Image
            {
                id: protectionImage
                anchors.fill: parent
                source: "desk_ikoner/power_white_3d.png"
            }
            SequentialAnimation
            {
                id: protectionAnimation
                objectName: "protectionAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: protectionImage
                    property: "source"
                    to: "desk_ikoner/power_green_3d.png"
                    duration: MyConst.animationDuration
                }

                PropertyAnimation
                {
                    target: protectionImage
                    property: "source"
                    to: "desk_ikoner/power_white_3d.png"
                    duration: MyConst.animationDuration
                }
            }

            states:
             [
                State
                {
                    name: "blinking";
                    PropertyChanges
                    {
                        target: protectionAnimation
                        running: false
                    }
                    PropertyChanges
                    {
                        target: protectionButton
                        enabled: true
                    }
                }
            ]
        }
    }
    Rectangle
    {
        height : parent.height * 3 / 4
        width : parent.width/3
        color : "transparent"
        // Change cart button
        Button
        {
            id: cartButton
            objectName: "cart"
            width: cartButton.height
            height:(cartButton.pressed) ? parent.height - 5 : parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: true
            Image
            {
                id: cartImage
                anchors.fill: parent
                source: "desk_ikoner/power_green_3d.png"
            }

            states:
                [
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: cartButton
                        enabled: true
                    }
                    PropertyChanges
                    {
                        target: cartImage
                        source: "desk_ikoner/power_green_3d.png"
                    }
                },
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: cartButton
                        enabled: false
                    }
                    PropertyChanges
                    {
                        target: cartImage
                        source: "desk_ikoner/power_white_3d.png"
                    }
                }
            ]
        }
    }
    // Text for activation button
    Rectangle
    {
        height: parent.height / 4
        width: parent.width/3
        color: "transparent"
        Text
        {
            id: activateText
            anchors.horizontalCenter: parent.horizontalCenter
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("AKTIVERING")
                font.pointSize: parent.width/3
                color: "White"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
    // Text for train protection button
    Rectangle
    {
        height: parent.height / 4
        width: parent.width/3
        color: "transparent"
        Text
        {
            id: protectionText

            anchors.horizontalCenter: parent.horizontalCenter
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("TÅGSKYDD")
                font.pointSize: parent.width/3
                color:"White"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
    // Text for changing cart button
    Rectangle
    {
        height: parent.height / 4
        width: parent.width/3
        color: "transparent"
        Text
        {
            id: cartText
            anchors.horizontalCenter: parent.horizontalCenter
            Text
            {
                text: qsTr("BYT HYTT")
                font.pointSize: parent.width/3
                color:"White"
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }
    }
}

