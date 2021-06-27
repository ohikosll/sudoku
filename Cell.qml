import QtQuick 2.0

Rectangle {

    height: 60
    width: 60
    // Определение цвета для конкретной клетки по её индексу
    color: helper.color(index).toString()
    border.color: "white"
    property int value: 3
    signal winDetected
    // Изменение значения в клетке
    function changeNumber() {
        value = (value + 1) % 10
        helper.changeState(index)
    }

    Text {
        id: cellText
        // Прятать нулевые значения клеток
        function setText(value) {
            if (value === 0)
                return ""
            return value.toString()
        }
        anchors.centerIn: parent
        text: setText(parent.value)
        font.pixelSize: 20
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            // Если клетка доступна для изменения - менять её
            if (helper.editable(index)) {
                cellText.color = "#def1ff"
                parent.changeNumber()
                // Если замечено решение - сигнал о победе
                if (helper.checkSolution()) {
                    winDetected()
                }
            }
        }
    }
}
