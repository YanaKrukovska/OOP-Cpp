//
// Created by user on 26.02.2020.
//

#ifndef C_TIME_H
#define C_TIME_H

#include <iostream>

using namespace std;

class Time {

private:

    int _hours;
    int _minutes;
    int _seconds;

    void normalizeTime();


public:

    static const double hourToDec;

    explicit Time(int h = 0, int m = 0, int s = 0);

    Time(const Time &);

    ~Time();


    Time &operator=(const Time &);

    operator int() const;

    operator double() const;


    int hours() const { return _hours; }

    int minutes() const { return _minutes; }

    int seconds() const { return _seconds; }


    int &hours() { return _hours; }

    int &minutes() { return _minutes; }

    int &seconds() { return _seconds; }

    const Time &operator++();

    const Time operator++(int);

    const Time &operator--();

    const Time operator--(int);

};


double operator+(const Time &, const Time &);

ostream &operator<<(ostream &, const Time &);

bool operator==(const Time &t1, const Time &t2);

bool operator!=(const Time &time1, const Time &time2);

bool operator==(const Time &, const struct tm *);

bool operator!=(const Time &, const struct tm *);

bool operator==(const struct tm *, const Time &);

bool operator!=(const struct tm *, const Time &);

#endif //C_TIME_H
