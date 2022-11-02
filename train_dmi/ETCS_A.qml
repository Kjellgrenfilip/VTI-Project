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
                text: qsTr("")
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
                    }
                },
                State {
                    name: "active"
                    PropertyChanges {
                        target: lssmaImage
                        source: "ETCS_icons/MO_21.bmp"
                    }
                }

            ]
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/10
            color:"red"
        }
        Rectangle
        {
            width:parent.width
            height: parent.height*(191/300)
            color:"purple"
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/12
            color:"white"
        }
    }
}
