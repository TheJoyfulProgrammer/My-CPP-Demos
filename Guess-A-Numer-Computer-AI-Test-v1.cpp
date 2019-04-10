/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 9th, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This is a guess-a-number game where the computer guesses your number.
*/

#include <iostream>
#include <string> // Added for Visual Studio users. Not required for G++.
#include <cmath>
#include <algorithm>

int main()
{
    std::string UserInput;

    const uint16_t MinNumber{1};
    const uint16_t MaxNumber{20};
    const uint16_t MaxGuesses{5};

    uint16_t LowestNumber{MinNumber};
    uint16_t HighestNumber{MaxNumber};
    uint16_t GuessesRemaining{MaxGuesses};
    uint16_t AIGuess;

    std::cout << "This is a guess-the-number game where I, the computer, will attempt to guess\n"
                 "your number. I will guess your number within five tries. Statistically\n"
                 "speaking, if I can't, then more-than-likely you lied about what your number is.\n\n"
                 "Please choose a number from " << MinNumber << " to " << MaxNumber << " and remember it. Please do not tell me what\n"
                 "it is (I wont ask you anyways).\n\n"
                 "If your number is higher than what I guess, type, \"higher\". If your number is\n"
                 "lower than mine, type, \"lower\". If I guess your number, type \"correct\".\n\n\n";

    do
    {
        AIGuess = (uint16_t) std::ceil((HighestNumber - LowestNumber) / 2 + LowestNumber);

        std::cout << "Is your number: " << AIGuess << "?\n\n> ";
        std::cin >> UserInput;
        std::cout << "\n\n";

        std::transform(UserInput.begin(), UserInput.end(), UserInput.begin(), tolower);

        if (UserInput == "lower")
        {
            HighestNumber = AIGuess;
        } else if (UserInput == "higher") {
            LowestNumber = AIGuess;
        } else if (UserInput == "correct") {
            std::cout << "I got it! I told you I could guess your number in five tries or less!\n\n";
            break;
        } else {
            std::cout << "I do not understand. Please either type, \"higher\", \"lower\", or \"correct\"\n\n";
            GuessesRemaining++;
        }

        GuessesRemaining--;
    } while (GuessesRemaining > 0);

    if (GuessesRemaining > 0)
    {
        std::cout << "I got your number in " << (MaxGuesses - GuessesRemaining) << " guesses!\n\n";
    } else {
        std::cout << "You cheated! I will not play this game with you again!\n\n";
    }

    return 0;
}
