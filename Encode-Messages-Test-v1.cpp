/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 18, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:    https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This demo encodes messages..
*/

#include <iostream>

std::string EncodeMessage(std::string);

int main()
{
    std::string UserInput, EncodedMessage;

    std::cout << "Enter a message to be encoded:\n> ";
    std::getline (std::cin, UserInput);

    EncodedMessage = EncodeMessage(UserInput);

    std::cout << "\n\nMessage: " << UserInput << "\nEncoded Message: " << EncodedMessage << "\n\n";

    return 0;
}

std::string EncodeMessage(const std::string MessageToEncode)
{
    const unsigned int SplitMessageAt{5};
    unsigned int Iterator1;
    std::string TempMessage = MessageToEncode;

    for (Iterator1 = 0; Iterator1 < MessageToEncode.size(); Iterator1++)
    {
        TempMessage[Iterator1] = MessageToEncode[(Iterator1 * SplitMessageAt) % MessageToEncode.size() + (Iterator1 / SplitMessageAt)];

        if (TempMessage[Iterator1] == ' ') TempMessage[Iterator1] = '0';
        if (TempMessage[Iterator1] == '.') TempMessage[Iterator1] = '1';
    }

    return TempMessage;

}
