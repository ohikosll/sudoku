import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.0

Window {
    id: w
    visible: true

    minimumWidth: 540
    maximumWidth: 540
    width: 540

    minimumHeight: 580
    maximumHeight: 580
    height: 580

    title: qsTr("Sudoku")

    ColumnLayout {
        id: cl

        anchors.centerIn: w.contentItem
        spacing: 2

        Gameplay {
            id: gameplay

            onWin: {
                // Остановка таймера после получения сигнала о победе
                toolbar.stopTimer()
                end.visible = true
            }
        }

        Toolbar {
            id: toolbar

            onMakeNewGame: {
                gameplay.newGame()
                toolbar.setTimer(300)
            }

            onLose: {
                console.log("Lose")
                end.visible = true
            }

            onQuitApp: Qt.quit()
        }
    }

    EndScreen {
        id: end
    }
}
