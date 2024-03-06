import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "../component/home"

Item {
    id: root
    anchors.fill: parent



    Calendar {
        id: calendar
        anchors.fill: parent
        style: CalendarStyle {
            dayDelegate: Item {
                Item {
                    id: dayBox
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        onClicked: popup.visible = true
                    }

                    Row {
                        Repeater {
                            model: ["red","blue","yellow"]
                            Rectangle { width: dayBox.width/3; height: dayBox.height; color: modelData }
                        }
                    }
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
    }

    HomePopUp {
        id: popup
        anchors.fill: parent
        visible: false
    }
}
