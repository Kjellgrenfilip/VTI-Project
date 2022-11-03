import QtQuick 2.0
import QtQuick.Layouts 1.1
import "Imports" 1.0

Item
{
    id: etcsB
    anchors.fill: parent

    RowLayout
    {
        id: etcsBRow
        spacing: 0
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
       // anchors.right: parent.right
       // anchors.left: parent.left
        //anchors.verticalCenter: parent.verticalCenter
        anchors.margins: parent.height/50

        Rectangle
        {
            id: etcsB6
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36

            ETCS_Box3DEffect{}

            Text
            {
                id: b6Text
                text: qsTr("25")
                color: MyConst.white
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }





            /*Image
            {
                id: etscB6Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }*/
        }

        Rectangle
        {
            id: etcsinactive0
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
        }

        Rectangle
        {
            id: etcsB3
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            objectName: "etcsB3"

            ETCS_Box3DEffect{}

            Image
            {
                id: etscB3Image
                objectName: "etcsB3Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etscB3Image
                        source: ""
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etscB3Image
                        source: ""
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsB4
            objectName: "etcsB4"
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36

            ETCS_Box3DEffect{}

            Image
            {
                id: etscB4Image
                objectName: "etcsB4Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etscB4Image
                        source: ""
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etscB4Image
                        //source: ""
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsB5
            objectName: "etcsB5"
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36

            ETCS_Box3DEffect{}

            Image
            {
                id: etscB5Image
                objectName: "etscB5Image"
                source: ""
                anchors.fill: parent
                anchors.margins: 2
            }

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etscB5Image
                        source: ""
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etscB5Image
                        source: ""
                    }
                }
            ]
        }

        Rectangle
        {
            id: etcsinactive1
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
        }

        Rectangle
        {
            id: etcsB7
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36

            ETCS_Box3DEffect{}

            Image
            {
                id: etscB7Image
                source: "symbols/Mode/MO_09.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: etscB3Image
                        source: ""
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: etscB3Image
                        source: "symbols/Mode/MO_09.bmp"
                    }
                }
            ]
        }
    }
}
