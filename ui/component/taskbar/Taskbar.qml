import QtQuick 2.0
import AppEnum 1.0

Item {
    id: root
    width: 500
    height: 80
    state: AppEnum.HOME

    property string screen: listItem.get(root.state).pathItem

    Rectangle {
        width: parent.width
        height: 3
        anchors {
            bottom: parent.top
            bottomMargin: 5
        }
        color: "black"
        opacity: 0.3
    }

    ListModel {
        id: listItem

        ListElement {
            stateItem: AppEnum.HOME
            pathItem: "qrc:/ui/scene/Home.qml"
            imgItem: "qrc:/Icon/Home.png"
            imgHLItem: "qrc:/Icon/Home_Highlight.png"
            nameItem: "Trang chủ"
        }

        ListElement {
            stateItem: AppEnum.INFOR
            pathItem: "qrc:/ui/scene/Infor.qml"
            imgItem: "qrc:/Icon/Infor.png"
            imgHLItem: "qrc:/Icon/Infor_Highlight.png"
            nameItem: "Thông tin"
        }

        ListElement {
            stateItem: AppEnum.STATISTICAL
            pathItem: "qrc:/ui/scene/Statistical.qml"
            imgItem: "qrc:/Icon/Statistical.png"
            imgHLItem: "qrc:/Icon/Statistical_Highlight.png"
            nameItem: "Thống kê"
        }

        ListElement {
            stateItem: AppEnum.SETTING
            pathItem: "qrc:/ui/scene/Setting.qml"
            imgItem: "qrc:/Icon/Setting.png"
            imgHLItem: "qrc:/Icon/Setting_Highlight.png"
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
                sourceImg: isCurrent ? imgHLItem : imgItem
                name: nameItem
                isCurrent: root.state == stateItem
                onClicked: root.state = stateItem
            }
        }
    }
}
