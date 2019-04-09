#include <iostream>

std::string strReverse(std::string);

int main()
{
    std::string UserInput, ReversedString;

    std::cout << "Please enter a message to reverse: ";
    std::getline (std::cin, UserInput);

    ReversedString = strReverse(UserInput);

    std::cout << "\nYour message in reverse: " << ReversedString << "\n";
    std::cout << "\nYour message is ";

    UserInput.compare (ReversedString) ? std::cout << "not " : std::cout << "";

    std::cout << "a Palindrome\n\n";

    return 0;
}

std::string strReverse(std::string MessageToReverse)
{
    uint16_t Iterator1;

    for (Iterator1 = 0; Iterator1 < (MessageToReverse.size() / 2); Iterator1++)
    {
        std::swap (MessageToReverse[Iterator1], MessageToReverse[MessageToReverse.size() - Iterator1 - 1]);
    }

    return MessageToReverse;
}
