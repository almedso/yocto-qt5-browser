import QtQuick 2.13
import QtQuick.Window 2.13
import QtWebEngine 1.0

Window {
    id: window
    visible: true
    width: 480
    height: 800
    title: qsTr("Web Browser")

    WebEngineView {
        anchors.fill: parent
        url: "http://localhost"
    }
}
