//
// Created by user on 29.03.2020.
//

#include <iostream>
#include "Array.h"
#include "cassert"

using namespace std;


int main() {

    Array<5, int> test1 = Array<5, int>();
    cout << "Simple empty array: " << test1 << endl;
    assert(test1.length() == 5);
    for (size_t i = 0; i < test1.length(); i++) {
        test1[i] = static_cast<int>(i);
    }
    cout << "Simple array: " << test1 << endl;


    Array<5, int> test2 = Array<5, int>();
    int position = 0;
    for (size_t i = test2.length() - 1; i > 0; i--) {
        test2[position++] = static_cast<int>(i);
    }
    cout << "Simple reversed array: " << test2 << endl;

    cout << endl << "Testing assignment: " << endl;
    test2 = test1;
    cout << test2 << endl;

    try {
        cout << "Testing index out of the bound error: " << endl;
        cout << test1[6];
    } catch (Array<5, int>::BadArray &error) {
        error.diagnose();
    }
    cout << endl << "Adding element of another type (double will be casted to int for array of ints)" << endl;
    test1[0] = 11.5;
    cout << test1 << endl;

    Array<10, double> test3 = Array<10, double>();
    for (size_t i = 0; i < 10; i++) {
        test3[i] = static_cast<double>(i) / 0.3;
    }

    cout << endl << "Adding element of int to double array" << endl;
    cout << test3 << endl;
    try {
        test3[10] = 0;
    } catch (Array<10, double>::BadArray & error) {
        error.diagnose();
    }
    return 0;
}