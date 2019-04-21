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
    Description: This creates a diamond pattern. Since this is not using the
                 <iomanip> library, we have to spread the stream settings into
                 multiple std::cout lines using the "fill" and "width" functions
                 of the std::cout function.
*/

#include <iostream>

int main ()
{
    int Iterator1;
    int rows{8};

    for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
    {
        std::cout.width(abs(Iterator1));
        std::cout.fill(' ');
        std::cout << "";
        std::cout.width((rows - abs(Iterator1) ) * 2 - 1);
        std::cout.fill('*');
        std::cout << "" << "\n";
    }

    return 0;
}

