import QtQuick 2.12
import QtQuick.Controls 2.5
//import QtQuick.Dialogs 1.3
import Translator 1.0
import Qt.labs.platform 1.1

ApplicationWindow {
    visible: true
    minimumWidth: 380; minimumHeight: 170
    width: 720;height: 340
    title: qsTr("Перводчик Морзе")

    Translator {
        id: _translator
    }

    Item {
        anchors.fill: parent
        Button {            
            anchors.top: parent.top; anchors.topMargin: 5
            anchors.left: parent.left; anchors.leftMargin: 20
            text: qsTr("Перевести")
            onClicked: {
                _textAreaRight.text = _translator.translate(_textAreaLeft.text)
            }
        }
        Button {
            anchors.top: parent.top; anchors.topMargin: 5
            anchors.left: parent.left; anchors.leftMargin: 140
            text: qsTr("Открыть файл")
            onClicked: {               
                _openfileDialog.open()
            }
        }
        Button {
            anchors.top: parent.top; anchors.topMargin: 5
            anchors.right: parent.right; anchors.rightMargin: 20
            text: qsTr("Сохранить в файл")
            onClicked: {
                _savefileDialog.open()
            }
        }
        TextArea {
            id: _textAreaLeft
            anchors.top: parent.top; anchors.topMargin: 50
            anchors.left: parent.left; anchors.leftMargin: 20
            anchors.bottom: parent.bottom; anchors.bottomMargin: 20
            width: parent.width/2-40
            padding: 10
            wrapMode: Text.WordWrap
            placeholderText: qsTr("Введите текст")
            background: Rectangle {               
                border.color: "#1E90FF"; border.width: 1
                radius: 10
            }
            onTextChanged: {
                _textAreaRight.text = _translator.translate(text)
            }
        }
        Label {
            id: _textAreaRight
            anchors.top: parent.top; anchors.topMargin: 50
            anchors.right: parent.right; anchors.rightMargin: 20
            anchors.bottom: parent.bottom; anchors.bottomMargin: 20
            width: parent.width/2-40
            padding: 10
            clip: true
            wrapMode: Text.WordWrap
            background: Rectangle {
                border.color: "#1E90FF"; border.width: 1
                radius: 10
            }
        }
    }
    FileDialog {
        id: _openfileDialog
        title: "Открыть файл"
        nameFilters: "Text files (*.txt)"
        fileMode: FileDialog.OpenFile
        onAccepted: {
            _textAreaLeft.text = _translator.openFile(file)
        }
    }
    FileDialog {
        id: _savefileDialog
        title: qsTr("Сохранить файл")
        nameFilters: "Text files (*.txt)"
        fileMode: FileDialog.SaveFile
        onAccepted: {
            _translator.saveFile(file, _textAreaRight.text)
        }
    }
}
