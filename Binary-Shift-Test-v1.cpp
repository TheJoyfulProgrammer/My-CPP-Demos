/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    March 4th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: Display Binary Shift - Test v1.
*/

#include <iostream>
#include <bitset>

int main()
{
    long long unsigned Value = 1;
    int Iterator1;

    for(Iterator1 = 0; Iterator1 < 32; Iterator1++)
    {
        std::bitset<32> ValueContainer(Value);
        std::cout << "Hex Value: ";
        std::cout.width (8);
        std::cout.fill ('0');
        std::cout << std::hex << Value << "  ==  Bin: " << ValueContainer << "\n";
        //if(Iterator1 < 31) std::cout << "Value = Value << 1\n";
        Value = Value << 1;
    }
}
