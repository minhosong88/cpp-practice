#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
  // Use Account Class
  cout << "\n==========Account=============" << endl;
  Account acc{};
  acc.deposit(2000.0);
  acc.withdraw(500.0);

  cout << endl;

  Account *p_acc{nullptr};
  p_acc = new Account();
  p_acc->deposit(1000.0);
  p_acc->withdraw(500.0);
  delete p_acc;

  // Use Savings Account Class
  cout << "\n==========Savings Account=============" << endl;
  Savings_Account sav_acc{};
  sav_acc.deposit(2000.0);
  sav_acc.withdraw(500.0);
  cout << endl;

  Savings_Account *p_save_acc{nullptr};
  p_save_acc = new Savings_Account();
  p_save_acc->deposit(1000.0);
  p_save_acc->withdraw(500.0);
  delete p_save_acc;

  return 0;
}