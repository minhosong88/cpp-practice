#include <iostream>

using namespace std;
/*
* Sample output
Estimate for carpet cleaning service:
Number of rooms: 2
Price per room: 30
cost: 60
tax: 3.6
======================================
Total estimate: 63.6
This estimate is valid for 30 days

Pseudocode:
  Prompt the user to enter the number of rooms
  Display number of rooms
  Display price per room
  Display cost: (number of rooms * price per room)
  Display tax: (num of rooms * price per room * tax rate)
  Display total estimate: cost + tax
  Display estimate expiration time

*/
int main()
{
  cout << "Hello, welcome to Minho's Carpet Cleaning Service" << endl
       << endl;
  // prompt user to enter the num of rooms
  cout << "How many rooms would you like cleaned? :";
  int num_of_rooms{0};
  cin >> num_of_rooms;
  const double price_per_room{30.0};
  const double sales_tax{0.06};
  const int estimate_expiry{30};
  int cost = num_of_rooms * price_per_room;
  int tax = cost * sales_tax;
  int estimate_total = cost + tax;

  cout << "\nEstimate for carpet cleaning service" << endl;
  cout << "Number of rooms: " << num_of_rooms << endl;
  cout << "Price per room: $" << price_per_room << endl; // using a literal constant
  cout << "Cost : $" << cost << endl;
  cout << "Tax : $" << tax << endl;
  cout << "===============================" << endl;

  cout << "Total Estimate: $" << estimate_total << endl;
  cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

  return 0;
}