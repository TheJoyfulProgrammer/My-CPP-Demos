/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    Feburary 28th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:      https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C++ ver 17
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This is a Guess-A-Number style game, but with a twist, and personality.
*/

#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
   const int MinNumber{1};
   const int MaxNumber{20};
   const int MaxGuessesLeft{5};

   bool UserAlreadyGuessedThisNumber{0};
   
   int SecretNumber{0};
   int GuessesLeft = MaxGuessesLeft;
   int UserGuessedNumber{0};
   int CinStatus{0};
   
   unsigned int RandomMessage{0};
   long long unsigned int iteration{0};
   
   float ChancePercentageOfGuessingCorrectly{0};
   
   
   
   std::vector<int> UserGuesses;

   std::srand(time(NULL));

   ChancePercentageOfGuessingCorrectly = ((float)MaxGuessesLeft / ((float)MaxNumber - (float)MinNumber + 1)) * 100;
   SecretNumber = std::rand() % MaxNumber + MinNumber;

   std::cout << "###  I am thinking of a number from " 
             << MinNumber 
             << " to " 
             << MaxNumber 
             << ".\n###  I am giving you " 
             << MaxGuessesLeft 
             << " chance"
             << (MaxGuessesLeft > 1 ? "s" : "")
             << " to guess it.\n###  This means you have a " 
             << ChancePercentageOfGuessingCorrectly 
             << "% chance of guessing my number.\n\n\n";

   do
   {
       do
       {
           do
           {
               do
               {
                  CinStatus = true;

                  std::cout << "]  What number am I thinking of? ";
                  std::cin >> UserGuessedNumber;

                  if (std::cin.fail()) {
                      CinStatus = false;

                         // Clear the std::cin error flag
                      std::cin.clear();
                      // Clear the remaining stream buffer 
                      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

                      std::cout << "\n\n###--->  I'm not sure what that answer means, but I know it's not a number\n###--->  "
                                   "from " 
                                << MinNumber 
                                << " to " 
                                << MaxNumber 
                                << ".\n\n\n";
                  }

               } while (!CinStatus);

               // Clear the remaining stream buffer 
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

               if((UserGuessedNumber < MinNumber) or (UserGuessedNumber > MaxNumber))
               {
                   std::cout << "\n\n";

                   if(UserGuessedNumber < 0)
                   {
                       std::cout << "###--->  You should start thinking happy and positive thoughts since I asked\n###--->  "
                                    "for a positive number only.\n";
                   }

                   std::cout << "###--->  I am ignoring your answer of " 
                             << UserGuessedNumber 
                             << " since you are ignoring my rules.\n###--->  I asked you to guess a number from " 
                             << MinNumber 
                             << " to " 
                             << MaxNumber 
                             << ".\n###--->  How hard can that be to follow?\n\n\n";
               }

           } while ((UserGuessedNumber < MinNumber) || (UserGuessedNumber > MaxNumber));

           UserAlreadyGuessedThisNumber = false;
            
           // Use a "Null Statement" to find if the user already selected the number.
           for (iteration = 0; ((iteration < UserGuesses.size()) && (UserGuesses[iteration] != UserGuessedNumber)); iteration++);
           
           // If the iteration value is less than the size of the number of guesses the user has already made,
           // then we know the user has already chosen that number. We do not need to verify that since logic
           // dictates this to be true.
           if (iteration < UserGuesses.size()) UserAlreadyGuessedThisNumber = true;

           if (UserAlreadyGuessedThisNumber == false)
           {
               UserGuesses.push_back(UserGuessedNumber);
           } else {
               std::cout << "\n\n###--->  You have already chosen the number " 
                         << UserGuessedNumber 
                         << ". Please try again\n\n\n";
           }

       } while (UserAlreadyGuessedThisNumber);

       std::cout << "]  You chose the number " 
                 << UserGuessedNumber 
                 << " and ";

       if (UserGuessedNumber < SecretNumber)
       {
            std::cout << "it is lower than the number I am thinking of.\n";
       } else if (UserGuessedNumber > SecretNumber) {
            std::cout << "it is higher than the number I am thinking of.\n";
       } else {
            RandomMessage = rand() % 3;

            switch(RandomMessage) {

                case 0:  std::cout << "you guessed the number I was thinking of!\n]  You win!!!\n";
                         break;

                case 1:  std::cout << "you nailed it!\n]  You disarmed the treasure chest and recieved tons of gold coins!\n";
                         break;

                case 2:  std::cout << "I can't believe you guessed it!\n]  I think you cheated and I'm not playing with you "
                                      "anymore!\n";
                         break;
            }

            if (GuessesLeft == 1)
            {
                RandomMessage = rand() % 2;

                switch(RandomMessage) {

                    case 0:  std::cout << "\n\n###\n###  Whoa! That was a very close call! You guessed my number on your "
                                          "last try!\n###\n";
                             break;

                    case 1:  std::cout << "\n\n###\n###  I think you already knew my number and waited until the last moment "
                                          "just\n###  for thrill of the suspense, and to make everyone else sweat so you can"
                                          "\n###  have a great laugh at our expense.\n###\n";
                             break;
                }
            }
            break;
       }

       GuessesLeft--;

       if (GuessesLeft > 0)
       {
          std::cout << "\n\n###  You have " 
                    << GuessesLeft 
                    << " more chance" 
                    << (GuessesLeft > 1 ? "s" : "")
                    << " left to guess the number I am thinking of.\n\n\n";
       }

  } while (GuessesLeft > 0);

  if (GuessesLeft == 0)
  {
      RandomMessage = rand() % 3;

      switch(RandomMessage) {

            case 0:  std::cout << "\n\n###\n###\n###  You did not guess the number I was thinking of within the " 
                               << MaxGuessesLeft 
                               << " guess"
                               << (MaxGuessesLeft > 1 ? "es" : "")
                               << "\n###  I gave you.\n###  Better luck next time!\n###\n###\n\n";
                     break;

            case 1:  std::cout << "\n\n###\n###\n###  Well, you are not a winner this time. Please try again.\n###\n###\n\n";
                     break;

            case 2:  std::cout << "\n\n###\n###\n###  Well, you failed to disarm the trap, and the treasure\n###  chest "
                                  "exploded disintegrating all the gold coins inside.\n###  Please try again.\n###\n###\n\n";
                     break;
      }
  }
}

