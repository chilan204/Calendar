import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent
    visible: false

    property string text

    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.2
        MouseArea{
            anchors.fill: parent
        }
    }

    Rectangle {
        id: bg
        width: 400
        height: 120
        radius: 20
        anchors.centerIn: parent
    }

    Text {
        anchors {
            horizontalCenter: bg.horizontalCenter
            top: bg.top
            topMargin: 20
        }
        text: root.text
        font.pixelSize: 20
    }

    Rectangle {
        width: 50
        height: 25
        radius: 15
        color: "#C0C0C0"
        border.color: "black"
        anchors {
            horizontalCenter: bg.horizontalCenter
            bottom: bg.bottom
            bottomMargin: 20
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.scale = 0.9
            onReleased: parent.scale = 1
            onClicked: root.visible = false
        }

        Text {
            anchors.centerIn: parent
            text: "OK"
            font.pixelSize: 15
        }
    }

    Connections {
        target: CTRL
        function onShowNotifyPopUp(msg){
            root.visible = true
            root.text = msg
        }
    }

}
