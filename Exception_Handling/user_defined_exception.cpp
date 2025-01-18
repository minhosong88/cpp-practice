#include <iostream>
#include <string>
using namespace std;
class DivideByZeroException
{
};
class NegativeValueException
{
};

double calculate_mpg(int miles, int gallons)
{
  if (gallons == 0)
    throw DivideByZeroException();
  if (gallons < 0 || miles < 0)
    throw NegativeValueException();
  return static_cast<double>(miles) / gallons;
}
int main()
{
  string input;
  int miles{0};
  int gallons{0};
  double miles_per_gallons{0};
  while (true)
  {
    cout << "Enter the miles (or 'exit' to exit):";
    cin >> input;
    // Break out of loop if input is 'exit'
    if (input == "exit")
      break;
    // Catch Invalid input
    try
    {
      miles = stoi(input);
    }
    catch (invalid_argument &)
    {
      cout << "Invalid Input: Please enter an integer or 'exit'" << endl;
      continue;
    }

    cout << "Enter the gallons: ";
    cin >> input;
    // Break out of loop if input is 'exit'
    if (input == "exit")
      break;
    // Catch Invalid input
    try
    {
      gallons = stoi(input);
    }
    catch (invalid_argument &)
    {
      cout << "Invalid Input: Please enter an integer or 'exit'" << endl;
      continue;
    }
    try
    {
      miles_per_gallons = calculate_mpg(miles, gallons);
      cout << "Result: " << miles_per_gallons << endl;
    }
    catch (DivideByZeroException &e)
    {
      cerr << "Sorry, can't divide by zero" << endl;
    }
    catch (NegativeValueException &e)
    {
      cerr << "Sorry, one of your parameters is negative" << endl;
    }
  }

  cout << "Bye" << endl;
  return 0;
}