#include "Checking_Account.h"
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance}
{
}

bool Checking_Account::withdraw(double amount)
{
  amount += transaction_fee;
  return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
  os << "Checking_Account: " << account.name << "\nChecking_Account balance: " << account.balance;

  return os;
}