import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root
    anchors.fill: parent

    Text {
        id: title
        text: qsTr("Bảng thống kê")
        font.pixelSize: 35
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
    }

    Text {
        id: selectMonth
        text: qsTr("Tháng 1 Tháng 2")
        font.pixelSize: 20
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: title.bottom
            topMargin: 20
        }
    }

    ListModel {
        id: myModel
        ListElement { name: "hs 1"; numberOfLessons: 10; }
        ListElement { name: "hs 2"; numberOfLessons: 20; }
        ListElement { name: "hs 3"; numberOfLessons: 30; }
    }

    TableView {
        width: 500
        height: 380
        model: myModel
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: selectMonth.bottom
            topMargin: 20
        }

        TableViewColumn {
            role: "name" // Được đặt tên trong ListModel
            title: "Tên"
            width: 150
        }

        TableViewColumn {
            role: "numberOfLessons"
            title: "Số buổi học"
            width: 150
        }

//        TableViewColumn {
//            role: "fee"
//            title: "Số tiền"
//            width: 150
//        }
    }
}
