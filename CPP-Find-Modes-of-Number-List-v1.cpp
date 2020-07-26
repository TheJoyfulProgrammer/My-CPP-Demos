/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    July 24th, 2020
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:      https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ ver 17
    Tested Compilers:         G++ ver 9.3
    Tested Operating Systems: Linux Mint
    Description: This app finds the modes (the most occurring numbers) of a 
                 number list.
*/

#include <iostream>
#include <vector>
#include <algorithm>


namespace ModeNumbers
{
    struct NumberCount
    {
        uint32_t Value;
        uint32_t Count;
    };
    
    std::vector<uint32_t> UserNumberList;
    std::vector<NumberCount> NumberCounts;
}


bool SortIntList(const uint32_t &lhs, const uint32_t &rhs) 
{ 
    return lhs < rhs; 
}


bool SortStructList(const ModeNumbers::NumberCount &lhs, const ModeNumbers::NumberCount &rhs) 
{
     return lhs.Count < rhs.Count; 
}

template <typename TemplateParameter>
void PrintSimpleVector(const std::vector<TemplateParameter> CurrentVector)
{
    std::cout << "{ ";
    
    for(uint32_t Iterator1 = 0; Iterator1 < CurrentVector.size(); Iterator1++)
    {
        std::cout << CurrentVector[Iterator1]
                  << (Iterator1 < CurrentVector.size() - 1 ? ", " : "");
    }
    
    std::cout << "}\n";
}

                           
void PrintMode(const std::vector<ModeNumbers::NumberCount> CurrentVector, const int32_t Position)
{
    std::cout << CurrentVector[Position].Value 
              << " occurs "
              << CurrentVector[Position].Count
              << " time" 
              << (CurrentVector[Position].Count > 1 ? "s" : "") 
              << " and is a mode of the list.\n";
}


int main()
{
    int CinStatus{0};
    int32_t UserValue{0};
    uint32_t CurrentValue{0};
    
    std::cout << "This app will display the Mode (the number(s) duplicated the most times\n"
              << "in a number list.\n\n"\
              << "You can create a list of numbers by entering them, one-by-one, on each\n"
              << "line below. Enter a negative number to let the computer know your done\n"
              << "creating you list\n\n";

    do
    {
        do
        {
            CinStatus = true;
            
            std::cout << "Value #" << (CurrentValue + 1) << ": ";
            std::cin >> UserValue;
            
            if (std::cin.fail()) {
                CinStatus = false;

                std::cin.clear();
                while ((getchar()) != '\n');

                std::cout << "ERROR: Invalid input. Please try again.\n\n";
            } else {
                if((CurrentValue < 3) & (UserValue < 0))
                {
                    std::cout << "You must enter three or more integer values.\n\n";
                    UserValue = 0;
                } else {
                    if(UserValue >= 0)
                    {
                        ModeNumbers::UserNumberList.push_back(UserValue);
                    }
                    
                    CurrentValue++;
                }
            }
        } while (!CinStatus);
    } while(UserValue >= 0);
    
    
    
    std::cout << "\nUser number set:\n";
    PrintSimpleVector(ModeNumbers::UserNumberList);
  
    
    std::sort(ModeNumbers::UserNumberList.begin(), ModeNumbers::UserNumberList.end(), SortIntList);
    
    
    std::cout << "\nSorted number set:\n";
    PrintSimpleVector(ModeNumbers::UserNumberList);
    std::cout << "\n";
  
    
    std::sort(ModeNumbers::UserNumberList.begin(), ModeNumbers::UserNumberList.end(), SortIntList);
    
    
    ModeNumbers::NumberCount CurrentNumberCounter{ModeNumbers::UserNumberList[0], (uint32_t) 1};
    
    
    for(uint32_t Iterator1 = 1; Iterator1 < ModeNumbers::UserNumberList.size(); Iterator1++)
    {
        if(ModeNumbers::UserNumberList[Iterator1] == CurrentNumberCounter.Value)
        {
            CurrentNumberCounter.Count++;
        } else {
            ModeNumbers::NumberCounts.push_back(ModeNumbers::NumberCount{CurrentNumberCounter.Value, CurrentNumberCounter.Count});
            CurrentNumberCounter.Value = ModeNumbers::UserNumberList[Iterator1];
            CurrentNumberCounter.Count = 1;            
        }
    }
    
    ModeNumbers::NumberCounts.push_back(ModeNumbers::NumberCount{CurrentNumberCounter.Value, CurrentNumberCounter.Count});
    
   
    std::sort(ModeNumbers::NumberCounts.begin(), ModeNumbers::NumberCounts.end(), SortStructList);
    
    
    for(int32_t Iterator1 = ModeNumbers::NumberCounts.size() - 1; Iterator1 >= 0; Iterator1--)
    {
        std::cout << "The value " << ModeNumbers::NumberCounts[Iterator1].Value 
                  << " is in the list " << ModeNumbers::NumberCounts[Iterator1].Count
                  << " times.\n";
    }
    std::cout << "\n";
    
    uint32_t HighestNumberCount{ModeNumbers::NumberCounts[ModeNumbers::NumberCounts.size() - 1].Count};
    
    PrintMode(ModeNumbers::NumberCounts, ModeNumbers::NumberCounts.size() - 1);
    
    for(int32_t Iterator1 = ModeNumbers::NumberCounts.size() - 2; Iterator1 >= 0; Iterator1--)
    {
        if(ModeNumbers::NumberCounts[Iterator1].Count == HighestNumberCount)
        {
            PrintMode(ModeNumbers::NumberCounts, Iterator1);
        } else {
            break;
        }
    }
}
