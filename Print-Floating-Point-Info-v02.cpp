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

    Description: prints a lot of information about floating-point numbers.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <values.h>
//#include <iomanip>

//const int LittleEndian = (char) 0x04030201 == 0x01;
const uint8_t IsLittleEndian = char (0x0001);

#define GetBit(Value, BitPosition) ((((char *) &Value)[IsLittleEndian ? BitPosition / CHARBITS : sizeof(Value) - BitPosition / CHARBITS - 1] >> (BitPosition % CHARBITS)) & 0x01)
#define PrintBit(Value, BitPosition) (putchar(GetBit(Value, BitPosition) ? '1' : '0'))

template <typename FloatType>
void PrintFloatingPointBits(FloatType FloatingPointNumber)
{
    int BitPosition;
    int ValueSize = sizeof(FloatingPointNumber) * CHAR_BIT;

    BitPosition = ValueSize - 1;

    if(ValueSize > 80)
    {
        for(; BitPosition > 88; BitPosition--)
        {
            PrintBit(FloatingPointNumber, BitPosition);
        }

        putchar(' ');

        ValueSize = 80;
        BitPosition = ValueSize - 1;
    }

    PrintBit(FloatingPointNumber, BitPosition);

    putchar(' ');

    for(BitPosition--; BitPosition >= (ValueSize - 9); BitPosition--) {
        PrintBit(FloatingPointNumber, BitPosition);
    }

    putchar(' ');

    for(; BitPosition >= 0; BitPosition--) {
        PrintBit(FloatingPointNumber, BitPosition);
    }
}

int main(int argc, char **argv)
{
    long double ReturnFloatValue;
    //__float128 ReturnFloatValue;
    float FloatValueF;
    double FloatValueD;
    long double FloatValueLD;
    //__float128 FloatValue128;

    std::cout << "Enter a floating point number to see its binary make up: ";

    while(scanf("%Lg", &ReturnFloatValue) == 1)
    {

        FloatValueF = (float) ReturnFloatValue;
        FloatValueD = (double) ReturnFloatValue;
        FloatValueLD = (long double) ReturnFloatValue;
        //FloatValue128 = ReturnFloatValue;

        std::cout << "\n" << std::fixed;

        std::cout << "\n\tFloatValueF (" << (sizeof(FloatValueF) * CHARBITS) << " Bits): " << FloatValueF;
        printf("\n\t(Actual: %24.10g)\n\t", FloatValueF);
        PrintFloatingPointBits(FloatValueF);
        std::cout << "\n";

        std::cout << "\n\tFloatValueD (" << (sizeof(FloatValueD) * CHARBITS) << " Bits): " << FloatValueD;
        printf("\n\t(Actual: %24.17g)\n\t", FloatValueD);
        PrintFloatingPointBits(FloatValueD);
        std::cout << "\n";

        std::cout << "\n\tFloatValueLD (" << (sizeof(FloatValueLD) * CHARBITS) << " Bits): " << FloatValueLD;
        printf("\n\t(Actual: %20.20Lg)\n\t", FloatValueLD);
        PrintFloatingPointBits(FloatValueLD);
        std::cout << "\n";

        //std::cout << "\n\tFloatValue128 (" << (sizeof(FloatValue128) * CHARBITS) << " Bits): " << FloatValue128;
        //printf("\n\t(Actual: %20.80Qe)\n\t", FloatValue128);
        //PrintFloatingPointBits(FloatValue128);
        //std::cout << "\n";

        std::cout << "\n\n";

        //printf("%10g = %24.17g = ", f, f);
        //PrintFloatingPointBits(f);
        std::cout << "Enter a floating point number to see its binary make up: ";

    }

    return 0;
}

