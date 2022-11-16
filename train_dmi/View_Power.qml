import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import "Imports" 1.0

Item
{
    id: power
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
            text: qsTr("SPÄNNING")
            font.pointSize: power.width / 25
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

   Grid
   {
        id: grid
        spacing: 10
        anchors.fill:parent
        rows: 3
        columns: 2
        anchors.margins: 30

        Button
        {
            id:pantUpButton
            objectName: "pantographUp"
            width: (pantUpButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pantUpButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            //anchors.fill: parent
            enabled: false

            onPressed: buttonHandler.pantUpPressed()
            Image
            {
                id: pantUpImage
                objectName: "pantUpImage"
                anchors.fill: parent
                source: "desk_ikoner/Up.png"
                visible: true
            }
            Image
            {
                id: pantUpImageBlinking
                objectName: "pantUpImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/UpY.png"
                visible: false
            }
//            SequentialAnimation
//            {
//                id: pantographUpAnimation
//                objectName: "pantographUpAnimation"
//                running: false
//                loops: Animation.Infinite
//                alwaysRunToEnd: false
//                PropertyAnimation
//                {
//                    target: pantUpImage
//                    property: "source"
//                    to: "desk_ikoner/UpY.png"
//                    duration: MyConst.animationDuration
//                }

//                PropertyAnimation
//                {
//                    target: pantUpImage
//                    property: "source"
//                    to: "desk_ikoner/Up.png"
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
                    target: pantUpImage
                    source:"desk_ikoner/Up.png"
                }
                PropertyChanges
                {
                    target: pantUpButton
                    enabled: true
                }
//                PropertyChanges
//                {
//                    target: pantographUpAnimation
//                    running: false
//                }
            },
            State
            {
                name: "active"
                PropertyChanges
                {
                    target: pantUpImage
                    source: "desk_ikoner/UpY.png"
                }
                PropertyChanges
                {
                    target: pantUpButton
                    enabled: true
                }
//                PropertyChanges
//                {
//                    target: pantographUpAnimation
//                    running: false
//                }
            },
            State
            {
                name: "warning";
                PropertyChanges
                {
                    target: pantUpButton
                    enabled: true
                }
//                PropertyChanges
//                {
//                    target: pantographUpAnimation
//                    running: false
//                }
            },
            State
            {
                name: "inactive"
                PropertyChanges
                {
                    target: pantUpImage
                    source:"desk_ikoner/Up.png"
                }
                PropertyChanges
                {
                    target: pantUpButton
                    enabled: true
                }
//                PropertyChanges
//                {
//                    target: pantographUpAnimation
//                    running: false
//                }
            }
            ]
        }

        // non-clickable power indicator
        Button
        {
            id:pantChargeButton
            objectName: "voltage"
            width:  parent.width / 2 - 5
            height: parent.height / 3 - 7
            enabled: false

            Image
            {
                id:pantChargeImage
                anchors.fill: parent
                source: "desk_ikoner/indicator_frame.png"
            }

            Text
            {
                id: pantChargeText
                text: qsTr("0V")
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            states:
            [
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: pantChargeText
                        text: qsTr("16kV")
                    }
                    PropertyChanges
                    {
                        target: pantChargeImage
                        source: "desk_ikoner/indicator_frame.png"
                    }
                },
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: pantChargeText
                        text: qsTr("0V")
                    }
                    PropertyChanges
                    {
                        target: pantChargeImage
                        source: "desk_ikoner/indicator_frameR.png"
                    }
                }
            ]
        }
        //clickable pantograph down
        Button
        {
            id:pantDownButton
            objectName:  "pantographDown"
            width: (pantDownButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pantDownButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            enabled: false

            Image
            {
                id:pantDownImage
                anchors.fill: parent
                source: "desk_ikoner/Down.png"
            }
            onPressed: buttonHandler.pantDownPressed()
            states:
                [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: pantDownImage
                        source:"desk_ikoner/Down.png"
                    }
                    PropertyChanges
                    {
                        target: pantDownButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: pantDownImage
                        source: "desk_ikoner/DownY.png"
                    }
                    PropertyChanges
                    {
                        target: pantDownButton
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: pantDownImage
                        source:"desk_ikoner/Down.png"
                    }
                    PropertyChanges
                    {
                        target: pantDownButton
                        enabled: true
                    }
                }
                ]
        }

        // non-clickable current indicator?
        Button
        {
            id:voltageWarningButton
            objectName: "voltageWarning"
            width: parent.width / 2 - 5
            height: parent.height / 3 - 7
            enabled: false

            Image
            {
                id: voltageWarningImage
                objectName: "voltageWarningImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }
            Image
            {
                id: voltageWarningImageBlinking
                objectName: "voltageWarningImageBlinking"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: false
            }
            text: "0-SP"

//            SequentialAnimation
//            {
//                id: voltageWarningAnimation
//                objectName: "voltageWarningAnimation"
//                running: false
//                loops: Animation.Infinite
//                PropertyAnimation
//                {
//                    target: voltageWarningImage
//                    property: "source"
//                    to: "desk_ikoner/yellow.png"
//                    duration: MyConst.animationDuration
//                }
//                PropertyAnimation
//                {
//                    target: voltageWarningImage
//                    property: "source"
//                    to: "desk_ikoner/button69.png"
//                    duration: MyConst.animationDuration
//                }
//            }

            states:
                [
                State
                {
                    name: "default"
//                    PropertyChanges
//                    {
//                        target: voltageWarningAnimation
//                        running: false
//                    }
                    PropertyChanges
                    {
                        target: voltageWarningImage
                        source: "desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: voltageWarningButton
                        enabled: true
                    }
                },
                State
                {
                    name: "warning"
                    PropertyChanges
                    {
                        target: voltageWarningButton
                        enabled: true
                    }
//                    PropertyChanges
//                    {
//                        target: voltageWarningAnimation
//                        running : false
//                    }
                },
                State
                {
                    name: "inactive"
//                    PropertyChanges
//                    {
//                        target: voltageWarningAnimation
//                        running : false
//                    }
                    PropertyChanges
                    {
                        target: voltageWarningImage
                        source: "desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: voltageWarningButton
                        enabled: true
                    }
                }
                ]
        }
        //clickable main breaker
        Button
        {
            id:mainBreakerButton
            objectName: "mainBreaker"
            width: (mainBreakerButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(mainBreakerButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            enabled: false

            Image
            {
                id: mainBreakerImage
                objectName: "mainBreakerImage"
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
                visible: true
            }

            text: "H-BRYT"
            onPressed: buttonHandler.mainBreakerPressed()
            states:
                [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: mainBreakerImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: mainBreakerButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: mainBreakerImage
                        source: "desk_ikoner/yellow.png"
                    }
                    PropertyChanges
                    {
                        target: mainBreakerButton
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: mainBreakerImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: mainBreakerButton
                        enabled: true
                    }
                }
            ]

        }
        //clickable heating
        Button
        {
            id:trainHeatButton
            objectName: "heating"
            width: (trainHeatButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(trainHeatButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            enabled: false

            Image
            {
                id: trainHeatImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "TÅGV."
            onPressed: buttonHandler.heatingPressed()
            states:
                [
                State
                {
                    name: "default"
                    PropertyChanges
                    {
                        target: trainHeatImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: trainHeatButton
                        enabled: true
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: trainHeatImage
                        source: "desk_ikoner/yellow.png"
                    }
                    PropertyChanges
                    {
                        target: trainHeatButton
                        enabled: true
                    }
                },
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: trainHeatImage
                        source:"desk_ikoner/button69.png"
                    }
                    PropertyChanges
                    {
                        target: trainHeatButton
                        enabled: true
                    }
                }
                ]
        }
    }
}
