#include <iostream>

bool Login(int);

std::string LoginPin = "1234"; // This would normally be read from a database instead of it being in a global variable.

int main()
{
    int MaxRetries = 3;
    bool LoggedIn = false;

    LoggedIn = Login(MaxRetries);

    if(LoggedIn == true)
    {
        std::cout << "ACCESS GRANTED!\n";
    } else {
        std::cout << "ACCESS DENIED!\n";
    }

    return 0;
}


bool Login(int Retries)
{
    std::string PinInput;

    do
    {
        std::cout << "Please enter your pin number to login: ";
        std::cin >> PinInput;

        if(PinInput == LoginPin)
        {
            return true;
        } else {
            Retries--;
            if(Retries > 0)
            {
                std::cout << "INCORRECT PIN. PLEASE TRY AGAIN\nYou have " << Retries << " attempts remaining.\n\n";
            }
        }
    } while (Retries > 0);

    return false;
}
