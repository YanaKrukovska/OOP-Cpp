//
// Created by user on 14.02.2020.
//


#ifndef C_TCOMPLEX_H
#define C_TCOMPLEX_H

#pragma once

#include <iostream>

using namespace std;

class AComplex;

class TComplex {
private:
    double _r, _phase;
    static int freeID;
    const int numberID;

public:
    TComplex(double r = 0, double phase = 0);

    TComplex(const TComplex &);

    TComplex(const AComplex &);

    ~TComplex();

    TComplex &operator=(const TComplex &);

    double &modR() { return _r; }

    double &phase() { return _phase; }

    const double &modR() const { return _r; }

    const double &phase() const { return _phase; }

    double real() const { return _r * cos(_phase); }

    double imaginary() const { return _r * sin(_phase); }

    const int getID() const { return numberID; }

};

TComplex &operator+=(TComplex &, const TComplex &);

TComplex &operator-=(TComplex &, const TComplex &);

TComplex &operator*=(TComplex &, const TComplex &);

TComplex &operator/=(TComplex &, const TComplex &);

const TComplex operator*(const TComplex &, const TComplex &);

const TComplex operator/(const TComplex &, const TComplex &);


ostream &operator<<(ostream &, const TComplex &);

#endif //C_TCOMPLEX_H
