#include <iostream>

using namespace std;

double calculate_mpg(int miles, int gallons)
{
  if (gallons == 0)
    throw 0;
  return static_cast<double>(miles) / gallons;
}

int main()
{

  int miles{};
  int gallons{};
  double miles_per_gallon{};
  cout << "Enter the miles:";
  cin >> miles;
  cout << "Enter the gallons: ";
  cin >> gallons;
  try
  {
    miles_per_gallon = calculate_mpg(miles, gallons);
    cout << "Results: " << miles_per_gallon << endl;
  }
  catch (int &e)
  {

    cerr << "Tried to divide by zero" << e << '\n';
  }

  cout << endl;
  return 0;
}