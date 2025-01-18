#include "Checking_Account.h"
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance}
{
}

bool Checking_Account::deposit(double amount)
{
  return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount)
{
  amount += transaction_fee;
  return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const
{
  std::cout << "======================" << std::endl;
  std::cout << "Checking Account Name:" << name << "\nChecking Account balance: " << balance;
}