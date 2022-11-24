import QtQuick 2.0

Item
{
    property real alpha: 0
    property real length: 0
    property bool visibility: false
    property real speedValue: 0
    property real tickMarkNum: 0

    property real tickWidth: 1
    property real placementRadius: 125
    property string tickmarkColor: "lightgrey"

    // Template for a tickmark
    Rectangle
    {
        id: tickMark
        height: length
        width: tickWidth
        color: tickmarkColor
        antialiasing: true
        radius: 0.5
        //Calculates the position of the tickmark
        //cos function takes Radians as parameter.
        x: placementRadius * Math.cos(alpha * Math.PI / 180) + 140
        y: placementRadius * Math.sin(alpha * Math.PI / 180) + 135

        // Rotates the tickmark so that they point to the middle!
        transform: Rotation
        {
            origin.x: 0
            origin.y: 0
            angle: ((Math.atan2( (140 - tickMark.y) , (140 - tickMark.x) ) * 180 / (Math.PI) ) - 90)
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
        x: 85 * Math.cos(alpha * Math.PI / 180) + 140
        y: 85 * Math.sin(alpha * Math.PI / 180) + 140
        transform: Translate
        {
            x: -10 - tickMarkNum*0.3
            y: -10
        }
    }
}
