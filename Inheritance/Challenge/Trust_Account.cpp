#include "Trust_Account.h"
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, limit_count{0} {}

bool Trust_Account::deposit(double amount)
{
  if (amount >= bonous_threshold)
    amount += bonus_amount;
  return Savings_Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount)
{
  if (limit_count >= max_num_withdrawal || amount >= (balance * withdraw_limit_percent))
  {
    std::cout << "Withdrawal Failed - Withdrawal limit Exceeded(" << max_num_withdrawal << ") or Amount exceeded" << withdraw_limit_percent << "%" << "of balance" << std::endl;
    return false;
  }
  else
  {
    ++limit_count;
    return Account::withdraw(amount);
  }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
  os << "Trust_Account: " << account.name << "\nTrust_Account balance: " << account.balance << "\nInterest rate: " << account.int_rate << "%";

  return os;
}