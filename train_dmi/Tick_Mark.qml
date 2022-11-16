import QtQuick 2.0

Item
{
    property real alpha: 0
    property real length: 0
    property bool visibility: false
    property real speedValue: 0
    property real tickMarkNum: 0

    // Template for a tickmark
    Rectangle
    {
        id: tickMark
        height: length
        width: 1
        color: "lightgrey"
        antialiasing: true

        x: 125 * Math.cos(alpha * Math.PI / 180) + 125
        y: 125 * Math.sin(alpha * Math.PI / 180) + 125

        // Rotates the tickmark so that they point to the middle!
        transform: Rotation
        {
            origin.x: 0
            origin.y: 0
            angle: ((Math.atan2( (125 - tickMark.y) , (125 - tickMark.x) ) * 180 / (Math.PI) ) - 90)
        }
    }
    Text
    {
        id: speed
        text: speedValue.toString()
        color: "lightgrey"
        font.bold: true
        font.pointSize: 15
        visible: visibility
        x: 85 * Math.cos(alpha * Math.PI / 180) + 125
        y: 85 * Math.sin(alpha * Math.PI / 180) + 125
        transform: Translate
        {
            x: -10 - tickMarkNum*0.3
            y: -10
        }
    }
}
