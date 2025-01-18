#include <iostream>
#include <vector>
#include "Account_Util.h"
#include "Account.h"
#include "Trust_Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
  cout.precision(2);
  cout << fixed;

  // Accounts : Abstract , Cannot instantiate
  // Account joe;
  Checking_Account c;
  cout << c << endl;

  Savings_Account s{"Minho", 5000, 2.6};
  s.deposit(10000);
  cout << s << endl;
  s.withdraw(10000);
  cout << s << endl;

  Account *ptr = new Trust_Account("Minho", 10000, 2.6);
  cout << *ptr << endl;

  return 0;
}