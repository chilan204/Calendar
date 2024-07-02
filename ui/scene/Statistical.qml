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
            topMargin: 15
        }
    }

    Rectangle {
        id: axisBar
        width: 375
        height: 3
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 60
        }
        color: "black"
    }

    ListView {
        id: liststudent
        width: 350
        height: 360
        spacing: 50
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
            workingDay: CTRL.getWorkingDay(model.color)
            anchors.bottom: parent.bottom

            Connections {
                target: CTRL
                function onMonthStatisticalChanged(){
                    workingDay = CTRL.getWorkingDay(model.color)
                }
            }
        }
    }

//    ScrollBar {
//        id: scrollBar
//        width: parent.width - 100
//        height: 3
//        anchors {
//            bottom: parent.bottom
//            bottomMargin: 5
//        }
//        opacity: 0.5
//    }

    StatisticalPopUp {
        id: statisticalPopUp
        visible: false
        anchors.fill: parent
    }
}
