#include <iostream>

using namespace std;

class I_Printable
{
  friend ostream &operator<<(ostream &os, const I_Printable &obj);

public:
  virtual void print(ostream &os) const = 0;
};
ostream &operator<<(ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account : public I_Printable
{
public:
  virtual void withdraw(double amount)
  {
    cout << "Account::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Account display";
  }
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  virtual void withdraw(double amount)
  {
    cout << "Checking::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Checking display";
  }
  virtual ~Checking() {}
};

class Savings : public Account
{
public:
  virtual void withdraw(double amount)
  {
    cout << "Savings::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Savings display";
  }
  virtual ~Savings() {}
};

class Trust : public Account
{
public:
  virtual void withdraw(double amount)
  {
    cout << "Trust::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Trust display";
  }
  virtual ~Trust() {}
};
class Dog : public I_Printable
{
public:
  virtual void print(ostream &os) const override
  {
    os << "Woof Woof";
  }
  virtual ~Dog() {}
};

void print(const I_Printable &obj)
{
  cout << obj << endl;
}

int main()
{
  Dog *dog = new Dog();
  cout << *dog << endl;
  print(*dog);
  Account *p1 = new Account();
  cout << *p1 << endl;
  Account *p2 = new Checking();
  cout << *p2 << endl;

  cout << endl;
  return 0;
}