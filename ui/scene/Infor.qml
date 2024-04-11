import QtQuick 2.0
import "../component/infor"

Item {
    id: root
    anchors.fill: parent

    property int currentIndex

    Text {
        id: title
        text: qsTr("Thông tin học sinh")
        font.pixelSize: 35
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
    }

    ListView {
        id: listStudent
        width: 350
        height: 350
        clip: true
        spacing: 25
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: title.bottom
            topMargin: 30
        }

        model: CTRL.getLength()

        delegate: Rectangle {
            width: 350
            height: 100
            radius: 20
            border.color: "black"

            MouseArea {
                anchors.fill: parent
                onPressed: parent.scale = 0.95
                onReleased: parent.scale = 1
                onClicked: {
                    popup.visible = true
                    currentIndex = index
                }
            }

            Column {
                Text {
                    text: '<b>Name:</b> ' + CTRL.getData(index).name
                    font.pixelSize: 15
                }
                Text {
                    text: '<b>Color:</b> ' + CTRL.getData(index).color
                    font.pixelSize: 15
                }
                Text {
                    text: '<b>Tuition:</b> ' + CTRL.getData(index).tuition
                    font.pixelSize: 15
                }
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 30
                }
            }
        }
    }

    Rectangle {
        id: newButton
        width: 70
        height: 30
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: {
                popup.visible = !popup.visible
                CTRL.addSV("D","Green",200000)
            }
        }

        Text {
            anchors.centerIn: parent
            text: "Thêm"
            font.pixelSize: 15
        }
    }

    InforPopUp {
        id: popup
        anchors.fill: parent
        visible: false
    }
}
