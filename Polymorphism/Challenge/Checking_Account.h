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
private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double transaction_fee = 1.50;

public:
  Checking_Account(std::string name = def_name, double balance = def_balance);
  virtual bool withdraw(double amount) override;
  virtual bool deposit(double amount) override;
  virtual void print(std::ostream &os) const override;
  virtual ~Checking_Account() = default;
};
#endif