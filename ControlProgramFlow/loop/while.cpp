#include <iostream>

using namespace std;

int main()
{
  int num{};
  // cout << "Enter a positive integer - start the countdown:";
  // cin >> num;

  // while (num > 0)
  // {
  //   cout << num << endl;
  //   --num;
  // }

  // cout << "Blastoff!!" << endl;

  // cout << "Enter a positive integer to count up to:";
  // cin >> num;

  // int i{1};
  // while (num >= i)
  // {
  //   cout << i << endl;
  //   ++i;
  // }

  // cout << "Enter an integer less than 100: ";
  // cin >> num;

  // while (num >= 100)
  // {
  //   cout << "Enter an integer less than 100:";
  //   cin >> num;
  // }

  // cout << "Thanks" << endl;
  // cout << endl;

  bool done{false}; // explicitly initialize to false

  while (!done) // condition becomes true and loop proceeds while done is false.
  {
    cout << "Enter an integer between 1 and 5:";
    cin >> num;
    if (num <= 1 || num >= 5)
      cout << "Out of range, try again" << endl;
    else
    {
      cout << "Thanks" << endl;
      done = true;
    }
  }

  return 0;
}