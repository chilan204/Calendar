import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: root
    anchors.fill: parent

    property string color
    property string name
    property string tuition

    Rectangle {
        anchors.fill: parent
        color: "white"
        MouseArea{
            anchors.fill: parent
        }
    }

    Calendar {
        id: calendar
        width: 450
        height: 300
        navigationBarVisible: false
        anchors {
            top: parent.top
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
        style: CalendarStyle {
            dayDelegate: Item {
                Rectangle {
                    anchors.fill: parent
                    color: CTRL.getColorDate(styleData.date, root.color) ? root.color : "white"
                }

                Label {
                    id: dayDelegateText
                    text: styleData.date.getDate()
                    font.pixelSize: 20
                    opacity: styleData.visibleMonth ? 1 : 0.5
                    anchors.centerIn: parent
                }
            }
        }
        MouseArea {
            anchors.fill: parent
        }
    }

    Column {
        Text {
            text: '<b>Name:</b> ' + root.name
            font.pixelSize: 20
        }
        Text {
            text: '<b>Tuition:</b> ' + root.tuition
            font.pixelSize: 20
        }
        Text {
            text: '<b>Total lesson:</b> ' + CTRL.getWorkingDay(root.color)
            font.pixelSize: 20
        }
        Text {
            text: '<b>Total tuition:</b> ' + root.tuition * CTRL.getWorkingDay(root.color)
            font.pixelSize: 20
        }
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: calendar.bottom
            topMargin: 20
        }
    }

    Rectangle {
        id: closeButton
        width: 75
        height: 30
        radius: 15
        color: "lavender"
        border.color: "black"
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 15
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: {
                root.visible = false
            }
        }

        Text {
            anchors.centerIn: parent
            text: "Đóng"
            font.pixelSize: 20
        }
    }
}

