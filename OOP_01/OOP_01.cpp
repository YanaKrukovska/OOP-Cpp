//
// Created by user on 08.02.2020.
//

#include <iostream>
#include "Point.h"
#include <cassert>
#define NDEBUG

using namespace std;

int main() {

    Point point1(1, 1);
    Point point2(2,0);
    Point point3(point1);
    Point point4(2, 2);

    cout << point1 << point2 << point3 << point4;

    assert(point1.amount() == 4);

    assert((point1 == point1) == 1);
    assert((point1 == point2) == 0);

    assert((point1 != point1) == 0);
    assert((point1 != point2) == 1);

    assert((point1 += point4).x() == 3);
    assert((point2 += point2).x() == 4);

    Point point5 = point2 + point4; // (4, 0) + (2, 2)
    assert(point5.x() == 6);
    assert(point5.y() == 2);
    assert(point1.amount() == 5);

    assert(point1.getID() == 1);
    assert(point5.getID() == 5);

    assert((point1 = point3).x() == 1);
    assert((point3 = point4).y() == 2);





}

