/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    Feburary 28th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: Show BYTE structure of integers in memory.
*/

#define __STDC_FORMAT_MACROS // Required for the MingW toolchain
#include <iostream>
#include <inttypes.h>

std::string CurrentEndianMsg;
std::string OppositeEndianMsg;

template <typename IntegerType>
void PrintIntegerDetails(IntegerType IntegerValue)
{
    uint16_t SizeOfIntegerValue = sizeof(IntegerValue);
    int8_t i;

    std::cout << "Integer size (in bytes): " << SizeOfIntegerValue << "\n";
    std::cout << "Integer value (Decimal): " << IntegerValue << "\n";
    std::cout << "Integer value (Hexidecimal): ";

    switch (SizeOfIntegerValue)
    {
        case 2: printf("0x%04X\n", (unsigned int) IntegerValue);
                break;
        case 4: printf("0x%08X\n", (unsigned int) IntegerValue);
                break;
        case 8: printf("0x%016" PRIX64 "\n", (uint64_t) IntegerValue);
                break;
    }

    std::cout << "Integer stored in memory in byte order:\n";
    std::cout << "        " << CurrentEndianMsg << " processor [current]: ";

    for(i = 0; i < SizeOfIntegerValue; i++)
    {
        printf("%02X ", (((unsigned char*) &IntegerValue)[i]));
    }

    std::cout << "\n        " << OppositeEndianMsg << " processor  [simulated]: ";

    for(i = SizeOfIntegerValue - 1; i >= 0; i--)
    {
        printf("%02X ", (((unsigned char*) &IntegerValue)[i]));
    }

    std::cout << "\n\n";
}


int main()
{
    uint16_t ValueUInt16a = 0x0001;
    uint16_t ValueUInt16b = 0x1234;
    uint32_t ValueUInt32a = 0x00000001;
    uint32_t ValueUInt32b = 0x12345678;
    uint64_t ValueUInt64a = 0x0000000000000001;
    uint64_t ValueUInt64b = 0x123456789ABCDEF0;

    uint16_t EndianTestValue = 0x0001;
    uint8_t IsLittleEndian = ((uint8_t*) &EndianTestValue)[0];

    std::cout << "Current processor endianness: ";

    switch (IsLittleEndian) {
        case 0: CurrentEndianMsg = "Big Endian";
                OppositeEndianMsg = "Little Endian";
                break;
        case 1: CurrentEndianMsg = "Little Endian";
                OppositeEndianMsg = "Big Endian";
                break;
    }

    std::cout << CurrentEndianMsg << "\n\n";

    PrintIntegerDetails(ValueUInt16a);
    PrintIntegerDetails(ValueUInt16b);
    PrintIntegerDetails(ValueUInt32a);
    PrintIntegerDetails(ValueUInt32b);
    PrintIntegerDetails(ValueUInt64a);
    PrintIntegerDetails(ValueUInt64b);

    return 0;
}
