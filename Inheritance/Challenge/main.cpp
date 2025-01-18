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

  // Accounts

  vector<Account> accounts;
  accounts.push_back(Account{});
  accounts.push_back(Account{"Minho"});
  accounts.push_back(Account{"Sunha", 1000});
  accounts.push_back(Account{"Jianjun", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  // Savings

  vector<Savings_Account> sav_accs;
  sav_accs.push_back(Savings_Account{});
  sav_accs.push_back(Savings_Account{"Minho"});
  sav_accs.push_back(Savings_Account{"Sunha", 2000});
  sav_accs.push_back(Savings_Account{"Jianjun", 5000, 5.0});

  display(sav_accs);
  deposit(sav_accs, 1000);
  withdraw(sav_accs, 2000);

  // Checking

  vector<Checking_Account> chk_accs;
  chk_accs.push_back(Checking_Account{});
  chk_accs.push_back(Checking_Account{"Minho"});
  chk_accs.push_back(Checking_Account{"Sunha", 2000});
  chk_accs.push_back(Checking_Account{"Jianjun", 5000});

  display(chk_accs);
  deposit(chk_accs, 1000);
  withdraw(chk_accs, 2000);

  // Trust
  vector<Trust_Account> trst_accs;
  trst_accs.push_back(Trust_Account{});
  trst_accs.push_back(Trust_Account{"Minho", 10000, 5.0});
  trst_accs.push_back(Trust_Account{"Sunha", 2000, 4.0});
  trst_accs.push_back(Trust_Account{"Jianjun", 50000, 5.0});

  display(trst_accs);
  deposit(trst_accs, 1000);
  withdraw(trst_accs, 2000);

  for (int i = 1; i < 4; i++)
  {
    withdraw(trst_accs, 1000);
  }

  return 0;
}