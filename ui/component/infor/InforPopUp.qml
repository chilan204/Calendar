import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent

    property string name
    property string color
    property string tuition
    property int index
    property bool isAdd

    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.2
        MouseArea{
            anchors.fill: parent
        }
    }

    Rectangle {
        id: bg
        width: 300
        height: 230
        radius: 20
        anchors.centerIn: parent
    }

    Column {
        anchors {
            horizontalCenter: bg.horizontalCenter
            top: bg.top
            topMargin: 25
        }
        spacing: 10
        Repeater {
            id: repeater
            model: 3
            Rectangle {
                property alias textInput: input.text
                width: 250
                height: 35
                border.color: "black"
                TextInput {
                    id: input
                    anchors {
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 10
                    }
                    font.pixelSize: 15
                    width: 200
                    clip: true
                    text: (index == 0 ? root.name : (index == 1 ? root.color : root.tuition))
                }
                Text {
                    anchors {
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 10
                    }
                    font.pixelSize: 15
                    text: (index == 0 ? "Name" : (index == 1 ? "Color" : "Tuition"))
                    opacity: 0.6
                    visible: input.text == ""
                }
            }
        }
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
            onClicked: {
                root.visible = false
                SV_MODEL.removeItem(root.index)
            }
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
            onClicked: {
                root.visible = false
                root.isAdd ? SV_MODEL.add(repeater.itemAt(0).textInput, repeater.itemAt(1).textInput, repeater.itemAt(2).textInput)
                       : SV_MODEL.modifyItem(repeater.itemAt(0).textInput, repeater.itemAt(1).textInput, repeater.itemAt(2).textInput, root.index)
            }
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

    function init(name, color, tuition, isAdd, index) {
        root.name = name
        root.color = color
        root.tuition = tuition
        root.isAdd = isAdd
        root.index = index
    }
}
