#include "Helper.h"
#include <QRandomGenerator>
#include <QString>

Helper::Helper(QObject *parent) : QObject(parent)
{

}

QVector<int> Helper::newGame()
{
    // Перетусовывает поле
    QRandomGenerator g;
    currentState = filledArea;
    for (int i = 0; i < rand() % 15; i++){
        swapLines(g.bounded(0, 2), g.bounded(0, 2));
        swapRows(g.bounded(0, 2), g.bounded(0, 2));
        swapLines(g.bounded(3, 5), g.bounded(3, 5));
        swapRows(g.bounded(3, 5), g.bounded(3, 5));
        swapLines(g.bounded(6, 8), g.bounded(6, 8));
        swapRows(g.bounded(6, 8), g.bounded(6, 8));
    }
    hideSolution();
    initialState = currentState;
    return currentState;
}

void Helper::changeState(int index){
    currentState[index] = (currentState[index] + 1) % 10;
}

void Helper::swapRows(int row1, int row2){
    QVector<int> saved;
    for (int i = 0; i < 9; i++){
       saved.append(currentState[row1 + i * 9]);
       currentState[row1 + i * 9] = currentState[row2 + i * 9];
    }
    for (int i = 0; i < 9; i++)
        currentState[row2 + i * 9] = saved[i];
}

void Helper::swapLines(int line1, int line2){
    QVector<int> saved;
    for (int i = 0; i < 9; i++){
       saved.append(currentState[line1 * 9 + i]);
       currentState[line1 * 9 + i] = currentState[line2 * 9 + i];
    }
    for (int i = 0; i < 9; i++)
        currentState[line2 * 9 + i] = saved[i];
}

bool Helper::checkSolution(void){
    for (int i = 0; i < 9; i++){
        QVector<int> current;
        for (int j = 0; j < 9; j++){
            if (current.contains(currentState[i * 9 + j]))
                return false;
            current.append(currentState[i * 9 + j]);
        }
        current.clear();
    }

    for (int i = 0; i < 9; i++){
        QVector<int> current;
        for (int j = 0; j < 9; j++) {
            if (current.contains(currentState[j * 9 + i]))
                return false;
            current.append(currentState[j * 9 + i]);
        }
        current.clear();
    }

    int matrix[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            matrix[i][j] = currentState[i * 9 + j];

    QVector<int> current;


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[i][j]))
                return false;
            current.append(matrix[i][j]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[i][j + 3]))
                return false;
            current.append(matrix[i][j + 3]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[i][j + 6]))
                return false;
            current.append(matrix[i][j + 6]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[3 + i][j]))
                return false;
            current.append(matrix[3 + i][j]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[3 + i][j + 3]))
                return false;
            current.append(matrix[3 + i][j + 3]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[3 + i][j + 6]))
                return false;
            current.append(matrix[3 + i][j + 6]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[6 + i][j]))
                return false;
            current.append(matrix[6 + i][j]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[6 + i][j + 3]))
                return false;
            current.append(matrix[6 + i][j + 3]);
        }
    }
    current.clear();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (current.contains(matrix[6 + i][6 + j]))
                return false;
            current.append(matrix[6 + i][j + 6]);
        }
    }
    current.clear();
    return true;
}

void Helper::hideSolution(void){
    int numOfZeros = rand() % 45;
    while(currentState.count(0) != numOfZeros)
        currentState[rand() % 81] = 0;
}

bool Helper::editable(int index){
    return initialState[index] != 0 ? false : true;
}

QString Helper::color(int index){
    return lighterColor.contains(index) ? "#9ec0ff" : "#5e97ff";
}
