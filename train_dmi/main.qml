import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import "Imports" 1.0

Window {
    id: mainWindow
    visible: true
    width: MyConst.window_width
    height: MyConst.window_height


    title: qsTr("Hello World")
    DESK_view{}
    ETCS_view{}
    ATC_view{}
}


