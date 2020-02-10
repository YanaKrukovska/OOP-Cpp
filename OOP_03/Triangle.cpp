#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Segment.h"


Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
        : _a(x1, y1), _b(x2, y2), _c(x3, y3), _ab(nullptr), _bc(nullptr), _ca(nullptr) {
#ifndef DEBUG
    cout << "Created " << *this << endl;
#endif
    return;
}


Triangle::Triangle(const Point &a, const Point &b, const Point &c) : _a(a), _b(b), _c(c), _ab(nullptr), _bc(nullptr),
                                                                     _ca(nullptr) {
#ifndef DEBUG
    cout << "Created " << *this << endl;
#endif
    return;
}

Triangle::Triangle(const Triangle &copy) : _a(copy.apexA()), _b(copy.apexB()), _c(copy.apexC()),
                                           _ab(nullptr), _bc(nullptr), _ca(nullptr) {
#ifndef DEBUG
    cout << "Copied " << *this << endl;
#endif
    return;
}


Triangle::~Triangle() {
    if (_ab != nullptr)
        delete _ab;
    if (_bc != nullptr)
        delete _bc;
    if (_ca != nullptr)
        delete _ca;

#ifndef DEBUG
    cout << "Deleted " << *this << endl;
#endif
    return;
}

Triangle &Triangle::operator=(const Triangle &otherTriangle) {
    _a = otherTriangle.apexA();
    _b = otherTriangle.apexB();
    _c = otherTriangle.apexC();

    if (_ab != nullptr)
        delete _ab;
    if (_bc != nullptr)
        delete _bc;
    if (_ca != nullptr)
        delete _ca;
    _ab = _bc = _ca = nullptr;
    return *this;
}

double Triangle::perimeter() const {
    return length_a() + length_b() + length_c();
}

double Triangle::area() const {
    double s = perimeter() / 2;
    return sqrt(s * (s - length_a()) * (s - length_b()) * (s - length_c()));
}

const Point &Triangle::apexA() const {
    return _a;
}

const Point &Triangle::apexB() const {
    return _b;
}

const Point &Triangle::apexC() const {
    return _c;
}

const Triangle::Segment &Triangle::side_a() const {
    if (_bc == nullptr)
        _bc = new Triangle::Segment(_b, _c);
    return *_bc;
}

const Triangle::Segment &Triangle::side_b() const {
    if (_ca == nullptr)
        _ca = new Triangle::Segment(_c, _a);
    return *_ca;
}

const Triangle::Segment &Triangle::side_c() const {
    if (_ab == nullptr)
        _ab = new Triangle::Segment(_a, _b);
    return *_ab;
}


double Triangle::length_a() const {
    return side_a().length();
}

double Triangle::length_b() const {
    return side_b().length();
}

double Triangle::length_c() const {
    return side_c().length();
}


const Triangle::Segment Triangle::median_a() const {
    double pointX = getMiddle(_b.x(), _c.x());
    double pointY = getMiddle(_b.y(), _c.y());
    return Segment(apexA(), Point(pointX, pointY));;
}


const Triangle::Segment Triangle::median_b() const {
    double pointX = getMiddle(_a.x(), _c.x());
    double pointY = getMiddle(_a.y(), _c.y());
    return Segment(apexB(), Point(pointX, pointY));;
}

const Triangle::Segment Triangle::median_c() const {
    double pointX = getMiddle(_a.x(), _b.x());
    double pointY = getMiddle(_a.y(), _b.y());
    return Segment(apexC(), Point(pointX, pointY));;
}

double Triangle::getMiddle(const double x, const double y) const {
    return (x + y) / 2;
}


ostream &operator<<(ostream &os, const Triangle &triangle) {
    os << "Triangle with vertexes A: " << triangle.apexA() << ", B: " << triangle.apexB() << ", C: "
       << triangle.apexC();
    return os;
}

