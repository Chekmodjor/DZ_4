#include "Queue.h"
#include "Time.h"
#include "Users.h"


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