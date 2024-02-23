import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root
    anchors.fill: parent

    Calendar {
        id: calendar
        anchors.fill: parent
        onClicked: {
            selectedDate = date;
        }
    }
}
