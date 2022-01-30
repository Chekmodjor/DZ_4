#include "Users.h"

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