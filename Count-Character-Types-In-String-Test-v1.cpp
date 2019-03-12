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
        if (isalpha(UserInput[Iterator1]))
        {
            vowels.find(tolower(UserInput[Iterator1])) != std::string::npos ? CounterVowels++ : CounterConsonants++;
        } else if (isdigit(UserInput[Iterator1])) {
            CounterNumbers++;
        } else if (isspace(UserInput[Iterator1])) {
            CounterSpaces++;
        } else if (ispunct(UserInput[Iterator1])) {
            CounterPunctuation++;
        }
    }

    std::cout << "\n\nConsonants: " << CounterConsonants << "\n";
    std::cout << "Vowels: " << CounterVowels << "\n";
    std::cout << "Numbers: " << CounterNumbers << "\n";
    std::cout << "Punctuations: " << CounterPunctuation << "\n";
    std::cout << "Spaces: " << CounterSpaces << "\n\n\n";

    return 0;
}
