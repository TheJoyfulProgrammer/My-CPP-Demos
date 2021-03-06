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
    Description: This C++ demo asks for a message from the user and the displays how many
                 consonants, vowels, number, spaces, and punctuations there are in the
                 message.

*/

#include <iostream>

int main()
{
    int CounterConsonants{0};
    int CounterVowels{0};
    int CounterNumbers{0};
    int CounterSpaces{0};
    int CounterPunctuation{0};
    int Iterator1{0};

    std::string UserInput;
    std::string vowels = "aeiou";

    std::cout << "This demo will count all consonants, vowels, numbers, spaces, and punctuation in a message.\n\nPlease type in a message:\n> ";
    std::getline(std::cin, UserInput);

    for (Iterator1 = 0; Iterator1 < (int)UserInput.length(); Iterator1++)
    {
        if (isalpha(UserInput[Iterator1])) vowels.find(tolower(UserInput[Iterator1])) != std::string::npos ? CounterVowels++ : CounterConsonants++;
        if (isdigit(UserInput[Iterator1])) CounterNumbers++;
        if (isspace(UserInput[Iterator1])) CounterSpaces++;
        if (ispunct(UserInput[Iterator1])) CounterPunctuation++;
    }

    std::cout << "\n\nConsonants: " << CounterConsonants << "\n";
    std::cout << "Vowels: " << CounterVowels << "\n";
    std::cout << "Numbers: " << CounterNumbers << "\n";
    std::cout << "Punctuations: " << CounterPunctuation << "\n";
    std::cout << "Spaces: " << CounterSpaces << "\n\n\n";

    return 0;
}
