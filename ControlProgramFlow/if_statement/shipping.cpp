#include <iostream>
#include <iomanip>
/*
shipping cost calcluator

ask the user for package dimension in inches
length, width, height - integers

all dimension must be 10 inches or less or we cannot ship it

Base cost $ 2.50
if package colume is greather than 100 cubic inches there is a 10% surcharge
if package colume is greather than 500 cubic inches there is a 25% surcharge


*/
using namespace std;

int main()
{
  int length{}, width{}, height{};
  double base{2.50};

  const int tier1_threshold{100};
  const int tier2_threshold{500};

  const int max_dimension_length{10};

  const double tier1_surcharge{0.10};
  const double tier2_surcharge{0.25};

  int package_volume{};
  cout << "Welcome to the package cost calculator" << endl;
  cout << "Enter length, width, and height of the package separated by spaces:";
  cin >> length >> width >> height;

  if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length)
  {
    cout << "Sorry, package rejected - dimension exceeded" << endl;
  }
  else
  {
    double package_cost{};
    package_volume = length * height * width;
    package_cost = base;
    if (package_volume > tier2_threshold)
    {
      package_cost += package_cost * tier2_surcharge;
      cout << "Adding tier2 surcharge" << endl;
    }
    else if (package_volume > tier1_threshold)
    {
      package_cost += package_cost * tier1_surcharge;
      cout << "Adding tier1 surcharge" << endl;
    }
    cout << fixed << setprecision(2);
    cout << "The volume of your package is: " << package_volume << endl;
    cout << "Your package will cost $" << package_cost << endl;
  }

  cout << endl;
  return 0;
}