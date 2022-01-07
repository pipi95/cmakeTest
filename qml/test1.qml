import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    RowLayout{
        anchors.fill: parent
        Rectangle{
            color: "green"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 50
            Button{
                text: "testBtn"
                anchors.fill: parent
            }
        }
        Image {
            id: name
            source: "qrc:/image/1.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
