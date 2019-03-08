#include <iostream>
#include <csignal>

using namespace std;

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here
   // terminate program

   exit(signum);
}

int main () {
   // register signal SIGINT and signal handler
   signal(SIGINT, signalHandler);

   while(1) {
      for(unsigned long long int i = 0; i < 99999999; i++) {}
      cout << "Going to sleep...." << endl;
   }

   return 0;
}
