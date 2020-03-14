#include <iostream>
#include "String.h"
#include "cassert"

using namespace std;

int main() {

    // Testing constructors
    String test1("test ");
    String test2('T');
    String test3(string("test"));
    int multipl = 3;
    String test4(test1, multipl);
    String test5(test3);

    cout << "char[]: " << test1 << endl;
    cout << "char: " << test2 << endl;
    cout << "string: " << test3 << endl;
    cout << "copied and multiplied string: " << test4 << endl;
    cout << "copied string: " << test5 << endl;

    //Testing == and !=
    assert((test3 == test5) == 1);
    assert((test3 != test5) == 0);
    assert((test1 == test4) == 0);
    assert((test1 != test4) == 1);

    //Testing <, >, <= and >=
    String test6('A');
    assert((test2 > test6) == 1); // T > A
    assert((test2 < test6) == 0); // T > A

    assert((test2 <= test2) == 1); // T == T
    assert((test2 >= test2) == 1); // T == T

    //Testing + and +=
    String result("test T");
    String resultExpected(test1 + test2);
    cout << endl << "Result of test1 + test2: " << resultExpected << endl;
    assert(resultExpected == result);

    result = "test test T";
    cout << "Result of test1 += resultExpected: " << (test1 += resultExpected) << endl;
    assert(test1 == result);

    //Testing =
    test1 = String("String");
    test2 = string("std::string");
    test3 = "C-string";
    test4 = 'C';

    cout << "String: " << test1 << endl;
    cout << "std::string: " << test2 << endl;
    cout << "C-string: " << test3 << endl;
    cout << "char: " << test4 << endl;

    cout << endl << "Testing getters" << endl;
    cout << "std::string: " << test1.STL_string() << endl;
    cout << "C-string: " << test1.c_str() << endl;

    //Testing length
    assert(test1.length() == 6);

    //Testing empty and clear
    assert(test5.empty() == 0);
    test5.clear();
    assert(test5.empty() == 1);

    // Testing [] access
    try {
        cout << "test3: " << test3 << endl;
        cout << "test3[1]: " << test3[1] << endl;
        test3[1] = '_';
        cout << "test3[1]: " << test3[1] << endl;
        cout << "test3: " << test3 << endl;
    } catch (String::BadIndex &e) {
        e.showMessage();
    }

    //Will catch a Bad Index
    try {
        cout << test3[test3.length()] << endl;
    } catch (String::BadIndex &error) {
        error.showMessage();
    }

    //Will catch a Bad String
    try {
        String badString(nullptr);
        cout << badString << endl;
    } catch (String::BadString &error) {
        error.showMessage();
    }

    return 0;
}