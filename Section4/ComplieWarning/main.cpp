#include <iostream>

using namespace std;

void warning()
{
  int name;
  name = 10;
  cout << "Hello" << endl; // variable declared but never used
}

int main()
{
  int favorite_number;
  cout << favorite_number << endl; // uninitialized
  warning();
  return 0;
}