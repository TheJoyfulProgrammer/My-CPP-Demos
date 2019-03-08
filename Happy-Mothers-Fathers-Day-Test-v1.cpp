#include <iostream>
#include <conio.h>

int main()
{
    std::string name, gender;

    std::cout << "What is your name?\n> ";
    std::cin >> name;

    std::cout << "\nAre you a 'male' or 'female'?\n> ";
    std::cin >> gender;

    if (gender == "male")
    {
        std::cout << "\nHappy Father's Day, " << name << "\n\n";
    } else if (gender == "female") {
        std::cout << "\nHappy Mother's Day, " << name << "\n\n";
    } else {
        std::cout << "\nHave a wonderful day, " << name << "\n\n";
    }

    std::cout << "<Press the enter/return key to exit>";

    std::cin.ignore();
    std::cin.get();

    return 0;
}
