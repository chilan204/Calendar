import QtQuick 2.0

Item {
    id: root
    width: 50
    height: CTRL.maxWorkingDay == 0 ? 0 : 300*workingDay/CTRL.maxWorkingDay + 60

    property string nameStudent
    property string colorStudent
    property int workingDay

    Text {
        id: name
        font.pixelSize: 20
        text: root.nameStudent
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }
    }

    Rectangle {
        id: rec
        width: parent.width
        height: CTRL.maxWorkingDay == 0 ? 0 : 300*workingDay/CTRL.maxWorkingDay
        border.color: "black"
        color: colorStudent
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: name.top
            bottomMargin: 5
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                statisticalPopUp.visible = true
                statisticalPopUp.color = model.color
                statisticalPopUp.name = model.name
                statisticalPopUp.tuition = model.tuition
            }
        }
    }

    Text {
        id: day
        font.pixelSize: 20
        text: workingDay
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom:  rec.top
            bottomMargin: 5
        }
    }
}
