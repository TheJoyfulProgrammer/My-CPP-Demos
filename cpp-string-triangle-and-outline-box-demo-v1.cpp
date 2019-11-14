/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    November 13, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This demo creates a triangular textual water fall and box outline
                 created with text.
*/

#include <iostream>
#include <cmath>

void PrintTriangleWaterfall(std::string);
void PrintBoxMessage(std::string);

int main()
{
	int Iterator1;
	std::string UserInput = "HELLO";
	
	PrintTriangleWaterfall(UserInput);
	
	for(Iterator1 = 1; Iterator1 <= 5; Iterator1++)
	{
		PrintBoxMessage(UserInput.substr(0, Iterator1));
	}
}

void PrintTriangleWaterfall(std::string Message)
{
	int Iterator1;
	int StringLength = Message.length();
	
	for(Iterator1 = 1; Iterator1 <= StringLength; Iterator1++)
	{
		std::cout.width(StringLength);
        std::cout.fill(' ');
        std::cout << Message.substr(0, Iterator1) << "\n";
	}
	
	std::cout << "\n";
}

void PrintBoxMessage(std::string Message)
{
	int Iterator1;
	int StringLength = Message.length();
	int StringLengthDouble = StringLength * StringLength;
	
	for(Iterator1 = 0; Iterator1 < StringLengthDouble; Iterator1++)
	{
		Iterator1 % StringLength == StringLength - 1 ? std::cout << Message.substr(StringLength - floor(Iterator1 / StringLength) - 1, 1) << "\n"
			: floor(Iterator1 / StringLength) == StringLength - 1 ? std::cout << Message.substr(StringLengthDouble - Iterator1 - 1, 1) 
			: Iterator1 % StringLength == 0 ? std::cout << Message.substr(floor(Iterator1 / StringLength), 1)
			: floor(Iterator1 / StringLength) == 0 ? std::cout << Message.substr(Iterator1, 1)
			: std::cout << " ";
	}
	
	std::cout << "\n";
}
