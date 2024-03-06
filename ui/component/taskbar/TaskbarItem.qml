import QtQuick 2.0

Item {
    id: root

    property string name
    property string sourceImg
    property bool isCurrent: false
    signal clicked()

    Image {
        id: img
        source: root.sourceImg
        width: 45
        height: 45
        opacity: root.isCurrent ? 1 : 0.5
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 5
        }
    }

    Text {
        text: root.name
        font.pixelSize: 15
        color: root.isCurrent ? "turquoise" : "black"
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: img.bottom
            topMargin: 5
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
