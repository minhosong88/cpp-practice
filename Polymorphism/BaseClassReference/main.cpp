#include <iostream>
#include <vector>

using namespace std;
class Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Account::withdraw" << std::endl;
  }
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Checking::withdraw" << std::endl;
  }

  virtual ~Checking() {}
};

class Savings : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Savings::withdraw" << std::endl;
  }
  virtual ~Savings() {}
};

class Trust : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Trust::withdraw" << std::endl;
  }
  virtual ~Trust() {}
};

void do_withdraw(Account &account, double amount)
{
  account.withdraw(amount);
}

int main()
{
  Account a;
  Account &ref = a;
  ref.withdraw(1000);

  Trust b;
  Trust &ref2 = b;
  ref2.withdraw(1000);

  Account a1;
  Savings a2;
  Checking a3;
  Trust a4;

  do_withdraw(a1, 1000);
  do_withdraw(a2, 1000);
  do_withdraw(a3, 1000);
  do_withdraw(a4, 1000);

  cout << endl;
  return 0;
}