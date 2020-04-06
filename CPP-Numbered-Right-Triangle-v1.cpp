
/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 05th, 2020
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ ver 17+
    Tested Operating Systems: Linux Mint, Windows
    Description: This demo was on a challenge to print a numbered right triangle with one
				 for loop.
*/

#include <iostream>

int main()
{
	// How many rows to print
	int NumberOfLines{10};
	// Calculate the area of the right triangle to get the number of numbers to print
	int NumberOfElementsToPrint = ((NumberOfLines + 1) * NumberOfLines) / 2;
	
	int Iterator1{0};
	int CurrentModulus{1};
	int CurrentValue{1};
	
	for(Iterator1 = 0; Iterator1 < NumberOfElementsToPrint; Iterator1++)
	{
		std::cout << (CurrentValue) << " ";
		
		if(CurrentValue == CurrentModulus) 
		{
			std::cout << "\n";
			CurrentModulus ++;
			CurrentValue = 1;
		} else {
			CurrentValue ++;
		}
	}
}
