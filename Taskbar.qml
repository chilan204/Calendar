import QtQuick 2.0

Item {
    id: root
    width: 500
    height: 80

    property string screen: "qrc:/Home.qml"

    ListModel {
        id: listItem

        ListElement {
            nameImgItem: "Home"
            nameItem: "Trang chủ"
        }

        ListElement {
            nameImgItem: "Statistical"
            nameItem: "Thống kê"
        }

        ListElement {
            nameImgItem: "Infor"
            nameItem: "Thông tin"
        }

        ListElement {
            nameImgItem: "Setting"
            nameItem: "Cài đặt"
        }
    }

    Row {
        Repeater {
            id: repeat
            model: listItem
            TaskbarItem {
                id: item
                x: index * item.width
                width: root.width / listItem.count
                height: root.height
                nameImg: nameImgItem
                name: nameItem
                isCurrent: index == 0
                onClicked: clickItem(index, nameImg)
            }
        }
    }

    function clickItem(index, screen) {
        for (var i = 0; i < listItem.count; i++) {
           repeat.itemAt(i).isCurrent = (i === index)
        }

        root.screen = "qrc:/" + screen + ".qml"
    }
}
