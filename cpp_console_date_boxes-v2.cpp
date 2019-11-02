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
    std::string Students[][3] = {{"Jackson", "Freddy", "94"},
								 {"Johnson", "Frankie", "98"}, 
								 {"Martin", "Donnie", "99"}, 
								 {"Garland", "George", "100"}, 
								 {"Clyde", "Bonnie", "69"}, 
								 {"Gordan", "Elizabeth", "99"}
								};
							   
    int BoxWidthLastName{15};
    int BoxWidthFirstName{15};
    int BoxWidthGrade{5};
    int Iterator1;

   	std::cout << "+" ;
    std::cout.width(BoxWidthLastName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthFirstName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthGrade + 2);
    std::cout.fill('-');
    std::cout << "" << "+\n";


	std::cout << "| ";

	std::cout.width(BoxWidthLastName);
	std::cout.fill(' ');
	std::cout << "Last Name" << " | ";

	std::cout.width(BoxWidthFirstName);
	std::cout.fill(' ');
	std::cout << "First Name" << " | ";

	std::cout.width(BoxWidthGrade);
	std::cout.fill(' ');
	std::cout << "Grade" << " |\n";
        

	std::cout << "+" ;
    std::cout.width(BoxWidthLastName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthFirstName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthGrade + 2);
    std::cout.fill('-');
    std::cout << "" << "+\n";
    
    for(Iterator1 = 0; Iterator1 < (sizeof(Students) / sizeof(Students[0])); Iterator1++)
    {
		std::cout << "| ";

		std::cout.width(BoxWidthLastName);
		std::cout.fill(' ');
		std::cout << Students[Iterator1][0] << " | ";

		std::cout.width(BoxWidthFirstName);
		std::cout.fill(' ');
		std::cout << Students[Iterator1][1] << " | ";

		std::cout.width(BoxWidthGrade);
		std::cout.fill(' ');
		std::cout << Students[Iterator1][2] << " |\n";

	}

	std::cout << "+";
    std::cout.width(BoxWidthLastName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthFirstName + 2);
    std::cout.fill('-');
    std::cout << "" << "+";

    std::cout.width(BoxWidthGrade + 2);
    std::cout.fill('-');
    std::cout << "" << "+\n";
}
