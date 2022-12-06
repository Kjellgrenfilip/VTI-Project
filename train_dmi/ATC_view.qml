import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "Imports" 1.0

Item {
    anchors.fill: parent;
    visible: true;
    Frame{
        id: leftFrame;
        width: parent.width;
        height: parent.height/6;
        background: Rectangle{
            anchors.fill: parent;
            color: MyConst.backgroundColor;
        }
    }
}
