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
        anchors.margins: parent.height/50
        width:  36*7/parent.width
        height: 36*parent.height

        Rectangle
        {
            id: etcsB6
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36

            width: parent.width
            height: parent.height
            color: MyConst.backgroundColor
            objectName: "etcsB6"


            ETCS_Box3DEffect{}

            Text
            {
                id: b6Text
                text: qsTr("25")
                color: MyConst.white
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            states :
            [
                State
                {
                    name: "inactive";
                    PropertyChanges
                    {
                        target: b6Text
                        visible: false
                    }
                },
                State
                {
                    name: "active";
                    PropertyChanges
                    {
                        target: b6Text
                        visible: true
                    }
                }

            ]



        }

        Rectangle
        {
            id: etcsinactive0
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
            width: parent.width
            height: parent.height
        }

        Rectangle
        {
            id: etcsB3
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            objectName: "etcsB3"
            color: MyConst.backgroundColor
            width: parent.width
            height: parent.height

            ETCS_Box3DEffect{}

            Image
            {
                id: etcsB3Image
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
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: MyConst.backgroundColor
            width: parent.width
            height: parent.height

            ETCS_Box3DEffect{}

            Image
            {
                id: etcsB4Image
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
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: MyConst.backgroundColor
            width: parent.width
            height: parent.height

            ETCS_Box3DEffect{}

            Image
            {
                id: etcsB5Image
                objectName: "etcsB5Image"
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
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
            width: parent.width
            height: parent.height
        }

        Rectangle
        {
            id: etcsB7
            objectName: "etcsB7"
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: MyConst.backgroundColor
            width: parent.width
            height: parent.height

            ETCS_Box3DEffect{}

            Image
            {
                id: etcsB7Image
                objectName: "etcsB7Image"
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
                        target: etcsB7Image
                        source: ""
                        visible: false
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
