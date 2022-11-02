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
            Text
            {
                id: b6Text
                text: qsTr("25")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            Image
            {
                id: etscB6Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }
            Rectangle
            {
                id: etcsB6Top
                color: MyConst.black
                anchors.top: parent.top
                width: parent.width
                height: 2
            }
            Rectangle
            {
                id: etcsB6Left
                color: MyConst.black
                anchors.left: parent.left
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB6Right
                color: MyConst.shadow
                anchors.right: parent.right
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB6Bottom
                color: MyConst.shadow
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
            }

        }
        Rectangle
        {
            id: etcsEmpty0
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
        }
        Rectangle
        {
            id: etcsB3
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "blue"

            Image
            {
                id: etscB3Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }

            Rectangle
            {
                id: etcsB3Top
                color: MyConst.black
                anchors.top: parent.top
                width: parent.width
                height: 2
            }
            Rectangle
            {
                id: etcsB3Left
                color: MyConst.black
                anchors.left: parent.left
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB3Right
                color: MyConst.shadow
                anchors.right: parent.right
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB3Bottom
                color: MyConst.shadow
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
            }

            states:
            [
                State
                {
                    PropertyChanges
                    {
                        target: etscB3Image
                        source: "symbols/TC_01.bmp"
                    }

                }
            ]
        }

        Rectangle
        {
            id: etcsB4
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "yellow"

            Image
            {
                id: etscB4Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }
            Rectangle
            {
                id: etcsB4Top
                color: MyConst.black
                anchors.top: parent.top
                width: parent.width
                height: 2
            }
            Rectangle
            {
                id: etcsB4Left
                color: MyConst.black
                anchors.left: parent.left
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB4Right
                color: MyConst.shadow
                anchors.right: parent.right
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB4Bottom
                color: MyConst.shadow
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
            }
        }

        Rectangle
        {
            id: etcsB5
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "blue"

            Image
            {
                id: etscB5Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }
            Rectangle
            {
                id: etcsB5Top
                color: MyConst.black
                anchors.top: parent.top
                width: parent.width
                height: 2
            }
            Rectangle
            {
                id: etcsB5Left
                color: MyConst.black
                anchors.left: parent.left
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB5Right
                color: MyConst.shadow
                anchors.right: parent.right
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB5Bottom
                color: MyConst.shadow
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
            }
        }
        Rectangle
        {
            id: etcsEmpty1
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "transparent"
        }
        Rectangle
        {
            id: etcsB7
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            //color: "yellow"
            Image
            {
                id: etscB7Image
                source: "symbols/Mode/MO_01.bmp"
                anchors.fill: parent
                anchors.margins: 2
            }
            Rectangle
            {
                id: etcsB7Top
                color: MyConst.black
                anchors.top: parent.top
                width: parent.width
                height: 2
            }
            Rectangle
            {
                id: etcsB7Left
                color: MyConst.black
                anchors.left: parent.left
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB7Right
                color: MyConst.shadow
                anchors.right: parent.right
                height: parent.height
                width: 2
            }
            Rectangle
            {
                id: etcsB7Bottom
                color: MyConst.shadow
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
            }




        }
    }
}
