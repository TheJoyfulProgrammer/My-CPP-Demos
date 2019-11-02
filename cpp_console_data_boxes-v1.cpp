/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    November 2, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8
    Tested Operating Systems: Linux Mint 19
    Description: This demonstrates how to create beautiful data boxes in C++.
*/

#include <iostream>

int main ()
{
    std::string Names[] = {"Freddy", "Frankie", "Donnie", "George", "Bonnie", "Elizabeth"};

    int BoxWidth = 20;
    int Iterator1;
    
    std::cout.width(BoxWidth);
    std::cout.fill('*');
    std::cout << "" << "\n";
    
    for(Iterator1 = 0; Iterator1 < (sizeof(Names) / sizeof(std::string)); Iterator1++)
    {
		std::cout << "*";
		std::cout.width(BoxWidth - 3);
		std::cout.fill(' ');
		std::cout << Names[Iterator1] << " *\n";
	}

    std::cout.width(BoxWidth);
    std::cout.fill('*');
    std::cout << "" << "\n\n\n";
}
