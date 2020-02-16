//
// Created by user on 14.02.2020.
//


#include <iostream>
#include "AComplex.h"
#include "TComplex.h"

#define DEBUG

using namespace std;

int AComplex::freeID = 0;

AComplex::AComplex(double real, double imaginary) : _real(real), _imaginary(imaginary), numberID(++freeID) {
#ifndef NDEBUG
    cout << "Created AComplex, id = " << numberID << ": " << *this << endl;
#endif
    return;
}

AComplex::AComplex(const AComplex &aComplex) : _real(aComplex.real()), _imaginary(aComplex.imaginary()),
                                               numberID(++freeID) {
#ifndef NDEBUG
    cout << "Copied AComplex, id = " << numberID << ": " << *this << endl;
#endif
    return;
}


AComplex::AComplex(const TComplex &tComplex) : _real(tComplex.real()), _imaginary(tComplex.imaginary()),
                                               numberID(++freeID) {
#ifndef NDEBUG
    cout << "Turned TComplex into AComplex, id = " << numberID << ": " << *this << endl;
#endif
    return;
}

AComplex::~AComplex() {
#ifndef NDEBUG
    cout << "Deleted AComplex, id = " << numberID << ": " << *this << endl;
#endif
}

AComplex &AComplex::operator=(const AComplex &another) {
    if (this == &another)
        return *this;

    imaginary() = another.imaginary();
    real() = another.real();

    return *this;
}

double AComplex::modR() const { return sqrt(_real * _real + _imaginary * _imaginary); }

double AComplex::phase() const { return tanh(_imaginary / _real); }


AComplex &operator+=(AComplex &first, const AComplex &second) {
    first.real() += second.real();
    first.imaginary() += second.imaginary();
    return first;
}

AComplex &operator-=(AComplex &first, const AComplex &second) {
    first.real() -= second.real();
    first.imaginary() -= second.imaginary();
    return first;
}

AComplex &operator*=(AComplex &first, const AComplex &second) {
    double tempReal = first.real();
    double tempImaginary = first.imaginary();
    first.real() *= second.real();
    first.real() -= tempImaginary * second.imaginary();
    first.imaginary() *= second.real();
    first.imaginary() += tempReal * second.imaginary();
    return first;
}

AComplex &operator/=(AComplex &a, const AComplex &b) {
    double tempReal = a.real();
    double tempImaginary = a.imaginary();
    a.real() *= b.real();
    a.real() += tempImaginary * b.imaginary();
    a.real() /= b.real() * b.real() + b.imaginary() * b.imaginary();
    a.imaginary() *= b.real();
    a.imaginary() -= tempReal * b.imaginary();
    a.imaginary() /= (b.real() * b.real() + b.imaginary() * b.imaginary());
    return a;

}


const AComplex operator+(const AComplex &first, const AComplex &second) {
    AComplex result(first);
    result += second;
    return result;
}

const AComplex operator-(const AComplex &first, const AComplex &second) {
    AComplex result(first);
    result -= second;
    return result;
}

const AComplex operator*(const AComplex &first, const AComplex &second) {
    cout << "entered" << endl;

    AComplex res(first);
    return res *= second;
}

const AComplex operator/(const AComplex &first, const AComplex &second) {
    AComplex res(first);
    return res /= second;
}

bool operator==(const AComplex &first, const AComplex &second) {
    return first.real() == second.real() && first.imaginary() == second.imaginary();
}

bool operator!=(const AComplex &first, const AComplex &second) {
    return !(first == second);
}

ostream &operator<<(ostream &os, const AComplex &number) {
    os << "AComplex number (id = " << number.getID() << "): " << number.real()
       << (number.imaginary() >= 0.0 ? " + " : " - ") << abs(number.imaginary()) << "i";

    return os;
}







