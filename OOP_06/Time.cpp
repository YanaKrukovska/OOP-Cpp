//
// Created by user on 26.02.2020.
//

#include "Time.h"

const double Time::hourToDec = 1. / 3600.;

Time::Time(const int h, const int m, const int s) :
        _hours(h), _minutes(m), _seconds(s) {
    normalizeTime();
#ifndef NDEBUG
    cout << "Set new time: " << *this << endl;
#endif
    return;
}

Time::Time(const Time &anotherTime) : _seconds(anotherTime.seconds()), _minutes(anotherTime.minutes()),
                                      _hours(anotherTime.hours()) {

#ifndef NDEBUG
    cout << "Copied time: " << *this << endl;
#endif
    return;
}

Time::~Time() {
#ifndef NDEBUG
    cout << "Deleted time: " << *this << endl;
#endif
    return;
}

Time &Time::operator=(const Time &anotherTime) {
    _seconds = anotherTime._seconds;
    _minutes = anotherTime._minutes;
    _hours = anotherTime._hours;
    return *this;
}

Time::operator int() const {
    return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const {
    double minutes = _minutes + 59. / _seconds;
    double hours = _hours + 59. / minutes;
    return hours;
}

void Time::normalizeTime() {
    int seconds = static_cast<int>(*this);
    _hours = seconds / 60 / 60;
    _minutes = seconds / 60 % 60;
    _seconds = seconds % 60;
}

const Time &Time::operator++() {
    _seconds += 1;
    normalizeTime();
    return *this;
}

const Time Time::operator++(int) {
    const Time temp(*this);
    _seconds += 1;
    normalizeTime();
    return temp;
}

const Time &Time::operator--() {
    const int n = static_cast<int>(*this);
    if (n > 0) {
        _hours = 0;
        _minutes = 0;
        _seconds = n - 1;
    }
    normalizeTime();
    return *this;
}

const Time Time::operator--(int) {
    const Time temp(*this);
    const int n = static_cast<int>(*this);
    if (n > 0) {
        _hours = 0;
        _minutes = 0;
        _seconds = n - 1;
    }
    normalizeTime();
    return temp;
}


double operator+(const Time &time1, const Time &time2) {
    return int(time1) * Time::hourToDec + int(time2) * Time::hourToDec;
}

bool operator==(const Time &t1, const Time &t2) {
    return t1.seconds() == t2.seconds() && t1.minutes() == t2.minutes() && t1.hours() == t2.hours();
}

bool operator!=(const Time &time1, const Time &time2) {
    return !(time1 == time2);
}

bool operator==(const Time &time1, const struct tm *time2) {
    return time1.hours() == time2->tm_hour + 2 && time1.minutes() == time2->tm_min && time1.seconds() == time2->tm_sec;
}

bool operator!=(const Time &time1, const struct tm *time2) {
    return !(time1 == time2);
}

bool operator==(const struct tm *time1, const Time &time2) {
    return time2 == time1;
}

bool operator!=(const struct tm *t2, const Time &t1) {
    return !(t1 == t2);
}

ostream &operator<<(ostream &os, const Time &time) {
    return os << time.hours() << ":" << time.minutes() << ":" << time.seconds();
}
