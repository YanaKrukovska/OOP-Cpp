//
// Created by user on 11.04.2020.
//

#ifndef C_POINT_H
#define C_POINT_H

#include <iostream>
#include<cmath>


using namespace std;

class Point {

private:
    double _x, _y;

public:
    explicit Point(double x = 0, double y = 0);
    ~Point();

    double &x() { return _x; }
    double &y() { return _y; }

    const double &x() const { return _x; }
    const double &y() const { return _y; }

    Point& mirrorX();
    Point& mirrorY();
    Point& turn(double angle);

};

ostream &operator<<(ostream &, const Point &);

typedef Point &(Point::* const MirrorPointAction)();
void mirrorPoint(Point & point, MirrorPointAction action);


#endif //C_POINT_H
