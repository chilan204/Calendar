import QtQuick 2.0
import QtQuick.Controls 2.14
import "../component/statistical"

Item {
    id: root
    anchors.fill: parent

    Text {
        id: title
        text: "Bảng thống kê"
        font.pixelSize: 35
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
    }

    TimeBar {
        id: timeBar
        width: parent.width
        height: 20
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: title.bottom
            topMargin: 20
        }
    }

//    PathView {
//        id: timeBar
//        anchors.fill: parent
//        model: 12
//        delegate: Rectangle {
//            width: 80
//            height: 40
//            radius: 40
//            border.color: "black"
//            opacity: PathView.isCurrentItem ? 1 : 0.5

//            Text {
//                text: "Tháng " + (index + 1)
//                font.pixelSize: 15
//                anchors.centerIn: parent
//            }
//        }
//        path: Path {
//            startX: 250
//            startY: 100
//            PathQuad { x: 250; y: 50; controlX: 1000; controlY: 75 }
//            PathQuad { x: 250; y: 100; controlX: -500; controlY: 75 }
//        }
//    }

    Rectangle {
        id: axisBar
        width: 375
        height: 3
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: scrollBar.top
            bottomMargin: 50
        }
        color: "black"
    }

    ListView {
        id: liststudent
        width: 375
        height: 360
        spacing: 25
        orientation: ListView.Horizontal
        clip: true
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: axisBar.top
            bottomMargin: -30
        }

        model: SV_MODEL
        delegate: StudentItem {
            nameStudent: model.name
            colorStudent: model.color
//            workingDay: CTRL.getWorkingDay[index]
            MouseArea {
                anchors.fill: parent
            }
        }
    }

    ScrollBar {
        id: scrollBar
        width: parent.width - 100
        height: 3
        anchors {
            bottom: parent.bottom
            bottomMargin: 5
        }
        opacity: 0.5
    }
}
