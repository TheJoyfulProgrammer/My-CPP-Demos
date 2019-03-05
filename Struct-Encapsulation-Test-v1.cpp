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

    Description: STRUCT Encapsulation Test v1.
*/

#include <iostream>

int main()
{
    struct EncapsulatedStructure
    {
        // PUBLIC
        std::string FirstName;
        std::string LastName;

        std::string GetIDNumber() { return IDNumber;}
        void PutIDNumber(std::string IDNumberValue) { IDNumber = IDNumberValue; }

        // PRIVATE
        private:
        std::string IDNumber;
    } ;

    EncapsulatedStructure myES;

    myES.FirstName = "Walt";
    myES.LastName = "Whitman";
    myES.PutIDNumber("25612812706403201608040201");

    std::cout << "First Name: " << myES.FirstName << "\nLast Name: " << myES.LastName << "\nID Number: " << myES.GetIDNumber() << "\n\n";

    return 0;

}
