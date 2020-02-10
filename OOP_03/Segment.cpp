#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Segment.h"
#include "Point.h"

int Triangle::Segment::_freeID = 0;
int Segment::_freeID = 0;

Triangle::Segment::Segment(const Point &start, const Point &end) : _a(start), _b(end), _myId(++_freeID) {
#ifndef DEBUG
    cout << "Created " << *this << endl;
#endif
    return;
}

Triangle::Segment::Segment(const Triangle::Segment &copy) : _a(copy.start()), _b(copy.end()), _myId(++_freeID) {
#ifndef DEBUG
    cout << "Copied " << *this << endl;
#endif
    return;

}

Triangle::Segment::~Segment() {
#ifndef NDEBUG
    cout << "Deleted " << *this << endl;
#endif
    return;
}

double Triangle::Segment::length() const {
    return sqrt(pow(_a.x() - _b.x(), 2) + pow(_a.y() - _b.y(), 2));
}

double Triangle::Segment::distance(const Point& point) const {
    double A = _a.x() - _b.x();
    double B = _b.y() - _a.x();
    double C = _a.x() * _b.y() - _b.x() * _a.y();
    if (A == 0)
        return fabs((B * point.y() + C) / B);
    else if (B == 0)
        return fabs((A * point.x() + C) / A);
    return fabs((A * point.x() + B * point.y() + C) / sqrt(A * A + B * B));
}

ostream &operator<<(ostream &os, const Triangle::Segment &segment) {
    os << " Segment [" << segment.start() << ", " << segment.end() << "], ID = " << segment.getID() ;
    return os;
}

