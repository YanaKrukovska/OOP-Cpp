#include <iostream>
#include <cassert>
#include "Date.h"

using namespace std;

int main() {

    cout << "START" << endl;

    cout << endl << "Testing default date:" << endl;
    try {
        //Expected - current date
        Date::showDefault();
        Date::setDefault(01, Date::Month(04), 1989);
        //Expected - 01.04.1989
        Date::showDefault();
        Date::setDefault();
        //Expected - current date
        Date::showDefault();
        cout << endl;
    }
    catch (Date::BadDate &badDate) {
        cerr << "Bad date: " << badDate << endl;
    }


    cout << "Testing creation of dates:" << endl;
    try {
        Date date1(01, 01, 2020);
        Date date2(01, Date::Month(03), 2016);
        Date date3(date1);
        cout << date1 << "\n" << date2 << "\n" << date3 << endl;
        Date badDate(84, 14, 2008);

    }
    catch (Date::BadDate &bd) {
        cerr << "Bad date: " << bd << endl;
    }

    cout << endl << "Testing operation ++ " << endl;
    try {
        Date date1(31, 12, 2019);
        Date date2(28, Date::Month(02), 2019);
        Date date3(30, 4, 2019);

        cout << date1++ << "++: " << date1 << endl;
        assert(date1.day() == 1);
        assert(date1.month() == 1);
        assert(date1.year() == 2020);

        cout << date2++ << "++: " << date2 << endl;
        assert(date2.day() == 1);
        assert(date2.month() == 3);
        assert(date2.year() == 2019);

        date2.setDay(28);
        date2.setMonth(2);
        date2.setYear(2020);
        cout << date2++ << "++: " << date2 << endl;
        assert(date2.day() == 29);
        assert(date2.month() == 2);
        assert(date2.year() == 2020);

        cout << date3++ << "++: " << date3 << endl;
        assert(date3.day() == 1);
        assert(date3.month() == 5);

        date3.setDay(30);
        cout << date3++ << "++: " << date3 << endl;
        assert(date3.day() == 31);
        assert(date3.month() == 5);
    }
    catch (Date::BadDate &bd) {
        cerr << "Bad date: " << bd << endl;
    }


    cout << endl << "Testing operation -- " << endl;
    try {
        Date date1(01, 01, 2020);
        Date date2(01, Date::Month(03), 2016);
        Date date3(01, 4, 2019);

        cout << date1-- << "--: " << date1 << endl;
        assert(date1.day() == 31);
        assert(date1.month() == 12);
        assert(date1.year() == 2019);

        cout << date2-- << "--: " << date2 << endl;
        assert(date2.day() == 29);
        assert(date2.month() == 2);
        assert(date2.year() == 2016);

        date2.setDay(1);
        date2.setMonth(3);
        date2.setYear(2019);
        cout << date2-- << "--: " << date2 << endl;
        assert(date2.day() == 28);
        assert(date2.month() == 2);
        assert(date2.year() == 2019);

        cout << date3-- << "--: " << date3 << endl;
        assert(date3.day() == 31);
        assert(date3.month() == 3);

        date3.setDay(1);
        date3.setMonth(5);
        cout << date3-- << "--: " << date3 << endl;
        assert(date3.day() == 30);
        assert(date3.month() == 4);


    }
    catch (Date::BadDate &bd) {
        cerr << "Bad date: " << bd << endl;
    }

    //Testing get methods
    Date test1(5, 4, 2019);
    assert(test1.day() == 5);
    assert(test1.month() == Date::Month(04));
    assert(test1.year() == 2019);
    assert(test1.getMonthName() == "Apr");

    //Testing set methods
    test1.setDay(1);
    test1.setMonth(3);
    test1.setYear(2020);
    assert(test1.day() == 1);
    assert(test1.month() == Date::Month(03));
    assert(test1.year() == 2020);

    // Testing leap years
    assert(Date::isLeapYear(1600) == 1);
    assert(Date::isLeapYear(2020) == 1);
    assert(Date::isLeapYear(2019) == 0);
    assert(Date::isLeapYear(1992) == 1);
    assert(Date::isLeapYear(1900) == 0);
    assert(Date::isLeapYear(1488) == 1);


    cout << endl << "END" << endl;
    return 0;
}

