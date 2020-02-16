//
// Created by user on 14.02.2020.
//

#include <iostream>
#include "TComplex.h"
#include "AComplex.h"

#define DEBUG

using namespace std;

int TComplex::freeID = 0;

TComplex::TComplex(double r, double phase) : _r(r), _phase(phase), numberID(++freeID) {
#ifndef NDEBUG
    cout << "Created TComplex, id = " << numberID << ": " << *this << endl;
#endif

    return;
}

TComplex::TComplex(const TComplex &tComplex) : _r(tComplex.modR()), _phase(tComplex.phase()),
                                               numberID(++freeID) {
#ifndef NDEBUG
    cout << "Created TComplex, id = " << numberID << ": " << *this << endl;
#endif

    return;
}

TComplex::TComplex(const AComplex &aComplex) : _r(aComplex.modR()), _phase(aComplex.phase()),
                                               numberID(++freeID) {
#ifndef NDEBUG
    cout << "Turned AComplex into TComplex, id = " << numberID << ": " << *this << endl;
#endif
    return;
}

TComplex::~TComplex() {
#ifndef NDEBUG
    cout << "Deleted TComplex, id = " << numberID << ": " << *this << endl;
#endif
}

TComplex &TComplex::operator=(const TComplex &another) {
    if (this == &another)
        return *this;

    modR() = another.modR();
    phase() = another.phase();

    return *this;
}


TComplex &operator+=(TComplex &first, const TComplex &second) {

    AComplex aComplex1(first);
    AComplex aComplex2(second);
    aComplex1 += aComplex2;
    first = TComplex(aComplex1);
    return first;
}

TComplex &operator-=(TComplex &first, const TComplex &second) {
    AComplex aComplex1(first);
    AComplex aComplex2(second);
    aComplex1 -= aComplex2;
    first = TComplex(aComplex1);
    return first;
}


TComplex& operator*=(TComplex& first, const TComplex& second)
{
    first.modR() *= second.modR();
    first.phase() += second.phase();
    return first;
}

TComplex& operator/= (TComplex &first, const TComplex &second)
{
    first.modR() /= second.modR();
    first.phase() -= second.phase();
    return first;
}


const TComplex operator*(const TComplex &first, const TComplex &second) {
    return TComplex(first.modR() * second.modR(), first.phase() + second.phase());

}

const TComplex operator/(const TComplex &first, const TComplex &second) {
    return TComplex(first.modR() / second.modR(), first.phase() - second.phase());
}


ostream &operator<<(ostream &os, const TComplex &complexNumber) {
    os << "TComplex number (id = " << complexNumber.getID() << "): " << complexNumber.modR() << "(cos("
       << complexNumber.phase() << ") + i*sin(" << complexNumber.phase() << "))";
    return os;
}

