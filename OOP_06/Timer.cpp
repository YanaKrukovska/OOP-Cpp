//
// Created by user on 03.03.2020.
//

#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include "Timer.h"
#include <thread>
#include <iostream>

using namespace std;

Timer::Timer(const Date &startDate, const Time &startTime, const Time &interval) : _startDate(startDate),
                                                                                   _startTime(startTime),
                                                                                   _interval(interval) {
#ifndef NDEBUG
    cout << "Created timer: " << *this << endl;
#endif
}


Timer::~Timer() {
#ifndef NDEBUG
    cout << "Deleted timer: " << *this << endl;
#endif
}

Date Timer::startDate() const {
    return _startDate;
}

Date &Timer::startDate() {
    return _startDate;
}

void Timer::setDate(const Date &date) {
    _startDate = date;
}

Time Timer::startTime() const {
    return _startTime;
}

Time &Timer::startTime() {
    return _startTime;
}

void Timer::setStartTime(const Time &time) {
    _startTime = time;
}


Time Timer::interval() const {
    return _interval;
}

Time &Timer::interval() {
    return _interval;
}

void Timer::setInterval(const Time &interval) {
    _interval = interval;
}

void Timer::waitForAlarm() {
    auto *currentDateTime = new tm;
    time_t timer;
    time(&timer);

    cout << "Waiting until: " << startDate() << " " << startTime() << endl;
    do {
        time(&timer);
        currentDateTime = gmtime(&timer);
        this_thread::sleep_for(chrono::seconds(1));
        cout << currentDateTime->tm_mday << "." << currentDateTime->tm_mon + 1 << "." << currentDateTime->tm_year + 1900
             << " (" << currentDateTime->tm_hour + 2 << ":"
             << currentDateTime->tm_min << ":" << currentDateTime->tm_sec << ") " << endl;
    } while (currentDateTime != startDate() || currentDateTime != startTime());

    Timer::startAlarm(_interval);

}

void Timer::startAlarm(const Time &intervalValue) {
    Time interval = intervalValue;
    cout << "The timer starts NOW" << endl;
    while (!(interval.hours() == 0 && interval.minutes() == 0 & interval.seconds() == 0)) {
        cout << interval << endl;
        --interval;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "\007" << "ALARM" << endl;
}

ostream &operator<<(ostream &os, const Timer &timer) {
    os << "timer (" << timer.startDate() << ", " << timer.startTime() << ", time gap = " << timer.interval() << ")"
       << endl;
    return os;
}

