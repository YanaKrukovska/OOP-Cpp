#include "Field.h"
#include "GameException.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Field::Field(int rows, int cols)
        : rows(0), cols(0), field(nullptr) {
    if (rows <= 0 || cols <= 0)
        throw GameException("Wrong field parameters");

    srand(time(nullptr));

    this->rows = rows;
    this->cols = cols;

    field = new char *[rows];
    for (int i = 0; i < rows; i++) {
        field[i] = new char[cols];
    }


    clearField();
}


Field::~Field() {
    if (field != nullptr) {
        for (int i = 0; i < rows; i++){
            delete[] field[i];
        }
        delete[] field;
    }
}


void Field::clearField() {
    if (field == nullptr) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            field[i][j] = (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) ? '*' : ' ';
        }
    }

}

void Field::showField() const {
    if (field == nullptr) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << field[i][j];
        }
        cout << '\n';
    }
}


void Field::setPoints(const Point &point, char ch) {

    if (field == nullptr){
        return;
    }

    if (point.x == 0 || point.y == 0 || point.x == cols - 1 || point.y == rows - 1){
        throw GameException("Can't set on borders");
    }

    field[point.y][point.x] = ch;
}

void Field::setFood() {

    if (field == nullptr) {
        return;
    }


    bool isEmpty = false;
    for (int i = 0; i < rows && !isEmpty; i++) {
        for (int j = 0; j < cols; j++) {
            if (field[i][j] == ' ') {
                isEmpty = true;
                break;
            }
        }

    }

    if (!isEmpty) {
        return;
    }


    int foodX;
    int foodY;

    do {
        foodX = rand() % (cols - 3) + 1;
        foodY = rand() % (rows - 3) + 1;
    } while (field[foodY][foodX] != ' ');


    field[foodY][foodX] = '$';
}

char Field::getElement(const Point &point) const {
    return field[point.y][point.x];
}


