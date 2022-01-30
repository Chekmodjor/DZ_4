#include "Queue.h"

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