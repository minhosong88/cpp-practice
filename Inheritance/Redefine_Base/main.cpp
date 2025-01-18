#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
  // Use Account Class
  cout << "\n==========Account=============" << endl;
  Account acc{2000.0};
  cout << acc << endl;

  acc.deposit(500.0);
  cout << acc << endl;
  acc.withdraw(1000.0);
  cout << acc << endl;
  acc.withdraw(5500.0);
  cout << acc << endl;

  // Use Savings Account Class
  cout << "\n==========Savings Account=============" << endl;
  Savings_Account sav_acc{2000.0, 5.0};
  cout << sav_acc << endl;

  sav_acc.deposit(1000);
  cout << sav_acc << endl;

  sav_acc.withdraw(500.0);
  cout << sav_acc << endl;

  sav_acc.withdraw(5000.0);
  cout << sav_acc << endl;

  cout << endl;

  return 0;
}