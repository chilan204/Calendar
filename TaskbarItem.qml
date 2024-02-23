import QtQuick 2.0

Item {
    id: root

    property string name
    property string nameImg
    property bool isCurrent: false
    signal clicked()

    Rectangle {
        id: highlightBar
        width: parent.width
        height: 3
        radius: highlightBar.height
        color: "turquoise"
        visible: root.isCurrent
    }

    Image {
        id: img
        source: "qrc:/Icon/" + root.nameImg + (root.isCurrent ? "_Highlight.png" : ".png")
        width: 45
        height: 45
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: highlightBar.bottom
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
