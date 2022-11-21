import QtQuick 2.0
import "Imports" 1.0
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
            color: "orange"
        }
        Rectangle
        {
            id:d13
            height: parent.height
            width: (166/246) * parent.width
            color: "blue"
        }
        Rectangle
        {
            id:d14
            height: parent.height
            width: (40/246) * parent.width
            color: "yellow"
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
            width: (40/246) * parent.width
            height: parent.height
            color: "red"
            property int scale: 4000

            Text {
                id: d1text1
                text: d1.scale
                width:parent.width
                color: MyConst.grey
                y:(0/270) * parent.height
                horizontalAlignment: Text.AlignRight
            }
            Text {
                id: d1text2
                text: d1.scale/2
                width:parent.width
                color: MyConst.grey
                y:(40/270) * parent.height
                horizontalAlignment: Text.AlignRight
            }
            Text {
                id: d1text3
                text: d1.scale/4
                width:parent.width
                color: MyConst.grey
                y:(83/270) * parent.height
                horizontalAlignment: Text.AlignRight
            }
            Text {
                id: d1text4
                text: d1.scale/8
                width:parent.width
                color: MyConst.grey
                y:(126/270) * parent.height
                horizontalAlignment: Text.AlignRight
            }
            Text {
                id: d1text5
                text: qsTr("0")
                width:parent.width
                color: MyConst.grey
                y:(260/270) * parent.height
                horizontalAlignment: Text.AlignRight
            }
        }
        Rectangle
        {
            id:d2
            width: (25/246) * parent.width
            height: parent.height
            color: "brown"
            Rectangle
            {
                y:(6/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 2
                color: MyConst.grey
            }
            Rectangle
            {
                y:(49/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(92/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(135/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 2
                color: MyConst.grey
            }
            Rectangle
            {
                y:(149/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(167/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(191/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(235/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 1
                color: MyConst.grey
            }
            Rectangle
            {
                y:(268/270) * parent.height
                width: (200/246) * middlegrid.width
                height: 2
                color: MyConst.grey
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
            width: (18/246) * parent.width
            height: parent.height
            color: "transparent"
            Rectangle
            {
                id:d5bar1
                objectName: "d5bar1"
                anchors.bottom: parent.anchors.bottom
                width: parent.width
                property int barValue: 0
                property int textValue: 0
                height: barvalue
            }
            Rectangle
            {
                id:d5bar2
                objectName: "d5bar2"
                anchors.bottom: d5bar1.anchors.top
                width: parent.width
                property int barValue: 0
                property int textValue: 0
                height: barvalue
            }
            Rectangle
            {
                id:d5bar3
                objectName: "d5bar3"
                anchors.bottom: d5bar2.anchors.bottom
                width: parent.width
                property int barValue: 0
                property int textValue: 0
                height: barvalue
            }
            Rectangle
            {
                id:d5bar4
                objectName: "d5bar4"
                anchors.bottom: d5bar3.anchors.top
                width: parent.width
                property int barValue: 0
                property int textValue: 0
                height: barvalue
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
            color: "transparent"
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
        height: (15/300) * parent.height
        width: parent.width
        anchors.top: middlegrid.bottom
        Rectangle
        {
            id: d9
            height: parent.height
            width: (40/246) * parent.width
            color: "orange"
        }
        Rectangle
        {
            id: d10
            height: parent.height
            width: (166/246) * parent.width
            color: "blue"
        }
        Rectangle
        {
            id: d11
            height: parent.height
            width: (40/246) * parent.width
            color: "yellow"
        }
    }
}
