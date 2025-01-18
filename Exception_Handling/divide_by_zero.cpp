#include <iostream>

using namespace std;

int main()
{

  int miles{};
  int gallons{};
  bool go{true};
  double miles_per_gallon{};
  while (go)
  {
    cout << "Enter the miles:";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;
    // Error Handling without try-catch block
    // if (gallons != 0)
    // {
    //   miles_per_gallon = static_cast<double>(miles) / gallons;
    // }
    // else
    // {
    //   cerr << "Sorry, can't divide by zero" << endl;
    //   go = false;
    // }

    // Exception handling with try-catch
    try
    {
      if (gallons == 0)
        throw 0;
      miles_per_gallon = static_cast<double>(miles) / gallons;
      cout << "Result: " << miles_per_gallon << endl;
    }
    catch (int &ex) // best practice: catch error by its reference
    {
      cerr << "Sorry, you cannot divide by zero" << endl;
      go = false;
    }
  }

  cout << endl;
  return 0;
}