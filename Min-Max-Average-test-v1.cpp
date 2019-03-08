#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    const unsigned int HighestPossibleGrade = 100;

    std::vector<int> StudentGrades;
    unsigned int MinGrade(HighestPossibleGrade);
    unsigned int MaxGrade(0);
    unsigned int CombinedGrades(0);
    int UserInput;
    unsigned int GradeIterator;

    std::cout << "Please enter the grades of all the students.\nEntering a negative value will end the input sequence.\n\n";

    do
    {
        std::cout << "Grade for student #" << (StudentGrades.size() + 1) << ": ";
        std::cin >> UserInput;

        if(UserInput >= 0)
        {
            if((unsigned int)UserInput > HighestPossibleGrade)
            {
                std::cout << "ERROR: The highest possible grade is " << HighestPossibleGrade << ". You entered " << (unsigned int)UserInput << ". Please try again.\n";
            } else {
                StudentGrades.push_back (UserInput);

                if((unsigned int)UserInput < MinGrade) MinGrade = (unsigned int)UserInput;
                if((unsigned int)UserInput > MaxGrade) MaxGrade = (unsigned int)UserInput;
                CombinedGrades += (unsigned int)UserInput;
            }
        }
    } while (UserInput >= 0);

    std::cout << "\nYou entered " << StudentGrades.size() << " student grades. Here is the list:\n";

    for(GradeIterator = 0; GradeIterator < StudentGrades.size(); GradeIterator++)
    {
        if(!(GradeIterator % 10)) std::cout << "\n";
        std::cout << std::setw(4) << std::setfill(' ') << std::right << StudentGrades[GradeIterator] << "%";
    }

    std::cout << "\n\n";
    std::cout << "Minimum Grade: " << std::setw(5) << std::setfill(' ') << MinGrade << "%\n";
    std::cout << "Maximum Grade: " << std::setw(5) << std::setfill(' ') << MaxGrade << "%\n";

    if(CombinedGrades == 0)
    {
        std::cout << "ALL STUDENTS MADE A ZERO ON THEIR GRADES.\n\n\n";
    } else {
        std::cout << "Average Grade: " << std::setw(5) << std::setfill(' ') << std::right << (CombinedGrades / StudentGrades.size()) << "%\n\n\n";
    }

    return 0;
}
