import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.2
    }

    Rectangle {
        id: bg
        width: 400
        height: 400
        radius: 20
        anchors.centerIn: parent
    }

    Rectangle {
        id: delButton
        width: 70
        height: 30
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            horizontalCenter: bg.horizontalCenter
            bottom: bg.bottom
            bottomMargin: 20
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: root.visible = false
        }

        Text {
            anchors.centerIn: parent
            text: "Xóa"
            font.pixelSize: 15
        }
    }

    Rectangle {
        id: saveButton
        width: 70
        height: 30
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            verticalCenter: delButton.verticalCenter
            left: delButton.right
            leftMargin: 50
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: root.visible = false
        }

        Text {
            anchors.centerIn: parent
            text: "Lưu"
            font.pixelSize: 15

        }
    }

    Rectangle {
        width: 70
        height: 30
        radius: 15
        color: "#C0C0C0"
        border.color: "black"
        anchors {
            verticalCenter: delButton.verticalCenter
            right: delButton.left
            rightMargin: 50
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: root.visible = false
        }

        Text {
            anchors.centerIn: parent
            text: "Hủy"
            font.pixelSize: 15
        }
    }
}
