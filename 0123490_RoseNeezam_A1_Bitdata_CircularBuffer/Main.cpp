#include <iostream>
#include <limits>
#include "BitData.h"
#include "CircularBuffer.h"

using namespace std;

#define CHR_BITS 8

BitData dat;

CircularBuffer cb;

void ResetInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void bufferMessage()
{
    for (int i = 0; i < cb.getSize(); ++i)
    {
        cout << cb.getRelativeLocation(i) << " | ";

    }
    cout << endl << endl;

    cout << "Circular Buffer: " << endl;
    cout << "[1] Push front a char" << endl;
    cout << "[2] Pop back a char" << endl;
    cout << "[3] Pop front a char" << endl;
    cout << "[4] Get char from location" << endl;
    cout << "[5] Get size of buffer" << endl;
    cout << "[0] Main Menu" << endl;
}

void bitDataMessage()
{
    cout << endl;
    cout << "Set 8 bit data: " << endl;
    cout << "[1] Set 1 Data Boolean" << endl;
    cout << "[2] Randomize Data Boolean" << endl;
    cout << "[3] Set All Data To 'TRUE'" << endl;
    cout << "[4] Set All Data To 'FALSE'" << endl;
    cout << "[5] Main menu" << endl;
}

void ListData(BitData _data)
{
    for (int i = 0; i < CHR_BITS; ++i)
    {
        cout << i << " => ";
        if (_data.get(i))
        {
            cout << "TRUE ";
        }
        else
        {
            cout << "FALSE";
        }
        cout << " | ";

        int n = i + 1;

        if (n % 8 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void ListInt(BitData _data)
{
    cout << "Current Bit Value: ";
    for (int i = 0; i < CHR_BITS; ++i)
    {
        cout << _data.get(i);
    }

    cout << endl << endl;

    cout << "Current Integer Value: " << dat.getData() << endl;
}


int BitDataFunc()
{
    while (true)
    {
        cout << '\n' << endl;
        ListData(dat);
        ListInt(dat);
        bitDataMessage();

        char choice;
        int value;
        int flag;
        bool bFlag;

        while (!(cin >> choice))
        {
            cout << "Input only accepts character: ";
        }
        ResetInput();

        switch (choice)
        {
        case '1':
#pragma region SetData
            cout << "Choose between index 0 - " << CHR_BITS - 1 << ": ";
            while (!(cin >> value))
            {
                ResetInput();
                cout << "Input only accepts integer: ";
            }
            if (!(value >= 0 && value <= CHR_BITS - 1))
            {
                cout << "You can only choose between index 0 - " << CHR_BITS - 1 << endl;
                break;
            }
            cout << endl;
            cout << "You have chosen index '" << value << "'" << endl;
            cout << "Please determine index flag: " << endl;
            cout << "[1] TRUE" << endl;
            cout << "[2] FALSE" << endl;
            while (!(cin >> flag))
            {
                ResetInput();
                cout << "Input only accepts integer: ";
            }
            if (flag == 1)
            {
                bFlag = true;
                cout << "You have set index '" << value << "' with flag 'TRUE'" << endl;
            }
            else if (flag == 2)
            {
                bFlag = false;
                cout << "You have set index '" << value << "' with flag 'FALSE'" << endl;
            }
            else
            {
                cout << "You can only choose TRUE or FALSE" << endl;
                break;
            }
            dat.set(value, bFlag);
            break;
#pragma endregion
        case '2':
#pragma region RandomizeData
            for (int i = 0; i < CHR_BITS; ++i)
            {
                int random = rand() % 2;

                dat.set(i, random);
            }
            cout << "Randomizing data boolean variables..." << endl;
            break;
#pragma endregion
        case '3':
#pragma region SetAllTrue
            for (int i = 0; i < CHR_BITS; ++i)
            {
                dat.set(i, true);
            }
            cout << "Setting all data boolean variables to 'TRUE'" << endl;
            break;
#pragma endregion
        case '4':
#pragma region SetAllFalse
            for (int i = 0; i < CHR_BITS; ++i)
            {
                dat.set(i, false);
            }
            cout << "Setting all data boolean variables to 'FALSE'" << endl;
            break;
#pragma endregion
        case '5':
            system("PAUSE");
            system("CLS");
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }
}


int CircularBufferFunc()
{
    while (true)
    {
        cout << '\n' << endl;
        char choice = NULL;
        char input = NULL;
        char selected = NULL;
        int index = NULL;


        bufferMessage();

        while (!(cin >> choice))
        {
            ResetInput();
            cout << "Input only accepts integers: ";
        }
        ResetInput();

        switch (choice)
        {
        case '1':
            cout << "Type a char to continue: ";
            while (!(cin >> input))
            {
                ResetInput();
                cout << "Input only accepts char: ";
            }
            cb.pushFront(input);
            break;
        case '2':
            cout << "Attempting to pop back." << endl;
            cb.popBack();
            break;
        case '3':
            cout << "Attempting to pop front." << endl;
            cb.popFront();
            break;
        case '4':
            if (cb.getSize() <= 0)
            {
                cout << "Buffer is empty, no value is acquired!" << endl;
                break;
            }
            else
            {
                cout << "Select index between " << 0 << " to " << cb.getSize() - 1 << ": ";
            }

            while (!(cin >> index))
            {
                ResetInput();
                cout << "Input only accepts int: ";
            }

            selected = cb.getRelativeLocation(index);
            if (index < 0 || index > cb.getSize() - 1)
            {
                cout << "Index out of range, no value is acquired!" << endl;
            }
            else
            {
                cout << "You have selected char '" << selected << "' from index " << index << "." << endl;
            }
            break;
        case '5':
            cout << "Current size of circular buffer is " << cb.getSize() << "." << endl;
            break;
        case '0':
            system("PAUSE");
            system("CLS");
            return 0;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }
}


int main(void)
{
    while (true) {

        char choice = NULL;

        cout << "\n|| Main Menu ||" << endl;
        cout << "\n Choose :" << endl;
        cout << "[1] : Set 8 bit data" << endl;
        cout << "[2] : Circular Buffer\n" << endl;

        while (!(cin >> choice))
        {
            cout << "Input only accepts character: ";
        }
        ResetInput();

        switch (choice)
        {
            case '1'
            :   system("CLS");
                BitDataFunc();
                break;
                case '2'
                :   system("CLS");
                    CircularBufferFunc();
                    break;
        }

    }

    system("PAUSE");
    return 0;
};