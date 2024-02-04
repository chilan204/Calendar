import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    width: 450
    height: 550
    title: qsTr("Calendar")

    Calendar {
        id: calendar
        width: 400
        height: 400
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Option {
        id: option
        anchors {
            top: calendar.bottom
            horizontalCenter: calendar.horizontalCenter
        }
    }
}
