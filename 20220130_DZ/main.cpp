#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h> 
#include <ctime>
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
template<typename T>Queue<T>::Queue() : SIZE(0), arr(NULL), counter(0)
{
    //DEFAULT
}
template<typename T> Queue<T>::Queue(int SIZE)
{
    try
    {
        this->SIZE = SIZE;
        arr = new T[this->SIZE]();
        counter = 0;
    }
    catch (std::bad_alloc& memoryAllocationException)
    {
        std::cerr << "Exception occured: [ERROR MEMORY]" << memoryAllocationException.what() << std::endl; // Fixed output
        STOP_CMD
    }
}
template<typename T> Queue<T>::~Queue()
{
    delete[] arr;
    arr = NULL;
}
template<typename T>void Queue<T>::addElement(T Element)
{
    if (this->checkQueue() != false)
    {
        this->arr[this->counter] = Element;
        this->counter++;
    }
}
template<typename T>void Queue<T>::deleteElementQueue() // Normal queue
{
    if (this->counter != 0)
    {
        T* buf = new T[this->counter]();
        for (size_t i = 0; i < this->counter; i++)
        {
            buf[i] = this->arr[i];
            this->arr[i] = 0;
        }
        for (size_t i = 0; i < this->counter - 1; i++)
        {
            this->arr[i] = buf[i + 1];
        }
        this->counter--;
        delete[] buf;
    }
    else
    {
        this->checkQueue();
    }
}
template<typename T>void Queue<T>::deleteElementQueueRing() //  Ring Queue
{
    if (this->counter != 0)
    {
        T temp = this->arr[0];
        for (size_t i = 1; i < this->counter; i++) // Copying an array without a priority item
        {
            this->arr[i - 1] = this->arr[i];
        }
        this->arr[this->counter - 1] = temp;
    }
    else
    {
        this->checkQueue();
    }
}
template<typename T>void Queue<T>::deleteElementQueuePriority() // Priority queue
{
    if (this->counter != 0)
    {
        T* buf = new T[this->counter - 1];
        T temp = this->arr[0];
        size_t count = 0, valueSameElements = 0;
        for (size_t i = 0; i < this->counter; i++) // Search Element MAX
        {
            if (temp < arr[i])
            {
                temp = arr[i];
            }
        }
        for (size_t i = 0; i < this->counter; i++) // get value same elements
        {
            if (arr[i] == temp)
                valueSameElements++;
        }
        for (size_t i = 0; i < this->counter; i++) // Copying an array without a priority item
        {
            if (this->arr[i] != temp)
            {
                buf[count] = this->arr[i];
                count++;
            }
            if (this->arr[i] == temp && valueSameElements > 1) //Protection: If the priority element is not one
            {
                buf[count] = this->arr[i];
                count++;
                valueSameElements--;
            }
        }
        for (size_t i = 0; i < this->counter - 1; i++) // Set array in main arr
        {
            this->arr[i + 1] = buf[i];
        }
        this->arr[0] = temp; // Set value in main arr index 0
        deleteElementQueue(); // DELL ELEMENT of Queue
        delete[] buf;
        count = 0;
    }
    else
    {
        this->checkQueue();
    }
}
template<typename T>bool Queue<T>::checkQueue()
{
    if (this->counter < this->SIZE)
    {
        return true;
    }
    else
    {
        //std::cerr << "Queue full:" << std::endl; 
        return false;
    }

}
template<typename T>void Queue<T>::showQueue()
{
    this->checkQueue();
    for (size_t i = 0; i < this->counter; i++)
    {
        std::cout << this->arr[i] << "\t";
    }
    std::cout << std::endl;
}
template<typename T>T Queue<T>::GetFirst()
{
    //std::cout << "First element in queue -> " << this->arr[0] << std::endl; 
    return this->arr[0];
}
template<typename T>T Queue<T>::GetLast()
{
    //std::cout << "Last element in queue -> " << this->arr[this->counter - 1] << std::endl;
}
template<typename T>void Queue<T>::queueRand(int min, int max)
{
    for (size_t i = 0; i < this->SIZE; i++)
    {
        this->arr[i] = min + rand() % (max - min + 1);
    }
    this->counter = this->SIZE;
}
template<typename T>void Queue<T>::deleteQueue()
{
    for (size_t i = 0; i < this->counter; i++)
    {
        arr[i] = 0;
    }
    this->counter = 0;
}
template<typename T>int Queue<T>::sizeQueue()
{
    std::cout << "Size queue -> " << this->SIZE << std::endl;
    std::cout << "Elements in queue -> " << this->counter << std::endl;
    return this->SIZE;
}
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
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

Users::Users() :age(0), numberSheets(0)
{
    //DEFAULT
}

Users::Users(std::string name, std::string surname, int age, int numberSheets, Time* time, int priority)
{
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->numberSheets = numberSheets;
    this->time = time;
    this->priority = priority;
}
void Users::show()
{
    std::cout << "User" << std::endl;
    std::cout << "Name -> " << this->getName() << std::endl;
    std::cout << "Surname -> " << this->getSurname() << std::endl;
    std::cout << "Age -> " << this->getAge() << std::endl;
    std::cout << "Sent to printer -> " << this->getNumberSheets() << std::endl;
    this->time->show();
    std::cout << "Priority -> " << this->getPriority() << std::endl;
}
void Users::setName(std::string name)
{
    this->name = name;
}
std::string Users::getName()
{
    return this->name;
}
void Users::setSurname(std::string surname)
{
    this->surname = surname;
}
std::string Users::getSurname()
{
    return this->surname;
}
void Users::setAge(int age)
{
    this->age = age;
}
int Users::getAge()
{
    return this->age;
}
void Users::setNumberSheets(int numberSheets)
{
    this->numberSheets = numberSheets;
}
int Users::getNumberSheets()
{
    return this->numberSheets;
}
void Users::setTime(int h, int m, int s)
{
    this->time->setHours(h);
    this->time->setMinutes(m);
    this->time->setSeconds(s);
}
Time& Users::getTime() {
    return *time;
}
void Users::setPriority(int priority)
{
    this->priority = priority;
}
int Users::getPriority()
{
    return this->priority;
}
//----------------------------------------------------------------------
int main() {
    COLOR_CMD

        char symbol = 0;

    std::cout << "--------------------------------------" << std::endl;
    Time time(12, 52, 35);
    Users u = { "Igor", "Dombrovsky", 29, 35,  &time, 15 };
    u.show();
    std::cout << "--------------------------------------" << std::endl;
    Time time1(10, 24, 27);
    Users u1 = { "Elena", "Petrova", 28, 78,  &time1, 25 };
    u1.show();
    std::cout << "--------------------------------------" << std::endl;
    Time time2(12, 52, 35);
    Users u2 = { "Petro", "Trefaldo", 35, 15,  &time2, 8 };
    u2.show();
    std::cout << "--------------------------------------" << std::endl;

    std::cout << "Send document to printer enter [y]:" << std::endl;
    std::cin >> symbol;
    if (symbol == 'y')
    {
        Queue<int> printer(3);
        printer.addElement(u.getPriority());
        printer.addElement(u1.getPriority());
        printer.addElement(u2.getPriority());
        std::cout << "--------------------------------------" << std::endl;
        printer.showQueue();
        std::cout << "--------------------------------------" << std::endl;
        printer.deleteElementQueuePriority();
        std::cout << "--------------------------------------" << std::endl;
        printer.showQueue();
        std::cout << "--------------------------------------" << std::endl;
        printer.deleteElementQueuePriority();
        std::cout << "--------------------------------------" << std::endl;
        printer.showQueue();
        std::cout << "--------------------------------------" << std::endl;
        printer.deleteElementQueuePriority();
        std::cout << "--------------------------------------" << std::endl;
        printer.showQueue();
        std::cout << "--------------------------------------" << std::endl;
    }
    else
    {
        std::cerr << "Error input!" << std::endl;
    }
    STOP_CMD
        return 0;
}