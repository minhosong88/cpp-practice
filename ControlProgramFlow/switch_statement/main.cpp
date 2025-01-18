#include <iostream>

using namespace std;

int main()
{
  cout << "Enter the letter grade you expect on the exam: ";
  char letter_grade{};
  cin >> letter_grade;

  switch (letter_grade)
  {
  case 'a':
  case 'A':
    cout << " You need a 90 or above, study hard!" << endl;
    break;
  case 'b':
  case 'B':
    cout << " You need a 80-89, go study!" << endl;
    break;

  case 'c':
  case 'C':
    cout << " You need a 70-79 for an average grade" << endl;
    break;
  case 'd':
  case 'D':
    cout << " You should strive for a better grade. All you need is 60-69!" << endl;
    break;
  case 'f':
  case 'F':
  {
    char confirm{};
    cout << "Are you sure (Y/N)?:";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
      cout << "OK, I guess you did not study..." << endl;
    else if (confirm == 'n' || confirm == 'N')
      cout << "Good, go study!" << endl;
    else
      cout << "Illegal choice" << endl;
    break;
  }
  default:
    cout << "Sorry, not a valid grade" << endl;
  }

  cout << endl;
  return 0;
}