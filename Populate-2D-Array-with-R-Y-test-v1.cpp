#include <iostream>
#include <ctime>
#include <cmath>

namespace ConnectFour
{
    const uint8_t BoardRows{6};
    const uint8_t BoardColumns{7};

    char Board[BoardRows][BoardColumns];
    int BoardTracker[BoardRows * BoardColumns];
    uint16_t CurrentPosition{0};

    std::string PopulationCharacters = "RY";
    uint16_t CurrentCharacter{0};

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

        CurrentCharacter = (++CurrentCharacter) % PopulationCharacters.length();

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
