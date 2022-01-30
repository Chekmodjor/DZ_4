#pragma once
#ifndef Users_def
#define Users_def
#include "Time.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <stdio.h>      /* puts, printf */
#include <ctime>       /* time_t, struct tm, time, localtime */
#include <iomanip>
#include <stdlib.h>
#include <sstream>
class Users
{
public:
    Users();
    Users(std::string name, std::string surname, int age, int numberSheets, Time* time, int priority);
    void show();
    void setName(std::string name);
    std::string getName();
    void setSurname(std::string surname);
    std::string getSurname();
    void setAge(int age);
    int getAge();
    void setNumberSheets(int numberSheets);
    int getNumberSheets();
    void setTime(int h, int m, int s);
    Time& getTime();
    void setPriority(int priority);
    int getPriority();
private:
    std::string name;
    std::string surname;
    int age;
    int numberSheets;
    Time* time;
    int priority;
};
#endif