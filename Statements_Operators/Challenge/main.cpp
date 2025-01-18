#include <iostream>

using namespace std;
/*
Ask the user to enter the following:
An integer representing the number of cents

Assume that the number of cents is greater than or equal to zero

Display how to provide that change to the user

In the US:
  1 dollar is 100 cents
  1 quarter is 25 cents
  1 dime is 10 cents
  1 nickel is  5 cents,
  1 penny is 1 cent.

Sample:
Enter an amount in cents: 92
provide this change as follows:
dollars: 0
quarters: 3
dime: 1
nickel : 1
penny:2

*/
int main()
{
  cout << "Enter an amount in cents: ";
  int cents{0};
  cin >> cents;
  const int dollar{100};
  const int quarter{25};
  const int dime{10};
  const int nickel{5};
  const int penny{1};

  int dollars{}, quarters{}, dimes{}, nickels{}, pennies{}, remainder{};
  dollars = cents / dollar;
  remainder = cents % dollar;

  quarters = remainder / quarter;
  remainder = remainder % quarter;

  dimes = remainder / dime;
  remainder = remainder % dime;

  nickels = remainder / nickel;
  pennies = remainder % nickel;

  cout << "Provide this change as follows:" << endl;
  cout << "dollars: " << dollars << endl;
  cout << "quarters: " << quarters << endl;
  cout << "dimes: " << dimes << endl;
  cout << "nickels: " << nickels << endl;
  cout << "pennies: " << pennies << endl;

  return 0;
}