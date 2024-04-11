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
        width: 300
        height: 200
        radius: 20
        anchors.centerIn: parent
    }

    Rectangle {
        id: delButton
        width: 50
        height: 25
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
        width: 50
        height: 25
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            verticalCenter: delButton.verticalCenter
            left: delButton.right
            leftMargin: 30
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
        width: 50
        height: 25
        radius: 15
        color: "#C0C0C0"
        border.color: "black"
        anchors {
            verticalCenter: delButton.verticalCenter
            right: delButton.left
            rightMargin: 30
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

    Column {
        Text {
            text: '<b>Name:</b> ' + CTRL.getData(currentIndex).name
            font.pixelSize: 25
        }
        Text {
            text: '<b>Color:</b> ' + CTRL.getData(currentIndex).color
            font.pixelSize: 25
        }
        Text {
            text: '<b>Tuition:</b> ' + CTRL.getData(currentIndex).tuition
            font.pixelSize: 25
        }
        anchors {
            horizontalCenter: bg.horizontalCenter
            top: bg.top
            topMargin: 30
        }
    }
}
