import QtQuick 2.12
import QtQuick.Window 2.12
import "component/taskbar"
import "component"

Window {
    id: root
    visible: true
    width: 540
    height: 600
    title: qsTr("Calendar")

    Loader {
        id: loader
        width: 500
        height: 500
        source: taskbar.screen
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Taskbar {
        id: taskbar
        anchors {
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
    }

    NotifyPopUp{}
}
