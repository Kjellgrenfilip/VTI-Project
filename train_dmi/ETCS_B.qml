import QtQuick 2.0
import QtQuick.Layouts 1.1
import "Imports" 1.0

Item
{
    id: etcsB
    anchors.fill: parent

    Speedometer{}
    Grid
    {
        id: grid
        columnSpacing: 0
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 14
        width: parent.width*0.9
        height: parent.height/8.333
        rows: 1
        columns: 7

        Rectangle
        {
            id: etcsB6
            width: parent.width/7
            height: parent.height
            color: MyConst.backgroundColor
            objectName: "etcsB6"

            Text
            {
                id: b6Text
                text: qsTr("25")
                color: MyConst.white
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: parent.height/1.8
            }

            ETCS_Box3DEffect{}

            states:
            [
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: b6Text
                        //visible: false
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: b6Text
                        text: qsTr("25")
                        visible: true
                    }
                }

            ]



        }

        Rectangle
        {
            id: etcsinactive0
            color: "transparent"
            width: parent.width/7
            height: parent.height
        }

        Rectangle
        {
            id: etcsB3
            objectName: "etcsB3"
            color: MyConst.backgroundColor
            width: parent.width/7
            height: parent.height

            Image
            {
                id: etcsB3Image
                objectName: "etcsB3Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            ETCS_Box3DEffect{}

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etcsB3Image
                        source: ""
                        visible: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etcsB3Image
                        source: ""
                        visible: true
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsB4
            objectName: "etcsB4"


            color: MyConst.backgroundColor
            width: parent.width/7
            height: parent.height

            Image
            {
                id: etcsB4Image
                objectName: "etcsB4Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            ETCS_Box3DEffect{}

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etcsB4Image
                        source: ""
                        visible: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etcsB4Image
                        source: ""
                        visible: true
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsB5
            objectName: "etcsB5"
            color: MyConst.backgroundColor
            width: parent.width/7
            height: parent.height

            Image
            {
                id: etcsB5Image
                objectName: "etcsB5Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            ETCS_Box3DEffect{}

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etcsB5Image
                        source: ""
                        visible: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etcsB5Image
                        source: ""
                        visible: true
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsinactive1
            color: "transparent"
            width: parent.width/7
            height: parent.height
        }

        Rectangle
        {
            id: etcsB7
            objectName: "etcsB7"
            color: MyConst.backgroundColor
            width: parent.width/7
            height: parent.height

            Image
            {
                id: etcsB7Image
                objectName: "etcsB7Image"
                source: "symbols/Mode/MO_09.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }

            ETCS_Box3DEffect{}

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etcsB7Image
                        source: "symbols/Mode/MO_09.bmp"
                        //visible: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etcsB7Image
                        source: ""
                        visible: true
                    }
                }
            ]
        }
    }
}
