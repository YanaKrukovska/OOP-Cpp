//
// Created by user on 14.02.2020.
//

#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
#include "cassert"

using namespace std;


int main() {

    // ACOMPLEX

    //Testing constructors
    AComplex a1(2, 4);
    AComplex a2(2, -2);
    AComplex a3(a1);

    //Testing + and -
    assert(a1 + a1 == AComplex(a1.real() + a1.real(), a1.imaginary() + a1.imaginary()));
    assert(a1 - a1 == AComplex(a1.real() - a1.real(), a1.imaginary() - a1.imaginary()));

    //Testing equality
    assert((a1 == a1) == 1);
    assert((a1 == a2) == 0);
    assert((a1 != a1) == 0);
    assert((a1 != a2) == 1);

    //Testing operator =
    assert((a3 = a2) == a2);


    // TCOMPLEX

    //Testing constructors
    TComplex t1(2, 4);
    TComplex t2(2, -2);
    TComplex t3(t1);

    //Testing * and /
    assert((t1 * t1) == TComplex(t1.modR() * t1.modR(), t1.phase() + t1.phase()));
    assert((t1 / t1) == TComplex(t1.modR() / t1.modR(), t1.phase() - t1.phase()));

    //Testing equality
    assert((t1 == t1) == 1);
    assert((t1 == t2) == 0);
    assert((t1 != t1) == 0);
    assert((t1 != t2) == 1);

    //Testing operator =
    assert((t3 = t2) == t2);

    // MIXED TYPES

    //TComplex constructed from AComplex
    AComplex a4(1, 1);
    TComplex t4(a4);

    //Showing how AComplex numbers turn into TComplex for * and / and TComplex turn into AComplex for + and -
    cout << "AComplex * AComplex: " << a1 * a4 << endl;
    cout << "AComplex / AComplex: " << a1 * a4 << endl;
    cout << "TComplex + TComplex: " << t1 * t4 << endl;
    cout << "TComplex - TComplex: " << t1 * t4 << endl;

}

