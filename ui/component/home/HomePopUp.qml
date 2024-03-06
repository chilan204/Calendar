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

    ListView {
        id: listcolor
        width: list_model.count > 2 ? 280 : list_model.count * 80 + (list_model.count - 1) * 20
        height: 150
        anchors {
            horizontalCenter: bg.horizontalCenter
            top: bg.top
            topMargin: 20
        }

        clip: true
        interactive: list_model.count > 3
        orientation: ListView.Horizontal
        spacing: 20

        model: ListModel {
            id: list_model
            ListElement {
                color: "red"
                name: "HS1"
            }
            ListElement {
                color: "blue"
                name: "HS2"
            }
            ListElement {
                color: "yellow"
                name: "HS3"
            }
            ListElement {
                color: "green"
                name: "HS4"
            }
        }

        delegate: Rectangle {
            width: 80
            height: 80
            radius: 80
            opacity: 0.5
            border.color: "black"
            color: model.color

            MouseArea {
                anchors.fill: parent
                onClicked: parent.opacity = (parent.opacity == 1 ? 0.5 : 1)
            }

            Text {
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.bottom
                    topMargin: 10
                }
                text: model.name
                font.pixelSize: 15
                color: "black"
            }
        }
    }

    Rectangle {
        id: selectButton
        width: 70
        height: 30
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            horizontalCenter: bg.horizontalCenter
            horizontalCenterOffset: 60
            bottom: bg.bottom
            bottomMargin: 15
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
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
        id: cancelButton
        width: 70
        height: 30
        radius: 15
        color: "#C0C0C0"
        border.color: "black"
        anchors {
            horizontalCenter: bg.horizontalCenter
            horizontalCenterOffset: -60
            verticalCenter: selectButton.verticalCenter
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
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
