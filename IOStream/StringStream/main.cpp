#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main()
{

  int num{};
  double total{};
  string name{};
  string info{"Moe 100 1234.5"};
  cout << " ----------------Input Example---------------" << endl;

  istringstream iss{info};
  iss >> name >> num >> total;
  cout << setw(10) << left << name << setw(5) << num << setw(10) << total << endl;
  cout << " \n----------------Output Example---------------" << endl;
  ostringstream oss{};
  oss << setw(10) << left << name << setw(5) << num << setw(10) << total << endl;
  cout << oss.str() << endl;

  cout << " \n-----------Data Validation Example-----------" << endl;

  int value{};
  string entry{};
  bool done = false;
  do
  {
    cout << "Please enter an integer: ";
    cin >> entry;
    istringstream validator{entry};
    if (validator >> value)
      done = true;
    else
      cout << "Sorry, that's not an integer" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // extract integer and clean up the leftover strings in the buffer.
  } while (!done);

  cout << "You entered the integer: " << value << endl;

  cout << endl;

  return 0;
}