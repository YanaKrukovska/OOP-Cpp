//
// Created by user on 11.04.2020.
//

#define NDEBUG


#include "Point.h"
#include<cmath>

using namespace std;


Point::Point(double x, double y) : _x(x), _y(y) {
#ifndef NDEBUG
    cout << "Created " << *this << endl;
#endif
}

Point::~Point() {
#ifndef NDEBUG
    cout << "Deleted " << *this << endl;
#endif
}

Point &Point::mirrorX() {
    _y *= -1;
    return *this;
}

Point &Point::mirrorY() {
    x() *= -1;
    return *this;
}

Point &Point::turn(double angle) {
    double x_temp = _x;
    double y_temp = _y;
    double radians = (angle * 3.14159265) / 180.0;
    _x = (int) (x_temp * cos(radians) - y_temp * sin(radians));
    _y = (int) (x_temp * sin(radians) + y_temp * cos(radians));
    return *this;
}

void mirrorPoint(Point &point, MirrorPointAction action) {
    (point.*action)();
}


ostream &operator<<(ostream &os, const Point &point) {
    os << "Point (" << point.x() << ", " << point.y() << ")";
    return os;
}