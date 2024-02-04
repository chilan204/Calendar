import QtQuick 2.0

Item {
    id: root
    width: 450
    height: 150

    Rectangle {
        id: option_1
        width: 80
        height: 80
        radius: 20
        border.color: "black"
        color: "white"
        anchors{
            verticalCenter: root.verticalCenter
            left: root.left
            leftMargin: (root.width - 4 * option_1.width) / 5
        }
    }

    Rectangle {
        id: option_2
        width: 80
        height: 80
        radius: 20
        border.color: "black"
        color: "white"
        anchors{
            verticalCenter: root.verticalCenter
            left: option_1.right
            leftMargin: (root.width - 4 * option_1.width) / 5
        }
    }

    Rectangle {
        id: option_3
        width: 80
        height: 80
        radius: 20
        border.color: "black"
        color: "white"
        anchors{
            verticalCenter: root.verticalCenter
            left: option_2.right
            leftMargin: (root.width - 4 * option_1.width) / 5
        }
    }

    Rectangle {
        id: option_4
        width: 80
        height: 80
        radius: 20
        border.color: "black"
        color: "white"
        anchors{
            verticalCenter: root.verticalCenter
            left: option_3.right
            leftMargin: (root.width - 4 * option_1.width) / 5
        }
    }
}
