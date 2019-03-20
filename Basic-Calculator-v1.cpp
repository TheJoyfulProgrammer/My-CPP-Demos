/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    March 20th, 2019

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This is a basic calculator.
*/

#include <iostream>
#include <cctype>
#include <stdexcept>

int main()
{
    long double LeftValue, RightValue;
    unsigned char BasicOperator;
    std::string UserExpression;
    int ValidUserExpression;
    int Iterator1, DecimalPointUsed;
    std::string ValidOperators = "+-*/";

    std::cout << "This is a basic calculator.\n\nEnter an simple numerical math expression to be solved.\nThe expression must be in the form of:  Left-Value Operator Right-Value\nAcceptable operators are: Addition, subtaction, Multiplication, and Division.\n\n";

    do
    {
        ValidUserExpression = false;
        DecimalPointUsed = false;

        std::cout << "> ";
        std::getline (std::cin, UserExpression);

        for (Iterator1 = 0; Iterator1 < (int)UserExpression.length(); Iterator1++)
        {
            if (isspace(UserExpression[Iterator1]))
            {
                UserExpression.erase (Iterator1, 1);
                Iterator1--;
            }
        }

        if (UserExpression.length() < 3)
        {
            std::cout << "\nInvalid expression. Please try again.\n";
            continue;
        }

        if ((UserExpression[0] != '-') && !isdigit(UserExpression[0]))
        {
            std::cout << "\nThe left value should start with either a digit or a negative '-' sign.\nPlease try again.\n";
            continue;
        }

        for (Iterator1 = 1; Iterator1 < (int)UserExpression.length(); Iterator1++)
        {
            if ((UserExpression[Iterator1] == '.') && (DecimalPointUsed == false))
            {
                DecimalPointUsed = true;
            } else if ((UserExpression[Iterator1] == '.') && (DecimalPointUsed == true)) {
                std::cout << "More than one decimal points were detected in the left value.\nPlease try again.\n";
                break;
            }

            if (!isdigit(UserExpression[Iterator1]) && (UserExpression[Iterator1] != '-') && (UserExpression[Iterator1] != '.'))
            {
                try {
                    LeftValue = std::stold (UserExpression.substr(0, Iterator1), 0);
                } catch (const std::invalid_argument&) {
                    std::cout << "The left value you entered is invalid. Please try again.\n";
                    break;
                } catch (const std::out_of_range&) {
                    std::cout << "The left value you entered is out of range. Please try again.\n";
                    break;
                }

                UserExpression.erase (0, Iterator1);
                break;
            }
        }

        if (ValidOperators.find(UserExpression[0]) != std::string::npos)
        {
            BasicOperator = UserExpression[0];
            UserExpression.erase (0, 1);
        } else {
            std::cout << "No valid math operator was found.\nPlease try again.\n";
            continue;
        }

        if ((UserExpression[0] != '-') && !isdigit(UserExpression[0]))
        {
            std::cout << "\nThe Right value should start with either a digit or a negative '-' sign.\nPlease try again.\n";
            continue;
        }

        DecimalPointUsed = false;

        for (Iterator1 = 1; Iterator1 < (int)UserExpression.length(); Iterator1++)
        {
            if ((UserExpression[Iterator1] == '.') && (DecimalPointUsed == false))
            {
                DecimalPointUsed = true;
            } else if ((UserExpression[Iterator1] == '.') && (DecimalPointUsed == true)) {
                std::cout << "More than one decimal points were detected in the right value.\nPlease try again.\n";
                break;
            }

            if (!isdigit(UserExpression[Iterator1]) && (UserExpression[Iterator1] != '-') && (UserExpression[Iterator1] != '.'))
            {
                break;
            }
        }

        try {
            RightValue = std::stold (UserExpression.substr(0, Iterator1), 0);
        } catch (const std::invalid_argument&) {
            std::cout << "The right value you entered is invalid. Please try again.\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "The right value you entered is out of range. Please try again.\n";
            continue;
        }

        UserExpression.erase (0, Iterator1);

        if (UserExpression.length() > 0) std::cout << "The expression contains unknown content after the right value and will be ignored.\n";

        std::cout << LeftValue << " " << BasicOperator << " " << RightValue << " = ";

        switch (BasicOperator) {
            case '*': std::cout << (LeftValue * RightValue) << "\n";
                      break;
            case '/': std::cout << (LeftValue / RightValue) << "\n";
                      break;
            case '+': std::cout << (LeftValue + RightValue) << "\n";
                      break;
            case '-': std::cout << (LeftValue - RightValue) << "\n";
                      break;
        }

        ValidUserExpression = true;

    } while (ValidUserExpression == false);

    return 0;
}
