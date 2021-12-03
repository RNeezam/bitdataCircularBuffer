#pragma once

class BitData
{
public:

    BitData();

    void reset();
    void set(int _location, bool _flag);
    bool get(int _location);
    void ListData(BitData _dat);

    int getData();
    void setData(int value);

private:

    unsigned char m_data;
    unsigned char m_value[];
};

