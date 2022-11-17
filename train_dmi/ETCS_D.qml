import QtQuick 2.0

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
            height: parent.height
            width: (40/246) * parent.width
            color: "orange"
        }
        Rectangle
        {
            height: parent.height
            width: (166/246) * parent.width
            color: "blue"
        }
        Rectangle
        {
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
            width: (40/246) * parent.width
            height: parent.height
            color: "red"
        }
        Rectangle
        {
            width: (25/246) * parent.width
            height: parent.height
            color: "brown"
        }
        Rectangle
        {
            width: (25/246) * parent.width
            height: parent.height
            color: "red"
        }
        Rectangle
        {
            width: (25/246) * parent.width
            height: parent.height
            color: "brown"
        }
        Rectangle
        {
            width: (18/246) * parent.width
            height: parent.height
            color: "red"
        }
        Rectangle
        {
            width: (14/246) * parent.width
            height: parent.height
            color: "brown"
        }
        Rectangle
        {
            width: (93/246) * parent.width
            height: parent.height
            color: "red"
        }
        Rectangle
        {
            width: (6/246) * parent.width
            height: parent.height
            color: "brown"
        }
    }
    Grid
    {
        height: (15/300) * parent.height
        width: parent.width
        anchors.top: middlegrid.bottom
        Rectangle
        {
            height: parent.height
            width: (40/246) * parent.width
            color: "orange"
        }
        Rectangle
        {
            height: parent.height
            width: (166/246) * parent.width
            color: "blue"
        }
        Rectangle
        {
            height: parent.height
            width: (40/246) * parent.width
            color: "yellow"
        }
    }
}
