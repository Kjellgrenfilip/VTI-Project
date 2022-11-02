import QtQuick 2.0
import QtQuick.Layouts 1.1

Item
{
    id: etcsB
    anchors.fill: parent

    RowLayout
    {
        id: etcsBRow
        spacing: 0
        anchors.bottom: parent.bottom
      //  anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.left: parent.left
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
        }
        Rectangle
        {
            id: etcsB4
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "yellow"
        }
        Rectangle
        {
            id: etcsB5
            Layout.minimumHeight: 36
            Layout.minimumWidth: 36
            color: "blue"
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
            color: "yellow"
        }
    }
}
