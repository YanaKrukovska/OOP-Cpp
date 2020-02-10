#pragma once

#include <iostream>
#include "Point.h"
#include "Segment.h"

using namespace std;

class Segment;

class Triangle {
public:
    class Segment {
    private:
        const Point &_a;
        const Point &_b;
        static int _freeID;
        int _myId;

        Segment &operator=(const Segment &);

    public:

        Segment(const Point &start, const Point &end);

        ~Segment();

        const Point &start() const { return _a; };

        const Point &end() const { return _b; };

        double length() const;

        double distance(const Point &) const;

        int getID() const { return _myId; };

        Segment(const Segment &);
    };

    Triangle(const double x1 = 0, const double y1 = 0,
             const double x2 = 1, const double y2 = 0,
             const double x3 = 0, const double y3 = 1);

    Triangle(const Point &a, const Point &b, const Point &c);
    Triangle(const Triangle &);
    ~Triangle();

    Triangle &operator=(const Triangle &);

    double perimeter() const;
    double area() const;

    const Point &apexA() const;
    const Point &apexB() const;
    const Point &apexC() const;

    const Segment &side_a() const;
    const Segment &side_b() const;
    const Segment &side_c() const;

    double length_a() const;
    double length_b() const;
    double length_c() const;

    const Segment median_a() const;
    const Segment median_b() const;
    const Segment median_c() const;


private:
    Point _a, _b, _c;
    mutable Segment *_ab, *_bc, *_ca;

    double getMiddle(const double x, const double y) const;
};

ostream &operator<<(ostream &, const Triangle::Segment &);

ostream &operator<<(ostream &, const Triangle &);