#include <iostream>

using namespace std;

class Account
{
  friend ostream &operator<<(ostream &os, const Account &acc);

public:
  virtual void withdraw(double amount)
  {
    cout << "Account::withdraw" << endl;
  }
  virtual ~Account() {}
};

ostream &operator<<(ostream &os, const Account &acc)
{
  os << "Account display";
  return os;
}

class Checking : public Account
{
  friend ostream &operator<<(ostream &os, const Checking &acc);

public:
  virtual void withdraw(double amount)
  {
    cout << "Checking::withdraw" << endl;
  }
  virtual ~Checking() {}
};
ostream &operator<<(ostream &os, const Checking &acc)
{
  os << "Checking display";
  return os;
}

class Savings : public Account
{
  friend ostream &operator<<(ostream &os, const Savings &acc);

public:
  virtual void withdraw(double amount)
  {
    cout << "Savings::withdraw" << endl;
  }
  virtual ~Savings() {}
};
ostream &operator<<(ostream &os, const Savings &acc)
{
  os << "Savings display";
  return os;
}

class Trust : public Account
{
  friend ostream &operator<<(ostream &os, const Trust &acc);

public:
  virtual void withdraw(double amount)
  {
    cout << "Trust::withdraw" << endl;
  }
  virtual ~Trust() {}
};
ostream &operator<<(ostream &os, const Trust &acc)
{
  os << "Trust display";
  return os;
}
int main()
{
  Account *p1 = new Account();
  cout << *p1 << endl;
  Account *p2 = new Checking();
  cout << *p2 << endl;

  cout << endl;
  return 0;
}