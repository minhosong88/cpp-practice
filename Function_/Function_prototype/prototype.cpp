#include <iostream>
#include <cmath>
using namespace std;

// function prototype
double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);
void area_circle();
void volume_cylinder();

const double pi{3.14159};

int main()
{

  area_circle();
  volume_cylinder();

  cout << endl;
  return 0;
}

double calc_area_circle(double radius)
{
  return pi * pow(radius, 2);
}

void area_circle()
{
  double radius{};
  cout << "\n Enter the radius of the circle: ";
  cin >> radius;

  cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

double calc_volume_cylinder(double radius, double height)
{
  // return pi * pow(radius, 2) * height;
  return calc_area_circle(radius) * height;
}

void volume_cylinder()
{
  double radius{};
  double height{};
  cout << "\n Enter the radius of the cylinder and height separated by a space: ";
  cin >> radius >> height;

  cout << "\n The volumne of a cyliner with height " << height << " and radius " << radius << " is " << calc_volume_cylinder(radius, height) << endl;
}