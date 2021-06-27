import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Window {
    id: dialog
    visible: false
    minimumWidth: 200
    maximumWidth: 200
    width: 200

    minimumHeight: 100
    maximumHeight: 100
    height: 100

    Button {
        id: newGameButton2
        x: 50
        y: 50
        text: "New Game"
        onClicked: {
            // Инициализация новой игры
            gameplay.newGame()
            // toolbar.time = 10
            toolbar.setTimer(300)
            //w.visible = true
            dialog.close()
        }
    }
    Shortcut {
        context: Qt.ApplicationShortcut
        sequence: ["Ctrl+N"]
        onActivated: {
            gameplay.newGame()
            toolbar.setTimer(300)
        }
    }

    TextField {
        id: endText
        anchors.centerIn: endText
        text: (gameplay.winned ? "You won!" : "You lose, try again!")
    }
}
