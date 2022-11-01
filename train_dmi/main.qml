import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import "Imports" 1.0


Window {
    id: mainWindow
    visible: true
    minimumWidth: MyConst.windowWidth
    minimumHeight: MyConst.windowHeight
    color: MyConst.backgroundColor;

    onHeightChanged:
    {
        var properWidth = Math.round(height * (16/9));
        if ( width !== properWidth ) {
            width = properWidth
        }
    }

    onWidthChanged:
    {
        var properHeight = Math.round(width * (9/16));
        if ( height !== properHeight ) {
            height = properHeight
        }
    }

    title: qsTr("Train DMI")
    DESK_view{}
    ETCS_view{}
    ATC_view{}
}


