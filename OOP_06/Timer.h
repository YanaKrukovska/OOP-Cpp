//
// Created by user on 03.03.2020.
//
#ifndef C_TIMER_H
#define C_TIMER_H
#pragma once

#include "Time.h"
#include "Date.h"
#include <iostream>

using namespace std;

class Timer {
private:
    Date _startDate;
    Time _startTime;
    Time _interval;

public:

    Timer(const Date &startDate, const Time &startTime, const Time &interval);

    ~Timer();

    Date startDate() const;

    Date &startDate();

    Time startTime() const;

    Time &startTime();

    Time interval() const;

    Time &interval();

    void setDate(const Date &date);

    void setStartTime(const Time &time);

    void setInterval(const Time &time);

    void waitForAlarm();

    static void startAlarm(const Time &intervalValue);

};

ostream &operator<<(ostream &os, const Timer &timer);


#endif //C_TIMER_H
