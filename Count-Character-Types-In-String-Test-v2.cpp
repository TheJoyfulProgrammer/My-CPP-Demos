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
    std::string vowels = "aeiouAEIOU";
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    std::string numbers = "1234567890";
    std::string space = " ";
    std::string punctuation = "`~!@#$%^&*()_-+={}[]|\\:;\"\'<>,.?/";

    std::cout << "This demo will count all consonants, vowels, numbers, spaces, and punctuation in a message.\n\nPlease type in a message:\n> ";
    std::getline(std::cin, UserInput);

    for (Iterator1 = 0; Iterator1 < (int)UserInput.length(); Iterator1++)
    {
        if (vowels.find(UserInput[Iterator1]) != std::string::npos) CounterVowels++;
        if (consonants.find(UserInput[Iterator1]) != std::string::npos) CounterConsonants++;
        if (numbers.find(UserInput[Iterator1]) != std::string::npos) CounterNumbers++;
        if (space.find(UserInput[Iterator1]) != std::string::npos) CounterSpaces++;
        if (punctuation.find(UserInput[Iterator1]) != std::string::npos) CounterPunctuation++;
    }

    std::cout << "\n\nConsonants: " << CounterConsonants << "\n";
    std::cout << "Vowels: " << CounterVowels << "\n";
    std::cout << "Numbers: " << CounterNumbers << "\n";
    std::cout << "Punctuations: " << CounterPunctuation << "\n";
    std::cout << "Spaces: " << CounterSpaces << "\n\n\n";

    return 0;
}

