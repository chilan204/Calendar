import QtQuick 2.0

Item {
    id: root
    width: 450
    height: 150

    Button {
        id: button_1
        anchors {
            verticalCenter: root.verticalCenter
            left: root.left
            leftMargin: (root.width - 4 * button_1.width) / 5
        }

        Text {
            text: "option 1"
            font.pixelSize: 15
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
            }
        }
    }

    Button {
        id: button_2
        anchors {
            top: button_1.top
            left: button_1.right
            leftMargin: (root.width - 4 * button_1.width) / 5
        }

        Text {
            text: "option 2"
            font.pixelSize: 15
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
            }
        }
    }

    Button {
        id: button_3
        anchors {
            top: button_1.top
            left: button_2.right
            leftMargin: (root.width - 4 * button_1.width) / 5
        }

        Text {
            text: "option 3"
            font.pixelSize: 15
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
            }
        }
    }

    Button {
        id: button_4
        anchors {
            top: button_1.top
            left: button_3.right
            leftMargin: (root.width - 4 * button_1.width) / 5
        }

        Text {
            text: "option 4"
            font.pixelSize: 15
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
            }
        }
    }
}
