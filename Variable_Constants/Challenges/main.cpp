#include <iostream>

using namespace std;
/*
Charges:
  $25 per small room
  $35 per large room
Tax rate: 6%
Estimates are valid for 30 days

Prompt the user for the number of small and large rooms they would like cleaned and provide an estimate such as:
* Sample output
Estimate for carpet cleaning service:
Number of small rooms: 2
Number of large rooms: 2
Price per small room: 25
Price per large room: 35
cost: 120
tax: 7.2
======================================
Total estimate: 127.2
This estimate is valid for 30 days

*/
double calculate_cost(int num1, int num2, double price1, double price2)
{
  return (num1 * price1) + (num2 * price2);
}

double calculate_tax(double total, double rate)
{
  return total * rate;
}

int main()
{
  cout << "Hello, welcome to Minho's Carpet Cleaning Service " << endl;
  cout << endl;
  cout << "How many small rooms would you like cleaned?: " << endl;
  int num_sm_rooms{0};
  cin >> num_sm_rooms;
  cout << "How many large rooms would you like cleaned?: " << endl;
  int num_lg_rooms{0};
  cin >> num_lg_rooms;
  const double sales_tax = 0.06;
  const int estimate_expiry = 30;
  const double price_per_sm_room = 25.0;
  const double price_per_lg_room = 35.0;

  cout << "Number of small rooms: " << num_sm_rooms << endl;
  cout << "Number of large rooms: " << num_lg_rooms << endl;
  cout << "Price per Small Room: $" << price_per_sm_room << endl;
  cout << "Price per Large Room: $" << price_per_lg_room << endl;
  double cost = calculate_cost(num_sm_rooms, num_lg_rooms, price_per_sm_room, price_per_lg_room);
  cout << "Cost: $" << cost << endl;
  double tax = calculate_tax(cost, sales_tax);
  cout << "Tax:  $" << tax << endl;
  cout << "===============================================" << endl;
  cout << "Total estimate:" << cost + tax << endl;
  cout << "This estimate is valid for " << estimate_expiry << " days" << endl;
  return 0;
}