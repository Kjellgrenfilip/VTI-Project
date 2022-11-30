import QtQuick 2.0
import QtQml 2.0

Item {
    id: pasp
    objectName: "pasp"
    anchors.fill: parent
    height: 300
    width: 300
    z: 50

   function createPASPImage()
    {
        console.log("hello");
        var component = Qt.createComponent("PASPImage.qml");
        if (component.status == Component.Ready)
        {
            var image = component.createObject(pasp);

        }
    }

   //Component.onCompleted: createPASPImage()

   Connections
   {
       target: dmi_handler
       onCreatePaspImage: {
         createPASPImage()
       }
   }

   Loader
   {
       id: paspLoader
       source: "PASPImage.qml"
   }

    Rectangle
    {
        anchors.fill: parent
        objectName: "speed"
        color: "red"

        Image
        {
            id: image
            source: "symbols/Planning/PL_21.png"
            anchors.fill: parent
        }

        Text
        {
            id: text
            text: qsTr("text")
        }
    }
}
