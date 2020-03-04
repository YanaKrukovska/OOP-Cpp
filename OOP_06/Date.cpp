//
// Created by user on 03.03.2020.
//
#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include <iostream>
#include <ctime>

#define NDEBUG

using namespace std;

string Date::monthNames[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
bool Date::defaultSet = false;
Date Date::defaultDate = Date();

Date::Date(int day, Month month, int year) {
    fillDate(day, month, year);
#ifndef NDEBUG
    cout << "Created: " << *this << endl;
#endif
    return;
}

Date::Date(int d, int m, int y) {
    fillDate(d, Month(m), y);
#ifndef NDEBUG
    cout << "Created: " << *this << endl;
#endif
    return;
}

Date::Date(const Date &date) {
    fillDate(date.day(), date.month(), date.year());
#ifndef NDEBUG
    cout << "Copied: " << *this << endl;
#endif
    return;
};


Date::~Date() {
#ifndef NDEBUG
    cout << "Deleted: " << *this << endl;
#endif
}


void Date::setDay(int day) {
    _day = day;
}

void Date::setMonth(int month) {
    _month = month;
}

void Date::setYear(int year) {
    _year = year;
}

void Date::setDefault(int d, Date::Month m, int y) {
    defaultDate = Date(d, m, y);
    defaultSet = true;

#ifndef NDEBUG
    cout << "Set ";
    showDefault();
#endif
}


void Date::setDefault() {
    time_t timer;
    time(&timer);
    struct tm *today = gmtime(&timer);
    defaultDate._day = today->tm_mday;
    defaultDate._month = today->tm_mon;
    defaultDate._year = today->tm_year += 1900;
    defaultSet = true;
#ifndef NDEBUG
    cout << "Set ";
    showDefault();
#endif
}

void Date::showDefault() {
    cout << "default date: " << defaultDate << endl;
}


void Date::fillDate(int d, Month m, int y) {
    if (!defaultSet) {
        setDefault();
    }

    _day = d ? d : defaultDate._day;
    _month = m ? m : defaultDate._month;
    _year = y ? y : defaultDate._year;

    int numberOfDays = 0;

    switch (_month) {
        case feb:
            numberOfDays = 28 + leapYear(y);
            break;
        case apr:
        case jun:
        case sep:
        case nov:
            numberOfDays = 30;
            break;
        case jan:
        case mar:
        case may:
        case jul:
        case aug:
        case oct:
        case dec:
            numberOfDays = 31;
            break;
        default:
            throw Date::BadDate(_day, _month, _year);
    }
    if (_day < 1 || numberOfDays < _day || _year < 0) {
        throw Date::BadDate(_day, _month, _year);
    }
}

const Date &Date::operator++() {
    switch (_month) {

        case feb:
            if ((_day == 28 && !leapYear(_year)) || (_day == 29 && leapYear(_year))) {
                _day = 1;
                ++_month;
            } else { ++_day; }
            break;
        case apr:
        case jun:
        case sep:
        case nov:
            if (_day == 30) {
                _day = 1;
                ++_month;
            } else { ++_day; }
            break;
        case dec:
            if (_day == 31) {
                _month = 1;
                _day = 1;
                ++_year;
            } else { ++_day; }
            break;
        default:
            if (_day == 31) {
                _day = 1;
                ++_month;
            } else {
                ++_day;
            }
    }
    return *this;
}

const Date Date::operator++(int) {
    Date old = *this;
    ++*this;
    return old;
}


const Date &Date::operator--() {
    switch (_month) {

        case jan:
            if (_day == 1) {
                _month = 12;
                _day = 31;
                --_year;
            } else { --_day; }
            break;
        case mar:
            if ((_day == 1 && leapYear(_year))) {
                _day = 29;
                --_month;
            } else {
                _day = 28;
                --_month;
            }
            break;
        case may:
        case jul:
        case oct:
        case dec:
            if (_day == 1) {
                _day = 30;
                --_month;
            } else { ++_day; }
            break;
        default:
            if (_day == 1) {
                _day = 31;
                --_month;
            } else {
                --_day;
            }
    }
    return *this;
}

const Date Date::operator--(int) {
    Date old = *this;
    --*this;
    return old;
}


bool Date::leapYear(int y) {
    return isLeapYear(y);
}

bool Date::isLeapYear(int y) {
    bool isLeapYear;
    if (y % 4) {
        isLeapYear = false;
    } else if (y % 100) {
        isLeapYear = true;
    } else isLeapYear = y % 400 == 0;
    return isLeapYear;
}

bool Date::operator<(const Date& a) const
{
    if(_year > a.year() )
    {
        return false;
    }else if(a.year() == _year)
    {
        if(_month >a.month())
        {
            return false;
        }else if(a.month() == _month)
        {
            if (_day >=a.day())
                return false;
        }
    }
    return true;
}



ostream &operator<<(ostream &os, const Date &date) {
    os << "Date (" << date.day() << "." << date.month() << "." << date.year() << ")";
    return os;
}


ostream &operator<<(ostream &os, const Date::BadDate &badDate) {
    os << "Bad date (" << badDate._day << '.' << badDate._month << '.' << badDate._year << ")";
    return os;
}

bool operator==(const Date & d1, const Date & d2)
{
    return d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year();
}

bool operator!=(const Date & d1, const Date & d2)
{
    return !(d1 == d2);
}

bool operator==(const struct tm * d1, const Date & d2)
{
    return d1->tm_mday == d2.day() && d1->tm_mon+1 == d2.month() && (d1->tm_year+1900 == d2.year());
}

bool operator!=(const struct tm * d1, const Date & d2)
{
    return !(d1 == d2);
}

bool operator==(const Date & d2, const struct tm * d1)
{
    return d1 == d2;
}

bool operator!=(const Date & d2, const struct tm * d1)
{
    return !(d1 == d2);
}


