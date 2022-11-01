import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "Imports" 1.0
Item {
    anchors.fill:parent
    Grid
    {
        id: grid
        anchors.fill:parent
        rows: 4
        columns: 1
        Rectangle
        {
            width:parent.width
            height: width
            color:"blue"
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/10
            color:"red"
        }
        Rectangle
        {
            width:parent.width
            height: parent.height*(191/300)
            color:"purple"
        }
        Rectangle
        {
            width:parent.width
            height: parent.height/12
            color:"white"
        }
    }
}
