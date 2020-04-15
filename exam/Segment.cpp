//
// Created by user on 11.04.2020.
//



#include "Segment.h"

Segment::Segment(Point start, Point end) : _start(start.x(), start.y()), _end(end.x(), end.y()) {

#ifndef NDEBUG
    cout << "Created segment " << *this << endl;
#endif
}

Segment::Segment(double x1, double y1, double x2, double y2) : _start(x1, y1), _end(x2, y2) {

#ifndef NDEBUG
    cout << "Created segment " << *this << endl;
#endif


}

Segment::~Segment() {
#ifndef NDEBUG
    cout << "Deleted segment " << *this << endl;
#endif
}

double Segment::length() const {

    return sqrt(pow(_start.x() - _end.x(), 2) + pow(_start.y() - _end.y(), 2));
}

Segment &Segment::mirrorX() {
    _start = _start.mirrorX();
    _end = _end.mirrorX();
    return *this;
}

Segment &Segment::mirrorY() {

    _start = _start.mirrorY();
    _end = _end.mirrorY();

    return *this;
}

Segment &Segment::turn(double angle) {
    _start = _start.turn(angle);
    _end = _end.turn(angle);
    return *this;
}

void mirrorSegment(Segment &segment, SegmentMirrorActions action) {
    (segment.*action)();
}

ostream &operator<<(ostream &os, const Segment &segment) {
    os << "[" << segment.start() << ", " << segment.end() << "]" ;
    return os;
}



