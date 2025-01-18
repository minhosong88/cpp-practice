#include "Account.h"
#include <iostream>

using namespace std;

int main()
{
  Account minho_acc;
  minho_acc.set_name("Minho Account");
  minho_acc.set_balance(1000.0);

  if (minho_acc.deposit(200.0))
    cout << "Success" << endl;
  else
    cout << "Failed" << endl;

  if (minho_acc.withdraw(500.0))
    cout << "Success" << endl;
  else
    cout << "Not enough Money" << endl;

  if (minho_acc.withdraw(1500.0))
    cout << "Success" << endl;
  else
    cout << "Not enough Money" << endl;

  cout << endl;
  return 0;
}