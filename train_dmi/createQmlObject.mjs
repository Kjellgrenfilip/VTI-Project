 function func() {
    const newObject = Qt.createQmlObject(`
        import QtQuick 2.0

        Rectangle {
            color: "red"
            width: 300
            height: 300
        }
        `,
        parentItem,
        "myDynamicSnippet"
    );
    return newObject;
}
