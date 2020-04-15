//
// Created by user on 11.04.2020.
//

#include "Segment.h"

class TrapeziumBase;

class TrapeziumAxes {
private:
    Point _a, _b, _c, _d;
    mutable Segment *_ab, *_bc, *_cd, *_da, *_midsegment;

    Point *_midsegmentStart, *_midsegmentEnd;
public:
    class BadTrapeziumAxes;

    TrapeziumAxes(const Point &a, const Point &b, const Point &c, const Point &d);

    TrapeziumAxes(const TrapeziumAxes &);

    explicit TrapeziumAxes(const TrapeziumBase &);

    ~TrapeziumAxes();

    const Point &apexA() const;
    const Point &apexB() const;
    const Point &apexC() const;
    const Point &apexD() const;

    const Point & midsegmentStart();
    const Point & midsegmentEnd();

    const Segment &side_a() const;
    const Segment &side_b() const;
    const Segment &side_c() const;
    const Segment &side_d() const;

    const Segment & midsegment();

    double length_a() const;
    double length_b() const;
    double length_c() const;
    double length_d() const;

    double perimeter() const;
    double area() const;


    TrapeziumAxes &mirrorX();
    TrapeziumAxes &mirrorY();

    TrapeziumAxes& turn(double angle);

};

ostream &operator<<(ostream &, const TrapeziumAxes &);

typedef TrapeziumAxes &(TrapeziumAxes::* const TrapeziumAxesMirrorActions)();
void mirrorTrapeziumAxes(TrapeziumAxes & trapeziumAxes, TrapeziumAxesMirrorActions action);

class TrapeziumAxes::BadTrapeziumAxes {
private:
    string _errorMessage;
public:
    explicit BadTrapeziumAxes(string reason = "") :
            _errorMessage(reason) {
    };

    ~BadTrapeziumAxes() {
#ifndef NDEBUG

        cout << "Deleted error message" << endl;
#endif

    };

    void showMessage() const {
        cerr << "Bad Trapezium Axes error: " << _errorMessage << endl;
    }
};
