#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include <vector>
#include <string>
#include "Savings_Account.h"
/*
any deposit of $5000.00 or more will receive a $50.00 bonus deposited to the account
only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
*/
class Trust_Account : public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Savings Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  static constexpr int max_num_withdrawal = 3;
  static constexpr double bonus_amount = 50.0;
  static constexpr double bonous_threshold = 5000.0;
  static constexpr double withdraw_limit_percent = 0.2;

protected:
  int limit_count;

public:
  Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif