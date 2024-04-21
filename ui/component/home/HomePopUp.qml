import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent

    property var date
    property var listIndex

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
        id: listColor
        width: 280
        height: 125
        clip: true
        spacing: 20
        orientation: ListView.Horizontal
        anchors {
            horizontalCenter: bg.horizontalCenter
            top: bg.top
            topMargin: 20
        }

        model: SV_MODEL

        delegate: Item {
            id: delegateItem
            width: 80
            height: 125
            property bool isCheck: false
            Rectangle {
                width: 80
                height: 80
                radius: 80
                opacity: parent.isCheck ? 1 : 0.2
                color: model.color
                border.color: "black"

                MouseArea {
                    anchors.fill: parent
                    onClicked: delegateItem.isCheck = !delegateItem.isCheck
                }
            }

            Text {
                text: model.name
                font.pixelSize: 15
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    bottom: parent.bottom
                    bottomMargin: 20
                }
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
            onClicked: {
                root.listIndex = []
                for(var i = 0; i < 4; i++) {
                    if(listColor.itemAtIndex(i).isCheck){
                        root.listIndex.push(i)
                    }
                }
                CTRL.modifyWorkingday(date, root.listIndex)
                root.visible = false
            }
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
