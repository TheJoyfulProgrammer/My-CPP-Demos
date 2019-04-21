#include <iostream>
#include <iomanip>

int main ()
{
    int Iterator1;
    int rows{8};

    for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
    {
        std::cout << std::setw(abs(Iterator1)) << std::setfill (' ') << "" << std::setw((rows - abs(Iterator1) ) * 2 - 1) << std::setfill ('*') << "";
        std::cout << "\n";
    }

    return 0;
}
