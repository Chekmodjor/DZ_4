#pragma once
#ifndef Time_def
#define Time_def
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>      /* puts, printf */
#include <ctime>       /* time_t, struct tm, time, localtime */
#include <iomanip>
#include <stdlib.h>
#include <sstream>

class Time
{
public:
    Time() :minutes(0), hours(0), seconds(0) {}
    Time(int h, int m, int s) {
        this->hours = h;
        this->minutes = m;
        this->seconds = s;
    }
    void show() { std::cout << "Time -> " << hours << ":" << minutes << ":" << seconds << std::endl; }
    void setHours(int h) { if (h <= 12 && h >= 0 || h <= 24 && h >= 0) this->hours = h; }
    void setMinutes(int m) { if (m <= 60 && m >= 0) this->minutes = m; }
    void setSeconds(int s) { if (s <= 60 && s >= 0) this->seconds = s; }
    int getHours() { return this->hours; }
    int getMinutes() { return this->minutes; }
    int getSeconds() { return this->seconds; }
private:
    int minutes;
    int hours;
    int seconds;
};
#endif