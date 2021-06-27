#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QVector>
#include <math.h>

using namespace std;
class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);

    // Текущее состояние поля
    QVector<int> currentState;

    // Шаблон заполненного поля
    QVector<int> filledArea = {
        1, 2, 3,    4, 5, 6,    7, 8, 9,
        4, 5, 6,    7, 8, 9,    1, 2, 3,
        7, 8, 9,    1, 2, 3,    4, 5, 6,
        2, 3, 4,    5, 6, 7,    8, 9, 1,
        5, 6, 7,    8, 9, 1,    2, 3, 4,
        8, 9, 1,    2, 3, 4,    5, 6, 7,
        3, 4, 5,    6, 7, 8,    9, 1, 2,
        6, 7, 8,    9, 1, 2,    3, 4, 5,
        9, 1, 2,    3, 4, 5,    6, 7, 8
    };

    // Состояние инициализированного поля со спрятанными цифрами
    QVector<int> initialState;

    // Индексы элементов секторов, которые необходимо выделить цветом
    QVector<int> lighterColor = {
        3, 4, 5, 12, 13, 14, 21, 22, 23,
        27, 28, 29, 36, 37, 38, 45, 46, 47,
        57, 58, 59, 66, 67, 68, 75, 76, 77,
        33, 34, 35, 42, 43, 44, 51, 52, 53
    };
signals:

public slots:
    // Инициализация поля для новой игры
    QVector<int> newGame();
    // Изменение значения элемента с индексом index
    void changeState(int index);
    // Перестановка двух строк на поле
    void swapLines(int line1, int line2);
    // Перестановка двух столбцов на поле
    void swapRows(int row1, int row2);
    // Функция проверки на правильность решения
    bool checkSolution(void);
    // Спрятать правильно решение, убрав некоторые элементы
    void hideSolution(void);
    // Определяет возможность изменения значения клетки
    bool editable(int index);
    // Определяет цвет для секторов
    QString color(int index);
};

#endif // HELPER_H
