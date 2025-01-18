#include <iostream>

using namespace std;
int counter{0}; // Global variable

void incrementCounter()
{
  counter++;
  cout << "Conter incremented to: " << counter << endl;
}

void resetCounter()
{
  counter = 0;
  cout << "counter reset to: " << counter << endl;
}

int main()
{
  cout << "Initial counter value: " << counter << endl;

  incrementCounter();
  incrementCounter();
  incrementCounter();
  resetCounter();

  return 0;
}