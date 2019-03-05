/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    Feburary 28th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This is the code to a challenge that adds two numbers without using the basic math operators.
*/

#include <iostream>
#include <string>
#include <sstream>

unsigned char Add(unsigned char, unsigned char, bool &);

int main()
{
    unsigned char Value1 = 200, Value2 = 35, ReturnValue;
    bool OverflowFlag;

    std::cout << "Value1: " << (int)Value1 << ", Value2: " << (int)Value2 << "\n";

    ReturnValue = Add(Value1, Value2, OverflowFlag);

    if(OverflowFlag == false)
    {
        std::cout << "Add(" << (int)Value1 << ", " << (int)Value2 << "): " << (int)ReturnValue << "\n\n";
    } else {
        std::cout << "Add(" << (int)Value1 << ", " << (int)Value2 << "):  << OVERFLOW ERROR >>   [overflow value: " << (int)ReturnValue << "]\n\n";
    }


    Value1 = 245;
    Value2 = 25;

    std::cout << "Value1: " << (int)Value1 << ", Value2: " << (int)Value2 << "\n";

    ReturnValue = Add(Value1, Value2, OverflowFlag);

    if(OverflowFlag == false)
    {
        std::cout << "Add(" << (int)Value1 << ", " << (int)Value2 << "): " << (int)ReturnValue << "\n\n\n";
    } else {
        std::cout << "Add(" << (int)Value1 << ", " << (int)Value2 << "):  << OVERFLOW ERROR >>   [overflow value: " << (int)ReturnValue << "]\n\n\n";
    }

    return 0;

}

unsigned char Add(unsigned char AL, unsigned char AH, bool &Overflow_flag)
{
    unsigned char CarryFlags;

    Overflow_flag = 0;

    while (AH != 0)
    {
        CarryFlags = AL & AH;
        Overflow_flag = Overflow_flag | (CarryFlags >> 7);
        AL = AL ^ AH;
        AH = CarryFlags << 1;
    }

    return AL;
}

