#pragma once

#define BUFFER_SIZE 5

class CircularBuffer
{
private:

    int head;
    int tail;
    int size;

public:

    float arrayValue[BUFFER_SIZE];

public:

    void pushBack(char _value);
    void pushFront(char _value);
    char popFront();
    char popBack();
    int getSize();
    char getRelativeLocation(int _location);
    char getLocation(int _location);
    char getFront();
    char getBack();

    CircularBuffer();
};