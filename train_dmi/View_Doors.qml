import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0

Item {
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
        color: "#041122"
        Text
        {
            id: name
            text: qsTr("DÖRRAR")
            font.pointSize: doors.width / 25 // gives warning
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Grid
    {
        id: grid_doors
        spacing: 10
        transformOrigin: Item.Center
        anchors.fill:parent
        anchors.left: parent.right
        rows: 2
        columns: 2
        anchors.margins: 30
        Button
        {
            id: door_left_button
            objectName: "door_left_button"
            width: (door_left_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(door_left_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5

            onPressed: buttonHandler.leftDoorClicked()
            Image
            {

                id: door_left_image
                anchors.fill: parent
                source: "desk_ikoner/doorleft.png"
            }

            SequentialAnimation {
                id: door_left_animation
                objectName: "door_left_button_animation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation {
                    target: door_left_image
                    property: "source"
                    to: "desk_ikoner/doorleftY.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: door_left_image
                    property: "source"
                    to: "desk_ikoner/doorleft.png"
                    duration: MyConst.animation_duration
                }
            }
            states: [
                 State {
                     name: "warning";
                     PropertyChanges {
                         target: door_left_image
                         source: "desk_ikoner/doorleftY.png"
                     }


                    },
                 State {
                     name: "inactive";
                     PropertyChanges {
                         target: door_left_image
                         source: "desk_ikoner/doorleft.png"
                     }
                     PropertyChanges {
                         target: door_left_animation
                         running: false
                     }
                 }
             ]
        }
        Button
        {
            id:door_right_button
            objectName: "door_right_button"
            width: (door_right_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(door_right_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id:door_right_image
                anchors.fill: parent
                source: "desk_ikoner/doorright.png"
            }

            onPressed: buttonHandler.rightDoorClicked()

            SequentialAnimation {
                id: door_right_animation
                objectName: "door_right_button_animation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation {
                    target: door_right_image
                    property: "source"
                    to: "desk_ikoner/doorrightY.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: door_right_image
                    property: "source"
                    to: "desk_ikoner/doorright.png"
                    duration: MyConst.animation_duration
                }
            }
            states: [
                 State {
                     name: "warning";
                     PropertyChanges {
                         target: door_right_image
                         source: "desk_ikoner/doorrightY.png"
                     }


                    },
                 State {
                     name: "inactive";
                     PropertyChanges {
                         target: door_right_image
                         source: "desk_ikoner/doorright.png"
                     }
                     PropertyChanges {
                         target: door_right_animation
                         running: false
                     }
                 }
             ]
        }
        Button
        {
            id:departure_button
            objectName: "departure_button"
            width: (departure_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(departure_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {

                id: departure_image
                anchors.fill: parent
                source: "desk_ikoner/avgang.png"
            }

            onPressed: buttonHandler.departureButtonClicked()

            SequentialAnimation {
                id: departure_animation
                objectName: "departure_button_animation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation {
                    target: departure_image
                    property: "source"
                    to: "desk_ikoner/green.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: departure_image
                    property: "source"
                    to: "desk_ikoner/avgang.png"
                    duration: MyConst.animation_duration
                }
            }
            states: [
                 State {
                     name: "warning";
                     PropertyChanges {
                         target: departure_image
                         source: "desk_ikoner/green.png"
                     }

                    },
                 State {
                     name: "inactive";
                     PropertyChanges {
                         target: departure_image
                         source: "desk_ikoner/avgang.png"
                     }
                     PropertyChanges {
                         target: departure_animation
                         running: false
                     }
                 }
             ]
        }
        Button
        {
            id:closed_button
            objectName: "door_close_button"
            width: (closed_button.pressed) ? parent.width / 2 -10 : parent.width / 2 - 5
            height:(closed_button.pressed) ? parent.height / 2 - 10 : parent.height / 2 - 5
            Image
            {
                id: closed_image
                anchors.fill: parent
                source: "desk_ikoner/closedG.png"
            }
            onPressed: buttonHandler.closeDoorClicked()

            SequentialAnimation {
                id: door_close_button_animation
                objectName: "door_close_button_animation"
                running: false
                loops: Animation.Infinite
                PropertyAnimation {
                    target: closed_image
                    property: "source"
                    to: "desk_ikoner/closedG.png"
                    duration: MyConst.animation_duration
                }

                PropertyAnimation {
                    target: closed_image
                    property: "source"
                    to: "desk_ikoner/closed.png"
                    duration: MyConst.animation_duration
                }
            }

               states: [
                    State {
                        name: "active"
                        PropertyChanges {
                            target: closed_image
                            source: "desk_ikoner/closedG.png"
                        }
                        PropertyChanges {
                            target: door_close_button_animation
                            running: false
                        }

                       },
                    State {
                        name: "inactive";
                        PropertyChanges {
                            target: closed_image
                            source: "desk_ikoner/closed.png"
                        }
                        PropertyChanges {
                            target: door_close_button_animation
                            running: false
                        }
                    },
                   State {
                       name: "warning"
                       PropertyChanges {
                           target: closed_image
                           source: "desk_ikoner/closedG.png"

                       }
                   }
                ]
        }

    }
}
