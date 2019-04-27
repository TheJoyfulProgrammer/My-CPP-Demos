/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    April 24, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ (ver 17)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This demonstrates how to use the <vector> container.
*/

#include <iostream>
#include <vector>

int main()
{
    struct Student
    {
        std::string Name;
        unsigned int Age;
        float gpa;
    } CurrentStudent;

    std::vector <Student> Students;
    long long unsigned int Iterator1;

    CurrentStudent.Name = "Mo";
    CurrentStudent.Age = 18;
    CurrentStudent.gpa = 4.0;
    Students.push_back(CurrentStudent);

    CurrentStudent.Name = "Larry";
    CurrentStudent.Age = 17;
    CurrentStudent.gpa = 3.6;
    Students.push_back(CurrentStudent);

    CurrentStudent.Name = "Curly";
    CurrentStudent.Age = 18;
    CurrentStudent.gpa = 3.4;
    Students.push_back(CurrentStudent);

    for (Iterator1 = 0; Iterator1 < Students.size(); Iterator1++)
    {
        std::cout << "Student's Name: " << Students[Iterator1].Name << ", Student's Age: " << Students[Iterator1].Age << ", Student's GPA: " << Students[Iterator1].gpa << "\n";
    }

    Students.pop_back();
    std::cout << "\n\n";

    for (Iterator1 = 0; Iterator1 < Students.size(); Iterator1++)
    {
        std::cout << "Student's Name: " << Students[Iterator1].Name << ", Student's Age: " << Students[Iterator1].Age << ", Student's GPA: " << Students[Iterator1].gpa << "\n";
    }

    return 0;
}
