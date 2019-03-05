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

    Description:
*/

#include <iostream>
#include <string>

int main()
{
    std::string UserInput;
    unsigned long int LoopIterator;

    std::cout << "Please enter a string and I will convert it to HEX string:\n> ";
    std::getline (std::cin, UserInput);

    std::cout << std::hex << "\nHere is the HEX array:\n\n";

    for(LoopIterator = 0; LoopIterator < UserInput.size(); LoopIterator ++)
    {
        std::cout << "0x" << (unsigned int)(UserInput[LoopIterator]);

        if(LoopIterator < (UserInput.size() - 1))
        {
            std::cout << ", ";
        } else {
            std::cout << "\n\n";
        }
    }
}
