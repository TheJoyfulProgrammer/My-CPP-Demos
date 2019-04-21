/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 14, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This creates a diamond pattern. This demo uses the <iomanip> library
                 which allows us to minimize the amount of std::cout statements used.
*/

#include <iostream>
#include <iomanip>

int main ()
{
    int Iterator1;
    int rows{8};

    for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
    {
        std::cout << std::setw(abs(Iterator1)) << std::setfill (' ') << "" << std::setw((rows - abs(Iterator1) ) * 2 - 1) << std::setfill ('*') << "";
        std::cout << "\n";
    }

    return 0;
}
