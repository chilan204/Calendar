import QtQuick 2.0

Item {
    id: root

    Text {
        id: month
        text: CTRL.monthStatistical
        font.pixelSize: 20
        anchors {
            verticalCenter: parent.verticalAlignment
            horizontalCenter: parent.horizontalCenter
        }
    }

    Image {
        id: nextIcon
        width: 20
        height: 20
        source: "qrc:/Icon/Next.png"
        anchors {
            verticalCenter: month.verticalCenter
            right: parent.right
        }
        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
                CTRL.changeMonthStatistical(true);
            }
        }
    }

    Image {
        id: preIcon
        width: 20
        height: 20
        source: "qrc:/Icon/Previous.png"
        anchors {
            verticalCenter: month.verticalCenter
            left: parent.left
        }
        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.8
            onReleased: parent.scale = 1
            onClicked: {
                CTRL.changeMonthStatistical(false);
            }
        }
    }
}
