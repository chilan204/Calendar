import QtQuick 2.0

Item {
    id: root
    width: 75
    height: 360
    Rectangle {
        anchors.fill: parent
        color: "gray"
        opacity: 0.5
    }

    property string nameStudent
    property string colorStudent

    Text {
        id: name
        font.pixelSize: 20
        text: root.nameStudent
        anchors {
            horizontalCenter: rec.horizontalCenter
            bottom: parent.bottom
        }
    }

    Rectangle {
        id: rec
        width: 50
        height: 300 //40*workingday
        border.color: "black"
        color: colorStudent
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: name.top
            bottomMargin: 5
        }
    }

    Text {
        id: day
        font.pixelSize: 20
        text: "5"
        anchors {
            horizontalCenter: rec.horizontalCenter
            bottom:  rec.top
            bottomMargin: 5
        }
    }
}
