//
// Created by user on 11.04.2020.
//

#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"
#include "Segment.h"
#include <cmath>

TrapeziumAxes::TrapeziumAxes(const Point &a, const Point &b, const Point &c, const Point &d) :
        _ab(nullptr),
        _bc(nullptr),
        _cd(nullptr),
        _da(nullptr), _midsegmentStart(nullptr), _midsegmentEnd(nullptr) {
    if ((a.x() == b.x() == c.x()) || (a.x() == b.x() == d.x()) || (b.x() == c.x() == d.x()) || (a.y() == b.y() == c.y())
        || (c.y() == b.y() == d.y())) {
        throw BadTrapeziumAxes("Three of the points are on the same segment");
    }

    _a = a;
    _b = b;
    _c = c;
    _d = d;

#ifndef NDEBUG
    cout << "Created trapezium axes " << *this << endl;
#endif

}

TrapeziumAxes::TrapeziumAxes(const TrapeziumAxes &other) : _a(other.apexA()), _b(other.apexB()),
                                                           _c(other.apexC()), _d(other.apexD()), _ab(nullptr),
                                                           _bc(nullptr), _cd(nullptr), _da(nullptr),
                                                           _midsegmentStart(nullptr), _midsegmentEnd(nullptr), _midsegment(nullptr) {

#ifndef NDEBUG
    cout << "Coped trapezium axes: " << *this << endl;
#endif
}

TrapeziumAxes::TrapeziumAxes(const TrapeziumBase &trapeziumBase) : _a(trapeziumBase.apexA()), _b(trapeziumBase.apexB()),
                                                                   _c(trapeziumBase.apexC()), _d(trapeziumBase.apexD()),
                                                                   _ab(nullptr), _bc(nullptr), _cd(nullptr),
                                                                   _da(nullptr), _midsegmentStart(nullptr),
                                                                   _midsegmentEnd(nullptr), _midsegment(nullptr) {

#ifndef NDEBUG
    cout << "Converted trapezium base to trapezium axe " << *this << endl;
#endif
}


TrapeziumAxes::~TrapeziumAxes() {
#ifndef NDEBUG
    cout << "Deleted trapezium axes " << *this << endl;
#endif
}

const Point &TrapeziumAxes::apexA() const {
    return _a;
}

const Point &TrapeziumAxes::apexB() const {
    return _b;
}

const Point &TrapeziumAxes::apexC() const {
    return _c;
}

const Point &TrapeziumAxes::apexD() const {
    return _d;
}

const Segment &TrapeziumAxes::side_a() const {
    if (_bc == nullptr)
        _bc = new Segment(_b, _c);
    return *_bc;
}

const Segment &TrapeziumAxes::side_b() const {
    if (_cd == nullptr)
        _cd = new Segment(_c, _d);
    return *_cd;
}


const Segment &TrapeziumAxes::side_c() const {
    if (_da == nullptr)
        _da = new Segment(_a, _d);
    return *_da;
}


const Segment &TrapeziumAxes::side_d() const {
    if (_ab == nullptr)
        _ab = new Segment(_a, _b);
    return *_ab;
}

double TrapeziumAxes::length_a() const {
    return side_a().length();
}

double TrapeziumAxes::length_b() const {
    return side_b().length();
}

double TrapeziumAxes::length_c() const {
    return side_c().length();
}

double TrapeziumAxes::length_d() const {
    return side_d().length();
}

double TrapeziumAxes::perimeter() const {

    return length_a() + length_b() + length_c() + length_d();
}


double TrapeziumAxes::area() const {

    double height = sqrt(pow(length_d(), 2) -
                         pow(((pow((length_c() - length_a()), 2) + pow(length_d(), 2) - pow(length_b(), 2)) /
                              (2 * (length_c() - length_a()))), 2));


    return ((length_a() + length_c()) / 2) * height;
}

TrapeziumAxes &TrapeziumAxes::mirrorX() {

    _a.mirrorX();
    _b.mirrorX();
    _c.mirrorX();
    _d.mirrorX();
    return *this;
}

TrapeziumAxes &TrapeziumAxes::mirrorY() {

    _a.mirrorY();
    _b.mirrorY();
    _c.mirrorY();
    _d.mirrorY();
    return *this;
}

TrapeziumAxes &TrapeziumAxes::turn(double angle) {

    _a.turn(angle);
    _b.turn(angle);
    _c.turn(angle);
    _d.turn(angle);
    return *this;
}

const Point &TrapeziumAxes::midsegmentStart() {
    if (_midsegmentStart == nullptr)
        _midsegmentStart = new Point(((_a.x() + _b.x()) / 2), ((_a.y() + _b.y()) / 2));
    return *_midsegmentStart;
}

const Point &TrapeziumAxes::midsegmentEnd() {
    if (_midsegmentEnd == nullptr)
        _midsegmentEnd = new Point(((_c.x() + _d.x()) / 2), ((_c.y() + _d.y()) / 2));
    return *_midsegmentEnd;
}

const Segment & TrapeziumAxes::midsegment() {
    if (_midsegment == nullptr)
        _midsegment = new Segment(midsegmentStart(), midsegmentEnd());
    return *_midsegment;
}

void mirrorTrapeziumAxes(TrapeziumAxes &trapeziumAxes, TrapeziumAxesMirrorActions action) {
    (trapeziumAxes.*action)();
}


ostream &operator<<(ostream &os, const TrapeziumAxes &trapeziumAxes) {
    os << "Trapezium (Axes) with vertexes A: " << trapeziumAxes.apexA() << ", B: " << trapeziumAxes.apexB() << ", C: "
       << trapeziumAxes.apexC() << ", D: " << trapeziumAxes.apexD();
    return os;
}
