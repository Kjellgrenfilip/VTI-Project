import QtQuick 2.0
import QtQuick.Controls 2.12
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
            id: c1234
            width: 37*3
            height: 50
            color: MyConst.backgroundColor

            Grid
            {
                id: grid2
                width: parent.width
                height: parent.height

                Rectangle
                {
                    id: c2
                    width: 37
                    height: 50
                    color: MyConst.backgroundColor

                }

                Rectangle
                {
                    id: c3
                    width: 37
                    height: 50
                    color: MyConst.backgroundColor

                    Text {
                        id: c3Text
                        objectName: "etcsC3Text"
                        text: qsTr("1000")
                        anchors.verticalCenter: parent.verticalCenter
                        color: MyConst.white
                    }
                }

                Rectangle
                {
                    id: c4
                    width: 37
                    height: 50
                    color: MyConst.backgroundColor


                }


            }

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c1
            objectName: "c1"
            width: 58
            height: 50
            color: MyConst.backgroundColor

            SequentialAnimation on color
            {
                running: true
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

            Button
            {
                id: c1Button
                width:  parent.width
                height: parent.height
                anchors.fill: parent
                anchors.margins: 4
                background: Rectangle
                {
                    color: "transparent"
                }

                onPressed: {
                    c1Image.source = ""
                    c1Animation.running = false
                    c1.color = "transparent"
                    buttonHandler.etcsC1Pressed();
                }

                Image
                {
                    id: c1Image
                    obejctName: "etcsC1Image"
                    source: "symbols/Level/LE_07.bmp"
                    anchors.fill: parent
                }
            }
            ETCS_Box3DEffect{}
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
