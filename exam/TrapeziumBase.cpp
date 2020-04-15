//
// Created by user on 11.04.2020.
//

#include "TrapeziumBase.h"
#include "TrapeziumAxes.h"
#include "Segment.h"
#include <cmath>

TrapeziumBase::TrapeziumBase(const Segment &segment1, const Segment &segment2): _midsegment(nullptr) {

    if (segment1.length() == segment2.length()) {
        throw BadTrapeziumBase("The lengths of segments are equal");
    }

    _base1 = segment1;
    _base2 = segment2;
#ifndef NDEBUG
    cout << "Created trapezium base " << *this << endl;
#endif
}

TrapeziumBase::TrapeziumBase(const TrapeziumBase &other) : _base1(other.base1()), _base2(other.base2()), _midsegment(nullptr) {
#ifndef NDEBUG
    cout << "Copied trapezium base: " << *this << endl;
#endif
}

TrapeziumBase::TrapeziumBase(const TrapeziumAxes &trapeziumAxes) : _base1(trapeziumAxes.side_a()),
                                                                   _base2(trapeziumAxes.side_c()), _midsegment(nullptr) {

#ifndef NDEBUG
    cout << "Converted trapezium axe to trapezium base " << *this << endl;
#endif
}


TrapeziumBase::~TrapeziumBase() {
#ifndef NDEBUG
    cout << "Deleted trapezium base " << *this << endl;
#endif
}

const Segment &TrapeziumBase::base1() const {
    return _base1;
}

const Segment &TrapeziumBase::base2() const {
    return _base2;
}


const Point &TrapeziumBase::apexA() const {
    return _base2.start();
}

const Point &TrapeziumBase::apexB() const {
    return _base1.start();
}

const Point &TrapeziumBase::apexC() const {
    return _base1.end();
}

const Point &TrapeziumBase::apexD() const {
    return _base2.end();
}

const Segment &TrapeziumBase::side_1() {
    if (_side1 == nullptr)
        _side1 = new Segment(apexA(), apexB());
    return *_side1;
}

const Segment &TrapeziumBase::side_2() {
    if (_side2 == nullptr)
        _side2 = new Segment(apexC(), apexD());
    return *_side2;
}


double TrapeziumBase::length_base1() const {
    return base1().length();
}

double TrapeziumBase::length_side1() {
    return side_2().length();

}

double TrapeziumBase::length_base2() const {
    return base2().length();
}

double TrapeziumBase::length_side2() {
    return side_1().length();
}

double TrapeziumBase::perimeter() {
    return length_base1() + length_base2() + length_side1() + length_side2();
}

double TrapeziumBase::area() {

    double height = sqrt(pow(length_side1(), 2) -
                         pow(((pow((length_base2() - length_base1()), 2) + pow(length_side1(), 2) -
                               pow(length_side2(), 2)) /
                              (2 * (length_base2() - length_base1()))), 2));


    return ((length_base1() + length_base2()) / 2) * height;
}


TrapeziumBase &TrapeziumBase::mirrorX() {

    _base1.mirrorX();
    _base2.mirrorX();

    return *this;
}

TrapeziumBase &TrapeziumBase::mirrorY() {

    _base1.mirrorY();
    _base2.mirrorY();
    return *this;
}

TrapeziumBase &TrapeziumBase::turn(double angle) {
    _base1.turn(angle);
    _base2.turn(angle);
    return *this;
}

const Segment &TrapeziumBase::midsegment() {
    if (_midsegment == nullptr)
        _midsegment = new Segment((apexA().x() + apexB().x())/2, (apexA().y() + apexB().y())/2, ((apexC().x() + apexD().x())/2), ((apexC().y() + apexD().y())/2));
    return *_midsegment;
}

void mirrorTrapeziumBase(TrapeziumBase &trapeziumBase, TrapeziumBaseMirrorActions action) {
    (trapeziumBase.*action)();
}


ostream &operator<<(ostream &os, const TrapeziumBase &trapeziumBase) {
    os << "Trapezium (bases) with bases A: " << trapeziumBase.base1() << ", B: " << trapeziumBase.base2();
    return os;
}