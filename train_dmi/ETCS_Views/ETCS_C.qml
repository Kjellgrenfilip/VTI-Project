import QtQuick 2.0
import QtQuick.Controls 2.12
import "../Imports" 1.0

Item {
    id: etcsC
    anchors.fill: parent
    width: parent.width
    height: parent.height

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
            width: parent.width/6.185
            height: parent.height
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}

            Rectangle
            {
                id: c8
                anchors.top: parent.top
                width: parent.width
                height: parent.height/2
                color: MyConst.backgroundColor

                ETCS_Box3DEffect{}
            }

            Rectangle
            {
                id: c9
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height/2
                color: MyConst.backgroundColor

                ETCS_Box3DEffect{}
            }
        }
        Rectangle
        {
            id: c234
            width: parent.width/3
            height: parent.height
            color: MyConst.backgroundColor

            Grid
            {
                id: grid2
                width: parent.width
                height: parent.height

                Rectangle
                {
                    id: c2
                    width: parent.width/3
                    height: parent.height
                    color: MyConst.backgroundColor

                }

                Rectangle
                {
                    id: c3
                    width: parent.width/3
                    height: parent.height
                    color: MyConst.backgroundColor

                    Text
                    {
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
                    width: parent.width/3
                    height: parent.height
                    color: MyConst.backgroundColor
                }
            }

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c1
            objectName: "etcsC1"
            width: parent.width/5.758
            height: parent.height
            color: MyConst.backgroundColor

            SequentialAnimation on color
            {
                running: false
                id: c1Animation
                objectName: "etcsC1Animation"
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
            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: c1Animation
                        running: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: c1Animation
                        running: true
                    }
                }

            ]

            Button
            {
                id: c1Button
                width:  parent.width
                height: parent.height
                anchors.fill: parent
                anchors.margins: 4
                hoverEnabled: false

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
                    objectName: "etcsC1Image"
                    source: "../symbols/Level/LE_03.bmp"
                    anchors.fill: parent
                }
            }
            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c5
            width: parent.width/9
            height: parent.height
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c6
            objectName: "etcsC6"
            width: parent.width/9
            height: parent.height
            color: MyConst.backgroundColor

            Image
            {
                id: c6Image
                anchors.fill: parent
                anchors.margins: 2
                source: "../symbols/Status/ST_06.bmp"
            }

            states:
            [
                State
                {
                    name: "inactive"
                    PropertyChanges
                    {
                        target: c6Image
                        visible: false
                    }
                },
                State
                {
                    name: "active"
                    PropertyChanges
                    {
                        target: c6Image
                        visible: true
                    }
                }

            ]

            ETCS_Box3DEffect{}
        }

        Rectangle
        {
            id: c7
            width: parent.width/9
            height: parent.height
            color: MyConst.backgroundColor

            ETCS_Box3DEffect{}
        }
    }
}
