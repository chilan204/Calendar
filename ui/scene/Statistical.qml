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

    ListView {
        id: listmonth
        width: 480
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: title.bottom
            topMargin: 20
        }

        clip: true
        orientation: ListView.Horizontal
        spacing: 20

        model: ListModel {
            id: list_model
            ListElement {
                month: "Tháng 1"
            }
            ListElement {
                month: "Tháng 2"
            }
            ListElement {
                month: "Tháng 3"
            }
            ListElement {
                month: "Tháng 4"
            }
            ListElement {
                month: "Tháng 5"
            }
            ListElement {
                month: "Tháng 6"
            }
            ListElement {
                month: "Tháng 7"
            }
            ListElement {
                month: "Tháng 8"
            }
            ListElement {
                month: "Tháng 9"
            }
            ListElement {
                month: "Tháng 10"
            }
            ListElement {
                month: "Tháng 11"
            }
            ListElement {
                month: "Tháng 12"
            }
        }

        delegate: Rectangle {
            width: 80
            height: 40
            radius: 20
            opacity: 0.5
            border.color: "black"

            MouseArea {
                anchors.fill: parent
                onClicked: parent.opacity = (parent.opacity == 1 ? 0.5 : 1)
            }

            Text {
                anchors.centerIn: parent
                text: model.month
                font.pixelSize: 15
                color: "black"
            }
        }
    }

    Rectangle {
        width: parent.width
        height: 3
        anchors {
            bottom: parent.bottom
            bottomMargin: 5
        }
        color: "black"
        opacity: 0.5
    }



//    ListModel {
//        id: myModel
//        ListElement { name: "hs 1"; numberOfLessons: 10; }
//        ListElement { name: "hs 2"; numberOfLessons: 20; }
//        ListElement { name: "hs 3"; numberOfLessons: 30; }
//    }

//    TableView {
//        width: 500
//        height: 380
//        model: myModel
//        anchors {
//            horizontalCenter: parent.horizontalCenter
//            top: selectMonth.bottom
//            topMargin: 20
//        }

//        TableViewColumn {
//            role: "name" // Được đặt tên trong ListModel
//            title: "Tên"
//            width: 150
//        }

//        TableViewColumn {
//            role: "numberOfLessons"
//            title: "Số buổi học"
//            width: 150
//        }

////        TableViewColumn {
////            role: "fee"
////            title: "Số tiền"
////            width: 150
////        }
//    }
}
