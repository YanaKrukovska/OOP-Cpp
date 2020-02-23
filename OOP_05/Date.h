//
// Created by user on 22.02.2020.
//
#ifndef C_DATE_H
#define C_DATE_H
#pragma once

#include <iostream>

using namespace std;

class Date {

public:

    struct BadDate;

// to avoid problem 7.2.2002 7 feb or jul 2?

    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    explicit Date(int d = 0, Month m = Month(0), int y = 0);

    Date(int d, int m, int y);

    Date(const Date &);

    ~Date();

    int day() const {
        return _day;
    }

    Month month() const {
        return Month(_month);
    }

    int year() const {
        return _year;
    }

    const string getMonthName() const {
        return monthNames[_month - 1];
    }

    void setDay(int);

    void setMonth(int);

    void setYear(int);

    static void setDefault(int d, Month m, int y);

    static void setDefault();

    static void showDefault();

    const Date &operator++();

    const Date operator++(int);

    const Date &operator--();

    const Date operator--(int);

    static bool isLeapYear(int y);


private:

    int _day, _month, _year;

    static bool leapYear(int y);

    void fillDate(int d, Month m, int y);

    static string monthNames[12];

    static bool defaultSet;

    static Date defaultDate;

};


ostream &operator<<(ostream &os, const Date &d);


struct Date::BadDate {

    int _day, _month, _year;

    BadDate(int d, int m, int y) : _day(d), _month(m), _year(y) {};

};


ostream &operator<<(ostream &os, const Date::BadDate &bd);

#endif //C_DATE_H
