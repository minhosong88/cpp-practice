#include <iostream>

using namespace std;

int main()
{

  char selection{};
  do
  {
    cout << "\n------------------" << endl;
    cout << "1. Character Edit" << endl;
    cout << "2. Item Edit" << endl;
    cout << "3. file Edit" << endl;
    cout << "E. Exit" << endl;
    cout << "\n Enter your selection:" << endl;
    cin >> selection;

    if (selection == '1')
      cout << "You chose 1 - Character Edited" << endl;
    else if (selection == '2')
      cout << "You chose 2 - Item Edited" << endl;
    else if (selection == '3')
      cout << "You chose 3 - File Edited" << endl;
    else if (selection == 'e' || selection == 'E')
      cout << "Good Bye" << endl;
    else
      cout << "Unknown option, try again...";

  } while (selection != 'e' && selection != 'E');

  cout << endl;
  return 0;
}