#include <iostream>
#include "Point.h"

using namespace std;

int Point::freeID = 0;

Point::Point(double x, double y) : _x(x), _y(y), pointID(++freeID) {
#ifndef NDEBUG
    cout << "Created " << *this << endl;
#endif
}


Point::Point(const Point& original) : _x(original.x()), _y(original.y()), pointID(++freeID) {
#ifndef NDEBUG
    cout << "Created " << *this << endl;
#endif
}

Point::~Point()
{
#ifndef NDEBUG
    cout << "Deleted " << *this << endl;
#endif
    return;
}

Point& Point::operator=(const Point& newPoint) {
    if (this == &newPoint)
        return *this;

    _x = newPoint.x();
    _y = newPoint.y();
    return *this;
}

double& Point::x()
{
    return _x;
}

double& Point::y()
{
    return _y;
}

const double& Point::x()const
{
    return _x;
}

const double& Point::y()const
{
    return _y;
}


ostream& operator<<(ostream& os, const Point& point) {
    os << "Point (" << point.x() << ", " << point.y() << "), id = " << point.getID();
    return os;
}


const Point operator+ (const Point& u, const Point& v) {
    return Point(u.x() + v.x(), u.y() + v.y());
}


Point& operator+=(Point& u, const Point& v) {

    u.x() += v.x();
    u.y() += v.y();
    return u;
}


bool operator==(const Point& u, const Point& v) {
    return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point& v) {
    return !(u == v);
}
