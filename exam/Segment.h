//
// Created by user on 11.04.2020.
//

#ifndef C_SEGMENT_H
#define C_SEGMENT_H


#include "Point.h"

class Segment {

private:
    Point _start, _end;
public:

    Segment(Point, Point);

    explicit Segment(double = 0, double y1 = 0, double x2 = 0, double y2 = 0);

    ~Segment();

    double length() const;

    Point &start() { return _start; };

    Point &end() { return _end; };

    const Point &start() const { return _start; };

    const Point &end() const { return _end; };

    Segment &mirrorX();

    Segment &mirrorY();

    Segment &turn(double angle);

};

ostream &operator<<(ostream &, const Segment &);

typedef Segment &(Segment::* const SegmentMirrorActions)();

void mirrorSegment(Segment &segment, SegmentMirrorActions action);

#endif //C_SEGMENT_H
