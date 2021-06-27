import QtQuick 2.12
import QtQuick.Layouts 1.12

GridLayout {
    property bool winned: false
    signal win
    id: gl
    width: 540
    height: 540

    columns: 9
    rows: 9
    columnSpacing: 0
    rowSpacing: 0
    // Функция новой игры
    function newGame() {
        var newGameConfigs = helper.newGame()
        for (var i = 0; i < newGameConfigs.length; i++)
            cells.itemAt(i).value = newGameConfigs[i]
        winned = false
    }
    // Задание модели игрового поля
    Repeater {
        id: cells
        model: 81
        Cell {
            // Сигнал о победе, передающийся в main.qml
            onWinDetected: {
                win()
                winned = true
            }
        }
    }
    // @disable-check M16
    Component.onCompleted: {
        newGame()
        toolbar.setTimer(300)
    }
}
