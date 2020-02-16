//
// Created by user on 14.02.2020.
//
#ifndef C_ACOMPLEX_H
#define C_ACOMPLEX_H

#pragma once

#include <iostream>
#include "TComplex.h"

using namespace std;

class TComplex;

class AComplex {

private :
    double _real, _imaginary;
    static int freeID;
    const int numberID;


public:

    AComplex(double _real = 0, double _imaginary = 0);

    AComplex(const TComplex &);

    AComplex(const AComplex &);

    ~AComplex();

    AComplex &operator=(const AComplex &);

    double &real() { return _real; }

    double &imaginary() { return _imaginary; }

    double real() const { return _real; }

    double imaginary() const { return _imaginary; }

    double modR() const;

    double phase() const;


    const int getID() const {
        return numberID;
    }

    static int amount() {
        return freeID;
    }

};

AComplex &operator+=(AComplex &, const AComplex &);

AComplex &operator-=(AComplex &, const AComplex &);

AComplex &operator*=(AComplex &, const AComplex &);

AComplex &operator/=(AComplex &, const AComplex &);

const AComplex operator+(const AComplex &, const AComplex &);

const AComplex operator-(const AComplex &, const AComplex &);

bool operator==(const AComplex &, const AComplex &);

bool operator!=(const AComplex &, const AComplex &);

ostream &operator<<(ostream &, const AComplex &);


#endif //C_ACOMPLEX_H
