import QtQuick 2.0
import QtQuick.Controls 2.0
import "Imports" 1.0
import QtQuick.Controls 2.12

Item {
    anchors.fill: parent
    Grid
        {
            id: uppergrid
            height: (15/300) * parent.height
            width: parent.width
            anchors.top: parent.top
            columns: 3
            rows: 1
            Rectangle
            {
                id:d12
                height: parent.height
                width: (40/246) * parent.width
                color: "transparent"
                Button
                {
                    id: topSign
                    anchors.fill: parent
                    background:Rectangle { color:"transparent"}
                    Text
                    {
                        id: upperSign
                        text: qsTr("−")
                        color:  MyConst.grey
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize:(topSign.pressed) ? parent.height*2 - 15 : parent.height*2 - 10
                        font.weight: 1
                    }
                    onPressed: buttonHandler.scaleDownPressed(d1.scale)
                }

            }
            Rectangle
            {
                id:d13
                height: parent.height
                width: (166/246) * parent.width
                color: "transparent"
            }
            Rectangle
            {
                id:d14
                height: parent.height
                width: (40/246) * parent.width
                color: "transparent"
            }
        }
        Grid
        {
            id: middlegrid
            height: (270/300) * parent.height
            width: parent.width
            anchors.top: uppergrid.bottom
            columns: 8
            rows: 1
            Rectangle
            {
                id:d1
                objectName: "D1"
                width: (40/246) * parent.width
                height: parent.height
                color: "transparent"
                property int scale: 4000

                Text {
                    id: d1text1
                    text: d1.scale
                    width: parent.width
                    font.pointSize: parent.height/28
                    color: MyConst.mediumGrey
                    y:(0/270) * parent.height
                    horizontalAlignment: Text.AlignRight
                }
                Text {
                    id: d1text2
                    text: d1.scale/2
                    width:parent.width
                    font.pointSize: parent.height/28
                    color: MyConst.mediumGrey
                    y:(41/270) * parent.height
                    horizontalAlignment: Text.AlignRight
                }
                Text {
                    id: d1text3
                    text: d1.scale/4
                    width:parent.width
                    font.pointSize: parent.height/28
                    color: MyConst.mediumGrey
                    y:(84/270) * parent.height
                    horizontalAlignment: Text.AlignRight
                }
                Text {
                    id: d1text4
                    text: d1.scale/8
                    width:parent.width
                    font.pointSize: parent.height/28
                    color: MyConst.mediumGrey
                    y:(127/270) * parent.height
                    horizontalAlignment: Text.AlignRight
                }
                Text {
                    id: d1text5
                    text: qsTr("0")
                    width:parent.width
                    font.pointSize: parent.height/28
                    color: MyConst.mediumGrey
                    y:(261/270) * parent.height
                    horizontalAlignment: Text.AlignRight
                }
            }
            Rectangle
            {
                id:d2
                width: (25/246) * parent.width
                height: parent.height
                color: "transparent"
                Rectangle
                {
                    y:(6/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 2
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(49/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(92/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(135/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 2
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(149/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(167/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(191/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(235/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 1
                    color: MyConst.mediumGrey
                }
                Rectangle
                {
                    y:(268/270) * parent.height
                    width: (200/246) * middlegrid.width
                    height: 2
                    color: MyConst.mediumGrey
                }
            }
            Rectangle
            {
                id:d3
                width: (25/246) * parent.width
                height: parent.height
                color: "transparent"
            }
            Rectangle
            {
                id:d4
                width: (25/246) * parent.width
                height: parent.height
                color: "transparent"
            }
            Rectangle
            {
                id:d5
                objectName: "d5"
                width: (18/246) * parent.width
                height: parent.height
                color: "transparent"
                Rectangle
                {
                    id:d5bar1
                    objectName: "d5bar1"
                    anchors.bottom: parent.bottom
                    //anchors.margins: 2
                    width: parent.width
                    height: (barValue/262) * parent.height
                    ETCS_D_GradientEffect{}
                    property int barValue: 0
                    property string textValue: ""
                    property string lowerSign: ""
                    property string upperSign: ""
                    visible: false
                    Text {
                        objectName: "d5bar1text1"
                        text: d5bar1.textValue
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                    }
                    Text {
                        objectName: "d5bar1text2"
                        text: d5bar1.upperSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top

                    }
                    Text {
                        objectName: "d5bar1text3"
                        text: d5bar1.lowerSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom

                    }

                }
                Rectangle
                {
                    id:d5bar2
                    objectName: "d5bar2"
                    anchors.bottom: d5bar1.top
                    width: parent.width
                    height: (barValue/262) * parent.height
                    ETCS_D_GradientEffect{}
                    property int barValue: 0
                    property string textValue: ""
                    property string lowerSign: ""
                    property string upperSign: ""
                    visible: false
                    Text {
                        objectName: "d5bar2text1"
                        text: d5bar2.textValue
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        objectName: "d5bar2text2"
                        text: d5bar2.upperSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                    }
                    Text {
                        objectName: "d5bar2text3"
                        text: d5bar2.lowerSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                    }

                }
                Rectangle
                {
                    id:d5bar3
                    objectName: "d5bar3"
                    anchors.bottom: d5bar2.top
                    width: parent.width
                    height: (barValue/262) * parent.height
                    ETCS_D_GradientEffect{}
                    property int barValue: 0
                    property string textValue: ""
                    property string lowerSign: ""
                    property string upperSign: ""
                    visible: false
                    Text {
                        objectName: "d5bar3text1"
                       text: d5bar3.textValue
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        objectName: "d5bar3text2"
                        text: d5bar3.upperSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                    }
                    Text {
                        objectName: "d5bar3text3"
                        text: d5bar3.lowerSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                    }

                }
                Rectangle
                {
                    id:d5bar4
                    objectName: "d5bar4"
                    anchors.bottom: d5bar3.top
                    width: parent.width
                    height: (barValue/262) * parent.height
                    ETCS_D_GradientEffect{}
                    property int barValue: 0
                    property string textValue: ""
                    property string lowerSign: ""
                    property string upperSign: ""
                    visible: false
                    Text {
                        objectName: "d5bar4text1"
                        text: d5bar4.textValue
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        objectName: "d5bar4text2"
                        text: d5bar4.upperSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                    }
                    Text {
                        objectName: "d5bar4text3"
                        text: d5bar4.lowerSign
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                    }
                }


            }
            Rectangle
            {
                id:d6
                width: (14/246) * parent.width
                height: parent.height
                color: "transparent"
            }
            Rectangle
            {
                id:d7
               width: (93/246) * parent.width
               height: parent.height
               color: MyConst.paspDark
               objectName: "d7"
               z: -3

                   Rectangle
                   {
                       id: d7Collumn1
                       width: parent.width/4
                       height: parent.height
                       color: MyConst.paspLight
                       anchors.bottom: parent.bottom
                   }

                   Rectangle
                   {
                       id: d7Collumn2
                       x: parent.width/4
                       width: parent.width/4
                       height: parent.height*(3/4)
                       color: MyConst.paspLight
                       anchors.bottom: parent.bottom
                   }

                   Rectangle
                   {
                       id: d7Collumn3
                       x: parent.width/4 * 2
                       width: parent.width/4
                       height: parent.height/2
                       color: MyConst.paspLight
                       anchors.bottom: parent.bottom
                   }

                   Rectangle
                   {
                       id: d7Collumn4
                       x: parent.width/4 * 3
                       width: parent.width/4
                       height: parent.height*(1/4)
                       color: MyConst.paspLight
                       anchors.bottom: parent.bottom
                   }
                   Rectangle
                   {
                       id: indicationMarker
                       y: parent.height/4 * 3.5
                       height: 2
                       width: parent.width
                       color: MyConst.yellow
                   }

            }
            Rectangle
            {
                id:d8
                width: (6/246) * parent.width
                height: parent.height
                color: "transparent"
            }
        }
        Grid
        {
            id: lowergrid
            height: (15/300) * parent.height
            width: parent.width
            anchors.top: middlegrid.bottom
            Rectangle
            {
                id: d9
                height: parent.height
                width: (40/246) * parent.width
                color: "transparent"
                Button
                {
                    id: scaleUp
                    anchors.fill: parent
                    background:Rectangle { color:"transparent"}
                    Text
                    {
                        id: lowerSign
                        text: qsTr("+")
                        color:  MyConst.grey
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize:(scaleUp.pressed) ? parent.height - 5 : parent.height

                    }
                    onPressed:buttonHandler.scaleUpPressed(d1.scale)
                }

            }
            Rectangle
            {
                id: d10
                height: parent.height
                width: (166/246) * parent.width
                color: "transparent"
            }
            Rectangle
            {
                id: d11
                height: parent.height
                width: (40/246) * parent.width
                color: "transparent"
            }
        }


    Rectangle
    {
        color: "transparent"
        height: 20
        width: 40
        x: d6.x + 3
        //visible: false
        objectName: "PASP0"
        y: (d7.height - d7Collumn4.height)

        Image
        {
            id: image0
            source: "symbols/Planning/PL_21.png"
            anchors.left: parent.left
            height: 20
            width: 20
        }

        Text
        {
            id: text0
            text: qsTr("80")
            font.pointSize: 12
            anchors.left: image0.right
        }
    }

    Rectangle
    {
        color: "transparent"
        height: 20
        width: 30
        x: d6.x + 3
        //visible: false
        objectName: "PASP1"
        y: 0

        Image
        {
            id: image1
            source: "symbols/Planning/PL_21.png"
            anchors.left: parent.left
            height: 20
            width: 20
        }

        Text
        {
            id: text1
            text: qsTr("120")
            font.pointSize: 12
            anchors.left: image1.right
        }
    }

    Rectangle
    {
        color: "transparent"
        height: 20
        width: 30
        x: d6.x + 3
        //visible: false
        objectName: "PASP2"
        y: 0

        Image
        {
            id: image2
            source: "symbols/Planning/PL_21.png"
            anchors.left: parent.left
            height: 20
            width: 20
        }

        Text
        {
            id: text2
            text: qsTr("140")
            font.pointSize: 12
            anchors.left: image2.right
        }
    }

    Rectangle
    {
        color: "transparent"
        height: 20
        width: 30
        x: d6.x + 3
        //visible: false
        objectName: "PASP3"
        y: 0

        Image
        {
            id: image3
            source: "symbols/Planning/PL_21.png"
            anchors.left: parent.left
            height: 20
            width: 20
        }

        Text
        {
            id: text3
            text: qsTr("40")
            font.pointSize: 12
            anchors.left: image3.right
        }
    }

    Rectangle
    {
        color: "transparent"
        height: 20
        width: 30
        x: d6.x + 3
        //visible: false
        objectName: "PASP4"
        y: 0

        Image
        {
            id: image4
            source: "symbols/Planning/PL_21.png"
            anchors.left: parent.left
            height: 20
            width: 20
        }

        Text
        {
            id: text4
            text: qsTr("60")
            font.pointSize: 12
            anchors.left: image4.right
        }
    }
}
