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

    getch();

    return 0;
}
