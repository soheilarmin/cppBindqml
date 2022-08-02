import QtQuick 2.0

import App 1.0

Window {
    width: 440
    height: 280
    visible: true
    title: qsTr("Hello World")

    ListView {
        width: 200; height: 250

        model: logModel
        delegate: Text { text: "my log: " + type + ", " + message }
    }

    Item {
        MyClass {
           model: logModel
        }
        LogModel {
            id: logModel
        }
    }
}
