#include <iostream>

int main ()
{
    int Iterator1;
    int rows{8};

    for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
    {
        std::cout.width(abs(Iterator1));
        std::cout.fill(' ');
        std::cout << "";
        std::cout.width((rows - abs(Iterator1) ) * 2 - 1);
        std::cout.fill('*');
        std::cout << "" << "\n";
    }

    return 0;
}

