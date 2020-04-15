//
// Created by user on 14.04.2020.
//

#include "Segment.h"


class Trapezium {
private:

public:

    virtual const Point &apexA() const = 0;
    virtual const Point &apexB() const = 0;
    virtual const Point &apexC() const = 0;
    virtual const Point &apexD() const = 0;


    virtual const Segment &side_a() const = 0;
    virtual const Segment &side_b() const = 0;
    virtual const Segment &side_c() const = 0;
    virtual const Segment &side_d() const = 0;

    virtual const Segment &midsegment() const = 0;


    virtual double length_a() const = 0;
    virtual double length_b() const = 0;
    virtual double length_c() const = 0;
    virtual double length_d() const = 0;

    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    virtual Trapezium  &mirrorX() = 0;
    virtual Trapezium &mirrorY() = 0;

    virtual Trapezium& turn(double angle) = 0;

};

ostream &operator<<(ostream &, const Trapezium &);

