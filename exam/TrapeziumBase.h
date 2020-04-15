//
// Created by user on 11.04.2020.
//


#include "Segment.h"

using namespace std;


class TrapeziumAxes;

class TrapeziumBase {
private:
    Segment _base1, _base2;
    Segment *_side1{}, *_side2{};
    Segment *_midsegment;

public:

    class BadTrapeziumBase;

    TrapeziumBase(const Segment &segment1, const Segment &segment2);

    TrapeziumBase(const TrapeziumBase &);

    explicit TrapeziumBase(const TrapeziumAxes &trapeziumAxes);

    ~TrapeziumBase();

    const Segment &base1() const;

    const Segment &base2() const;

    const Segment &side_1();

    const Segment &side_2();

    const Segment &midsegment();

    const Point &apexA() const;

    const Point &apexB() const;

    const Point &apexC() const;

    const Point &apexD() const;

    double length_base1() const;

    double length_base2() const;

    double length_side1();

    double length_side2();

    double perimeter();

    double area();

    TrapeziumBase &mirrorX();

    TrapeziumBase &mirrorY();

    TrapeziumBase &turn(double angle);
};

ostream &operator<<(ostream &, const TrapeziumBase &);

typedef TrapeziumBase &(TrapeziumBase::* const TrapeziumBaseMirrorActions)();

void mirrorTrapeziumBase(TrapeziumBase &trapeziumBase, TrapeziumBaseMirrorActions action);

class TrapeziumBase::BadTrapeziumBase {
private:
    string _errorMessage;
public:
    explicit BadTrapeziumBase(string reason = "") :
            _errorMessage(reason) {
    };

    ~BadTrapeziumBase() {
#ifndef NDEBUG

        cout << "Deleted error message" << endl;
#endif

    };

    void showMessage() const {
        cerr << "Bad Trapezium Base error: " << _errorMessage << endl;
    }
};