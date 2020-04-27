//
// Created by user on 08.02.2020.
//


#include <iostream>
#include "Segment.h"

using namespace std;

int Segment::_freeID = 0;


Segment::Segment(const double x1, const double y1,

                 const double x2, const double y2): _start(x1, y1), _end(x2, y2), _myId(++_freeID){

#ifdef DEBUG
    cout << "Created segment " << _myId << ": << this << endl;
#endif
}


Segment::Segment(const Point& start, const Point& end): _start(start.x(), start.y()), _end(end.x(), end.y()), _myId(++_freeID){

#ifdef DEBUG
    cout << "Created segment " << _myId << ": << this << endl;
#endif
}


Segment::Segment(const Segment& copy): _start(copy.start()), _end(copy.end()), _myId(++_freeID){
#ifdef DEBUG
    cout << "Copied segment " << _myId << ": << this << endl;
#endif
}

Segment::~Segment() {
#ifndef NDEBUG
    cout << "Deleted " << *this << endl;
#endif
}


Segment& Segment::operator=(const Segment& newSegment){

    if (this == &newSegment)
        return *this;

    _start = newSegment.start();
    _end = newSegment.end();
    return *this;
}


const Point& Segment::start() const {
    return _start;
}

const Point& Segment::end() const {
    return _end;
}


Point& Segment::start() {
    return _start;
}

Point& Segment::end() {
    return _end;
}


const double& Segment::startX() const {
    return _start.x();
}

const double& Segment::startY() const {
    return _start.y();
}

const double& Segment::endX() const {
    return _end.x();
}

const double& Segment::endY() const {
    return _end.y();
}


double& Segment::startX() {
    return _start.x();
}

double& Segment::startY() {
    return _start.y();
}

double& Segment::endX() {
    return _end.x();
}

double& Segment::endY() {
    return _end.y();
}

double Segment::length() const {

    return sqrt(pow(_start.x() - _end.x(), 2) + pow(_start.y() - _end.y(), 2));
}

/* Формула прямої: Ax + By + C = 0;
Тоді відстань від точки можна знайти за формулою: d = |A*Mx + B*My + C|/((A^2 + B^2)^1/2) */

double Segment::distance(const Point& point) const {
    double A = _start.x() - _end.x();
    double B = _end.y() - _start.x();
    double C = _start.x() * _end.y() - _end.x() * _start.y();
    if (A == 0)
        return fabs((B * point.y() + C) / B);
    else if (B == 0)
        return fabs((A * point.x() + C) / A);
    return fabs((A * point.x() + B * point.y() + C) / sqrt(A * A + B * B));
}


ostream& operator<<(ostream& os, const Segment& segment) {
    os << "[" << segment.start() << ", " << segment.end() << "], ID = " << segment.getID() << endl;
    return os;
}


double distance(const Segment& segment, const Point& point) {
    return segment.distance(point);
}