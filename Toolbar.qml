import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.0
import QtQuick 2.0

RowLayout {
    id: rl
    property int time: 300
    signal makeNewGame
    signal quitApp
    signal lose

    function isLose() {
        console.log("Lose")
        end.visible = true
        w.visible = false
    }
    function stopTimer() {
        timer.stop()
    }

    /* Установить таймер */
    function setTimer(seconds) {
        time = seconds
        timer.start()
    }

    Button {
        id: newGameButton

        text: "New Game"
        onClicked: {
            toolbar.setTimer(300)
            gameplay.newGame()
        }
    }

    TextField {
        id: textField1
        Layout.fillWidth: true
    }
    // @disable-check M300
    Timer {
        id: timer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            if (gameplay.winned) {
                timer.stop()
                isWon()
            }
            if (time == 0) {
                timer.stop()
                lose()
            }

            textField1.text = "Time to the end: "
            textField1.text += rl.time.toString() + " sec."
            rl.time = rl.time - 1
        }
    }

    Button {
        id: quitButton

        text: "Quit"
        onClicked: quitApp()
    }

    Shortcut {
        context: Qt.ApplicationShortcut
        sequence: ["Ctrl+N"]
        onActivated: {
            toolbar.setTimer(time)
            gameplay.newGame()
        }
    }

    Shortcut {
        context: Qt.ApplicationShortcut
        sequence: [StandardKey.Close, "Ctrl +Q"]
        onActivated: quitApp()
    }
}
