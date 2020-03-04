//
// Created by user on 26.02.2020.
//

#include "Time.h"
#include "Timer.h"
#include <iostream>
#include <thread>
#include "cassert"


using namespace std;

int main() {


    // Testing get/set methods
    Time time1(14, 14, 14);
    assert(time1.hours() == 14);
    assert(time1.minutes() == 14);
    assert(time1.seconds() == 14);


    //Testing operator =
    Time time2(0, 2, 0);
    time1 = time2;
    assert(time1.hours() == time2.hours());
    assert(time1.minutes() == time2.minutes());
    assert(time1.seconds() == time2.seconds());


    //Testing increment ++
    Time time4(00, 59, 58);
    time4++;
    assert(time4.seconds() == 59);
    time4++;
    assert(time4.seconds() == 0);
    assert(time4.minutes() == 0);
    assert(time4.hours() == 1);

    //Testing decrement --
    time4--;
    assert(time4.seconds() == 59);
    assert(time4.minutes() == 59);
    assert(time4.hours() == 0);
    time4--;
    assert(time4.seconds() == 58);

    //Testing int()
    assert(static_cast<int>(time1) == 120);

    //Testing double()
    Time time3(0, 120, 0);
    assert(static_cast<double>(time3) == 2);


    cout << "TESTING TIMER" << endl;
    Time interval = Time(0, 0, 2);

    //Alarm that starts after class started
    Timer::startAlarm(interval);

    //Alarm that starts after certain interval passes by after the class started
    //ATTENTION: insert valid date and time to check if the timer actually works
    Date date = Date(4, 3, 2020);
    Time time = Time(14, 15, 20);
    try {
        Timer *timer1 = new Timer(date, time, interval);
        timer1->waitForAlarm();
        delete timer1;
    } catch (char const *error) {
        cout << error << endl;
    }

    return 0;
}