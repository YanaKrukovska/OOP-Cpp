#pragma once

#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

class Field {
private:
    int rows;
    int cols;
    char **field;

public:

    explicit Field(int rows = 15, int cols = 15);

    ~Field();

    void clearField();

    void showField() const;

    void setPoints(const Point &point, char ch);

    void setFood();

    char getElement(const Point &point) const;

    int getRows() const { return rows; }

    int getCols() const { return cols; }
};
