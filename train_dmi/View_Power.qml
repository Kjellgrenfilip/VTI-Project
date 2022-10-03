import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import "Imports" 1.0
//import power_button_implement 1.0

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
        color: "#041122"
        Text
        {
            id: name
            text: qsTr("SPÄNNING")
            font.pointSize: power.width / 25
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

   Grid  {
        id: grid
        spacing: 10
        anchors.fill:parent
        rows: 3
        columns: 2
        anchors.margins: 30
        // clickable pantograph up
        Button
        {
            id:pont_up_button
            objectName: "pontograph_up"
            width: (pont_up_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pont_up_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            //anchors.fill: parent

            onClicked: buttonHandler.pontUpClicked()

            Image
            {
                id: pont_up
                anchors.fill: parent
                source: "desk_ikoner/Up.png"
            }
        states:[
        State {
            name: "on"
            PropertyChanges {
                target: pont_up
                source: "desk_ikoner/UpY.png"

            }

        },
            State {
                name: "off"
                PropertyChanges {
                    target: pont_up
                    source:"desk_ikoner/Up.png"

                }
            }
        ]
        }
        // non-clickable power indicator
        Button
        {
            id:pont_charge_button
            objectName: "voltage"
            width:  parent.width / 2 - 5
            height: parent.height / 3 - 7

            Image
            {
                id:pont_charge
                anchors.fill: parent
                source: (pont_charge_button.text == "0V") ? "desk_ikoner/indicator_frameR.png" : "desk_ikoner/indicator_frame.png"
            }

            text: "0V"
//            Text {
//                id: bajs
//                objectName: "testing"
//                text: ""
//                color: "transparent"
//            }

            onTextChanged: if(pont_charge_button.text.charAt(pont_charge_button.text.length -1) != "V")
                           {
                            if(pont_charge_button.text.charAt(0) == "0")
                            {
                                pont_charge_button.text = pont_charge_button.text + "V"
                            }
                            else
                            {
                                pont_charge_button.text = pont_charge_button.text + "kV"
                            }
                           }
//            states:[
//            State {
//                name: "on"
//                PropertyChanges {
//                    target: pont_charge_button
//                    text:"16kV"

//                }
//                PropertyChanges {
//                    target: pont_charge
//                    source: "desk_ikoner/indicator_frame.png"

//                }

//            },
//                State {
//                    name: "off"
//                    PropertyChanges {
//                        target: pont_charge_button
//                        text: "0V"
//                    }
//                    PropertyChanges {
//                        target: pont_charge
//                        source: "desk_ikoner/indicator_frameR.png"
//                }
//             }
//            ]
        }
        //clickable pantograph down
        Button
        {
            id:pont_down_button
            objectName:  "pontograph_down"
            width: (pont_down_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(pont_down_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7
            Image
            {
                id:pont_down
                anchors.fill: parent
                source: "desk_ikoner/Down.png"
            }
            onClicked: buttonHandler.pontDownClicked()
            states:[
            State {
                name: "on"
                PropertyChanges {
                    target: pont_down
                    source: "desk_ikoner/DownY.png"

                }

            },
                State {
                    name: "off"
                    PropertyChanges {
                        target: pont_down
                        source:"desk_ikoner/Down.png"

                    }
                }
            ]

        }
        // non-clickable current indicator?
        Button
        {
            id:sp_button
            objectName: "sp"
            width: parent.width / 2 - 5

            height: parent.height / 3 - 7
            Image
            {
                id:sp
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "0-SP"

            states:[
            State {
                name: "warning"
             }
            ,
                State {
                    name: "off"
                    PropertyChanges {
                        target: spWarningAnimation
                        running : false


                    }
                }
            ]

            SequentialAnimation {
                            id: spWarningAnimation
                            objectName: "sp_animation"
                            running: false
                            loops: Animation.Infinite
                            PropertyAnimation {
                                target: sp
                                property: "source"
                                to: "desk_ikoner/yellow.png"
                                duration: MyConst.animation_duration
                            }

                            PropertyAnimation {
                                target: sp
                                property: "source"
                                to: "desk_ikoner/button69.png"
                                duration: MyConst.animation_duration
                            }
                        }


        }
        //clickable main breaker
        Button
        {
            id:h_bryt_button
            objectName: "h-bryt"
            width: (h_bryt_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(h_bryt_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7

            Image
            {
                id: h_bryt
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "H-BRYT"
            onClicked: buttonHandler.hBrytClicked()
            states:[
            State {
                name: "on"
                PropertyChanges {
                    target: h_bryt
                    source: "desk_ikoner/yellow.png"

                }

            },
                State {
                    name: "off"
                    PropertyChanges {
                        target: h_bryt
                        source:"desk_ikoner/button69.png"

                    }
                }
            ]

        }
        //clickable heating
        Button
        {
            id:tågv_button
            objectName: "heating"
            width: (tågv_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(tågv_button.pressed) ? parent.height / 3 - 12 : parent.height / 3 - 7

            Image
            {
                id:tågv
                anchors.fill: parent
                source: "desk_ikoner/button69.png"
            }
            text: "TÅGV."
            onClicked: buttonHandler.heatingClicked()
            states:[
            State {
                name: "on"
                PropertyChanges {
                    target: tågv
                    source: "desk_ikoner/yellow.png"

                }

            },
                State {
                    name: "off"
                    PropertyChanges {
                        target: tågv
                        source:"desk_ikoner/button69.png"

                    }
                }
            ]
        }
    }
}
