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
            id:pontUpButton
            objectName: "pontographUp"
            width: (pontUpButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pontUpButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            //anchors.fill: parent

            onClicked: buttonHandler.pontUpClicked()

            Image
            {
                id: pontUpImage
                anchors.fill: parent
                source: "desk_ikoner/Up.png"
            }

        states:
            [
            State {
                name: "active"
                PropertyChanges
                {
                    target: pontUpImage
                    source: "desk_ikoner/UpY.png"
                }
            },
            State
            {
                name: "inactive"
                PropertyChanges
                {
                    target: pontUpImage
                    source:"desk_ikoner/Up.png"
                }
            }
            ]
        }

        // non-clickable power indicator
        Button
        {
            id:pontChargeButton
            objectName: "voltage"
            width:  parent.width / 2 - 5
            height: parent.height / 3 - 7

            Image
            {
                id:pontChargeImage
                anchors.fill: parent
                source: (pontChargeButton.text == "0V") ? "desk_ikoner/indicator_frameR.png" : "desk_ikoner/indicator_frame.png"
            }

            text: "0V"

            onTextChanged:  if(pontChargeButton.text.charAt(pontChargeButton.text.length -1) != "V")
                            {
                                if(pontChargeButton.text.charAt(0) == "0")
                                {
                                    pontChargeButton.text = pontChargeButton.text + "V"
                                }
                                else
                                {
                                    pontChargeButton.text = pontChargeButton.text + "kV"
                                }
                            }
        }
        //clickable pantograph down
        Button
        {
            id:pontDownButton
            objectName:  "pontographDown"
            width: (pontDownButton.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pontDownButton.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            Image
            {
                id:pontDownImage
                anchors.fill: parent
                source: "desk_ikoner/Down.png"
            }
            onClicked: buttonHandler.pontDownClicked()
            states:
                [
                State
                    {
                    name: "active"
                    PropertyChanges
                    {
                        target: pontDownImage
                        source: "desk_ikoner/DownY.png"
                    }
                },
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: pontDownImage
                        source:"desk_ikoner/Down.png"

                    }
                }
                ]
        }

        // non-clickable current indicator?
        Button
        {
            id:volatageWarningButton
            objectName: "voltageWarning"
            width: parent.width / 2 - 5

            height: parent.height / 3 - 7
            Image
            {
                id: volatageWarningImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "0-SP"

            SequentialAnimation
            {
                id: voltageWarningAnimation
                objectName: "voltageWarningAnimation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation
                {
                    target: volatageWarningImage
                    property: "source"
                    to: "desk_ikoner/yellow.png"
                    duration: MyConst.animationDuration
                }
                PropertyAnimation
                {
                    target: volatageWarningImage
                    property: "source"
                    to: "desk_ikoner/button69.png"
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
                        target: voltageWarningAnimation
                        running : false
                    }
                },
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: voltageWarningAnimation
                        running : false
                    }
                    PropertyChanges
                    {
                        target: volatageWarningImage
                        source: "desk_ikoner/button69.png"

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

            Image
            {
                id: mainBreakerImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "H-BRYT"
            onClicked: buttonHandler.mainBreakerClicked()
            states:
                [
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: mainBreakerImage
                        source: "desk_ikoner/yellow.png"
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

            Image
            {
                id: trainHeatImage
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "TÅGV."
            onClicked: buttonHandler.heatingClicked()
            states:
                [
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: trainHeatImage
                        source: "desk_ikoner/yellow.png"
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
                }
                ]
        }
    }
}
