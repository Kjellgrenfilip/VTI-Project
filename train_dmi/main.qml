import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
//import "Constants.qml"

Window {
    id: mainWindow
    visible: true
    width: Constants.WIDTH
    height: Constants.HEIGHT
    minimumHeight:720
    minimumWidth: 1280
    title: qsTr("Hello World")
    DESK_view{}
    ETCS_view{}
    ATC_view{}
}


