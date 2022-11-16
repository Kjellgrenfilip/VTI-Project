import QtQuick 2.0
import "Imports" 1.0

Item {
    id: etcsC
    anchors.fill: parent
    Grid
    {
        anchors.fill: parent
        columns: 8
        rows: 1
        width: parent.width
        height: parent.height

        Rectangle
        {
            id: c89
            width: 54
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
            Rectangle
            {
                id: c8
                anchors.top: parent.top
                width: 54
                height: 25
                color: MyConst.backgroundColor

                ETCS_Box3DEffect{}
            }

            Rectangle
            {
                id: c9
                anchors.bottom: parent.bottom
                width: 54
                height: 25
                color: MyConst.backgroundColor

                ETCS_Box3DEffect{}
            }
        }

        Rectangle
        {
            id: c2
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }
        Rectangle
        {
            id: c3
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c4
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c1
            width: 58
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}


            SequentialAnimation on color
            {
              //  running: true
                id: c1Animation
                loops: Animation.Infinite
                ColorAnimation
                {
                    from : MyConst.backgroundColor
                    to: MyConst.yellow
                    duration: 200
                }
                ColorAnimation
                {
                    from: MyConst.yellow
                    to: MyConst.backgroundColor
                    duration: 200
                }
            }
            Image
            {
                id: c1Image
                source: "symbols/Level/LE_07.bmp"
                anchors.fill: parent
                anchors.margins: 4
                MouseArea
                {
                    width: parent.width
                    height: parent.height
                    anchors.fill: parent
                    onClicked: console.log("clicked")
                 /*   {
                        c1Animation.running = false;

                        enabled: false
                    }*/

                }
            }


        }

        Rectangle
        {
            id: c5
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c6
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c7
            width: 37
            height: 50
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }
    }
}
