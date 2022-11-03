import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "Imports" 1.0
Item {
    anchors.fill:parent
    Grid
    {
        id: grid
        anchors.fill:parent
        rows: 4
        columns: 1
        Rectangle
        {
            width:parent.width
            height: width
            objectName: "LSSMA"
            Image {
                id: lssmaImage
                anchors.fill: parent
                //anchors.verticalCenter: parent.verticalCenter
                //anchors.horizontalCenter: parent.horizontalCenter
                source: "ETCS_icons/MO_21.bmp"
            }
            Text {
                id: lssmaText
                objectName: "LSSMAText"
                text: qsTr("120")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color:MyConst.grey
            }
            states: [
                State {
                    name: "default"
                    PropertyChanges {
                        target: lssmaImage
                        source: ""
                    }
                    PropertyChanges {
                        target: lssmaText
                        text: ""
                        color: "transparent"
                    }
                },
                State {
                    name: "active"
                    PropertyChanges {
                        target: lssmaImage
                        source: "ETCS_icons/MO_21.bmp"
                    }
                    PropertyChanges {
                        target: lssmaText
                        color: MyConst.grey

                    }
                }

            ]
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/10
            objectName: "distance"
            color:"red"
            Text {
                id: distanceText
                objectName: "distanceText"
                text: qsTr("12345")
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                color: MyConst.grey
            }
            states: [
                State {
                    name: "default"
                    PropertyChanges {
                        target: distanceText
                        text:""
                        color: "transparent"
                    }
                },
                State {
                    name: "active"
                    PropertyChanges {
                        target: distanceText
                        color: MyConst.grey
                    }
                }
            ]

        }
        Rectangle
        {
            width:parent.width
            height: parent.height*(191/300)
            color: MyConst.backgroundColor
            objectName: "distanceBar"

            // 1000
            Rectangle
            {
                x: (12/54) * parent.width
                y: (-1/191) * parent.height
                width: (13/54) * parent.width
                height: (2/191) * parent.height
                color: MyConst.grey
            }
            // 900
            Rectangle
            {
                x: (16/54) * parent.width
                y: (6/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 800
            Rectangle
            {
                x: (16/54) * parent.width
                y: (13/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 700
            Rectangle
            {
                x: (16/54) * parent.width
                y: (22/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 600
            Rectangle
            {
                x: (16/54) * parent.width
                y: (32/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 500
            Rectangle
            {
                x: (12/54) * parent.width
                y: (45/191) * parent.height
                width: (13/54) * parent.width
                height: (2/191) * parent.height
                color: MyConst.grey
            }
            // 400
            Rectangle
            {
                x: (16/54) * parent.width
                y: (59/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 300
            Rectangle
            {
                x: (16/54) * parent.width
                y: (79/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 200
            Rectangle
            {
                x: (16/54) * parent.width
                y: (105/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 100
            Rectangle
            {
                x: (16/54) * parent.width
                y: (152/191) * parent.height
                width: (9/54) * parent.width
                height: (1/191) * parent.height
                color: MyConst.grey
            }
            // 0
            Rectangle
            {
                x: (12/54) * parent.width
                y: (185/191) * parent.height
                width: (13/54) * parent.width
                height: (2/191) * parent.height
                color: MyConst.grey
            }
            Rectangle
            {
                objectName: "distanceBarValue"
                property int barValue: 0
                x: (29/54) * parent.width
                y: (186/191) * parent.height
                width: (10/54) * parent.width
                height: (barValue/191) * parent.height
                anchors.bottom: parent.bottom
                anchors.margins: (5/191) * parent.height
                color: MyConst.grey
            }
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/12
            color:"white"
        }
    }
}
