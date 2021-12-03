#include <iostream>
#include <Windows.h>
#include <array>
#include "CircularBuffer.h"

void CircularBuffer::pushFront(char _value)
{
    arrayValue[head] = _value;
    head = (head + 1) % BUFFER_SIZE;
    ++size;

    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload, replacing oldest index!" << std::endl;
        size -= overflow;
        tail = (tail + overflow) % BUFFER_SIZE;
    }
}

void CircularBuffer::pushBack(char _value)
{
    tail = (tail - 1);
    if (tail <= 0)
    {
        tail += BUFFER_SIZE;
    }
    arrayValue[tail] = _value;
    ++size;

    int overflow = size - BUFFER_SIZE;

    if (overflow > 0)
    {
        std::cout << "Buffer overload, replacing oldest index!" << std::endl;
        size -= overflow;
        tail = (head - 1);
        if (head <= 0)
        {
            tail += BUFFER_SIZE;
        }
    }
}

char CircularBuffer::popFront()
{
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popFront" << std::endl;
        return NULL;
    }

    char value = getFront();

    head = head - 1;
    if (head < 0)
    {
        head += BUFFER_SIZE;
    }
    --size;
    return value;
}

char CircularBuffer::popBack()
{
    if (size <= 0)
    {
        std::cout << "Buffer is empty! Cannot use popBack." << std::endl;
        return NULL;
    }

    char value = getBack();

    tail = (tail + 1) % BUFFER_SIZE;
    --size;
    return value;
}

int CircularBuffer::getSize()
{
    return size;
}

char CircularBuffer::getRelativeLocation(int _location)
{
    int currentIndex = (tail + _location) % BUFFER_SIZE;
    return arrayValue[currentIndex];
}

char CircularBuffer::getLocation(int _location)
{   
    int currentIndex = _location;
    return arrayValue[currentIndex];
}

char CircularBuffer::getFront()
{
    // head
    return arrayValue[head];
}

char CircularBuffer::getBack()
{
    // tail
    return arrayValue[tail];
}

CircularBuffer::CircularBuffer()
{
    head = 0;
    tail = 0;
    size = 0;
}