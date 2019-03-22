/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    March 20th, 2019

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++ ver 17
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This demo fills a Connect Four board with 'R' and 'Y' pieces and prints the board on each turn.
                 Since this is to show a student the simple logic behind what the teacher was asking for on the
                 test, I decided to keep this demo simple.
*/

#include <iostream>
#include <ctime>
#include <cmath>

namespace ConnectFour
{
    const uint8_t BoardRows{6};
    const uint8_t BoardColumns{7};

    uint16_t BoardTracker[BoardRows * BoardColumns];
    uint16_t CurrentPosition{0};
    uint16_t CurrentCharacter{0};

    std::string PopulationCharacters = "RY";
    char Board[BoardRows][BoardColumns];

    void ResetBoard()
    {
        for (uint16_t Iterator1 = 0; Iterator1 < (BoardRows * BoardColumns); Iterator1++)
        {
            Board[Iterator1 / BoardColumns][Iterator1 % BoardColumns] = '.';
            BoardTracker[Iterator1] = Iterator1;
            CurrentPosition = 0;
        }

        srand (time(NULL));
    }

    bool populateBoard()
    {
        uint16_t RandomCell = (rand() % ((BoardRows * BoardColumns) - CurrentPosition));
        std::swap(BoardTracker[CurrentPosition], BoardTracker[RandomCell + CurrentPosition]);

        uint16_t NewPosition = BoardTracker[CurrentPosition];

        std::cout << "Current Character: '" << PopulationCharacters[CurrentCharacter] << "'\n";
        Board[NewPosition / BoardColumns][NewPosition % BoardColumns] = PopulationCharacters[CurrentCharacter];

        CurrentCharacter = ++CurrentCharacter % PopulationCharacters.length();

        CurrentPosition++;
        if (CurrentPosition == (BoardRows * BoardColumns )) return true;

        return false;
    }

    void printBoard()
    {
        std::cout << "\n        Current Iteration: " << CurrentPosition << "\n";

        for (uint16_t Iterator1 = 0; Iterator1 <= (BoardRows * BoardColumns); Iterator1++)
        {
            if (Iterator1 % BoardColumns == 0) std::cout << "\n        ";
            std::cout << Board[Iterator1 / BoardColumns][Iterator1 % BoardColumns];
        }

        std::cout << "\n";
    }
}

int main()
{
    bool ReturnValue;

    ConnectFour::ResetBoard();

    do
    {
        ReturnValue = ConnectFour::populateBoard();
        ConnectFour::printBoard();
    } while (ReturnValue == false);

    return 0;
}
