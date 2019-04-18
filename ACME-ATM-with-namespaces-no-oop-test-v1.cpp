/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 18, 2019

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This is a basic ATM demo that shows how to use members and
                 methods in namespaces.
*/

#include <iostream>

namespace BankAccount
{
    float ClientBalance{10};

    void DepositFunds()
    {
        float DepositAmount;

        while(true)
        {
            std::cout << "How much would you like to deposit into your account?\n> ";
            std::cin >> DepositAmount;
            std::cout << "\n\n";

            if (DepositAmount >= 0)
            {
                ClientBalance += DepositAmount;
                std::cout << "After depositing " << DepositAmount << ", you now have " << ClientBalance << ".\n\n";
                break;
            } else {
                std::cout << "Invalid amount. Please enter a positive number.\n\n";
            }
        }
    }

    void WithdrawFunds()
    {
        float WithdrawAmount;

        while(true)
        {
            std::cout << "How much money would you like to get back?\n\n> ";
            std::cin >> WithdrawAmount;
            std::cout << "\n\n";

            if (WithdrawAmount >= 0)
            {
                if ((ClientBalance - WithdrawAmount) >= 0)
                {
                    ClientBalance -= WithdrawAmount;
                    std::cout << "After withdrawing " << WithdrawAmount << " from your account, you now have " << ClientBalance << " dollars in your account.\n\n";
                    break;
                } else {
                    std::cout << "Insufficient Funds. Please try again.\n\n";
                }
            } else {
                std::cout << "Invalid Amount. You must enter a positive number.\n\n";
            }
        }
    }

    void CheckBalance()
    {
        std::cout << "Your current balance is: " << ClientBalance << "\n\n\n";
    }
}

int main()
{
    unsigned int SelectedMenuItem;

    while (true)
    {
        std::cout << "Welcome to the ACME ATM. Please choose from the following options:\n\n1. Check Balance\n\n2. Deposit Funds\n\n3. Withdraw Funds\n\n4. Exit your account.\n\n\n> ";
        std::cin >> SelectedMenuItem;
        std::cout << "\n\n";

        switch (SelectedMenuItem)
        {
            case 1 : BankAccount::CheckBalance();
                     break;
            case 2 : BankAccount::DepositFunds();
                     break;
            case 3 : BankAccount::WithdrawFunds();
                     break;
            case 4 : std::cout << "Thank you for using your ACME ATM. Have a nice day.\n\n\n";
                     exit(0);
                     break;
            default : std::cout << "Invalid Input. Please try again.\n\n\n";
                     break;
        }
    }

    return 0;
}
