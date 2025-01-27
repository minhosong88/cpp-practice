#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <vector>
#include <string>
#include "Account.h"
/*
 Checking account has a name/balance/transaction fee of $1.50 per withdrawal
*/
class Checking_Account : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double transaction_fee = 1.50;

public:
  Checking_Account(std::string name = def_name, double balance = def_balance);
  bool withdraw(double amount);
};
#endif