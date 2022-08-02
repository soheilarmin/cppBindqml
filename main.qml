import QtQuick 2.0
import QtQml 2.0
import QtQuick.Window 2.15
import App 1.0

Window {
    width: 440
    height: 280
    visible: true
    title: qsTr("Hello World")

    ListView {
        width: 200; height: 250

        model: myClass.model
        delegate: Text { text: "my log: " + type + ", " + message }
        onCountChanged: positionViewAtEnd()

        MyClass{
            id: myClass
        }

        Timer{
            interval: 1000
            running: true
            repeat: true
            onTriggered: myClass.addLogSample()
        }
    }

}
