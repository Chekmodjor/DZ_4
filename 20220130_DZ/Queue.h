#pragma once
#ifndef Queue_def
#define Queue_def
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>      /* puts, printf */
#include <ctime>       /* time_t, struct tm, time, localtime */
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#define STOP_CMD system("pause"); 
#define COLOR_CMD system("color 0A");
template<typename T>class Queue
{
public:
    Queue();
    Queue(int SIZE);
    ~Queue();
    void addElement(T Element);
    void deleteElementQueue(); // Normal Queue
    void deleteElementQueueRing(); // Ring Queue
    void deleteElementQueuePriority(); // Priority queue
    bool checkQueue();
    void showQueue();
    T GetFirst();
    T GetLast();
    void queueRand(int min, int max);
    int sizeQueue();
    void showStatistic();
    void deleteQueue();
private:
    T* arr;
    int SIZE;
    int counter;
};
#endif