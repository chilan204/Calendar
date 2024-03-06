import QtQuick 2.0
import "../component/infor"

Item {
    id: root
    anchors.fill: parent

    Text {
        id: title
        text: qsTr("Thông tin học sinh")
        font.pixelSize: 35
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
    }

    ListView {
        id: listStudent
        width: 350
        height: 390
        clip: true
        spacing: 10
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: title.bottom
            topMargin: 30
        }

        model: ListModel {
            id: list_model
            ListElement {
                name: "HS1"
                address: "AD1sthrthsthsehserhhrthsthsehserhe"
                age: "1"
            }
            ListElement {
                name: "HS2"
                address: "AD2shtrsjhtykyhrthsthsehserhuksthe"
                age: "2"
            }
            ListElement {
                name: "HS3"
                address: "AD3erhsthtrhsrthrthsthsehserhhshsr"
                age: "3"
            }
            ListElement {
                name: "HS4"
                address: "AD4sehtrsjrjsthahrthsthsehserhehaaw"
                age: "4"
            }
        }

        delegate: Rectangle {
            width: 350
            height: 90
            radius: 20
            border.color: "black"

            MouseArea {
                anchors.fill: parent
                onPressed: parent.scale = 0.95
                onReleased: parent.scale = 1
                onClicked: popup.visible = true
            }

            Column {
                Text {
                    text: '<b>Name:</b> ' + name
                    font.pixelSize: 15
                }
                Text {
                    text: '<b>Address:</b> ' + address
                    font.pixelSize: 15
                }
                Text {
                    text: '<b>Age:</b> ' + age
                    font.pixelSize: 15
                }
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 30
                }
            }
        }
    }

    InforPopUp {
        id: popup
        anchors.fill: parent
        visible: false
    }
}
