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
                        onClicked: {
                            popup.visible = true
                            popup.date = styleData.date
                        }
                    }

                    Row {
                        Repeater {
                            id: repeater
                            model: CTRL.getListColorDate(styleData.date).length
                            Rectangle {
                                width: dayBox.width/repeater.model
                                height: dayBox.height
                                color: CTRL.getListColorDate(styleData.date)[index]
                            }
                        }
                        Connections{
                            target: CTRL
                            function onWorkingdayChanged(workingday){
                                if(Qt.formatDateTime(styleData.date, "yyMMdd") ===
                                        Qt.formatDateTime(workingday, "yyMMdd")) {
                                    repeater.model = CTRL.getListColorDate(styleData.date).length
                                    for(var i = 0; i < CTRL.getListColorDate(styleData.date).length; i++) {
                                        repeater.itemAt(i).color = CTRL.getListColorDate(styleData.date)[i]
                                    }
                                }
                            }
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
