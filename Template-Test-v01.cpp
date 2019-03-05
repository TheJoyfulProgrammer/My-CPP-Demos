/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    Feburary 28th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: Temaplate test v1.
*/

#include <iostream>
#include <string>


template <typename TemplateParameter>
TemplateParameter GetMax (TemplateParameter a, TemplateParameter b) {

    TemplateParameter result;

    result = (a > b) ? a : b;

    return (result);
}

int main ()
{

    int WallHeight1 = 5, WallHeight2 = 10, WallHeightLargest;
    long SunToEarthDistanceMiles = 92900000, SunToMarsDistanceMiles = 141600000, FurthestFromTheSunMiles;

    float EarthsGravityFT = 32.1740;
    float MarsGravityFT = 12.2;
    float GravityAnswer;

    std::string Msg1 = "Walter", Msg2 = "Whitman", LargestMsg;

    WallHeightLargest = GetMax(WallHeight1, WallHeight2);
    FurthestFromTheSunMiles = GetMax(SunToEarthDistanceMiles, SunToMarsDistanceMiles);
    LargestMsg = GetMax(Msg1, Msg2);
    GravityAnswer = GetMax(EarthsGravityFT, MarsGravityFT);

    std::cout << "Largest Wall Height: " << WallHeightLargest << "\n";
    std::cout << "Furthes From The Sun: " << FurthestFromTheSunMiles << "\n";
    std::cout << "LargestMsg: " << LargestMsg << "\n";
    std::cout << "Most Gravity: " << GravityAnswer << "\n";

    std::cout << "\n";

    return 0;
}
