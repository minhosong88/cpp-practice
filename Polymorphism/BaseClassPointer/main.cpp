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
int main()
{
  cout << "\n ====Pointer=====" << endl;
  Account *p1 = new Account();
  Account *p2 = new Checking();
  Account *p3 = new Savings();
  Account *p4 = new Trust();

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);

  cout << "\n ====Array=====" << endl;
  Account *array[] = {p1, p2, p3, p4};
  for (auto i = 0; i < 4; ++i)
  {
    array[i]->withdraw(1000);
  }

  cout << "\n ====Array=====" << endl;
  array[0] = p4;
  for (auto i = 0; i < 4; ++i)
  {
    array[i]->withdraw(1000);
  }

  cout << "\n ====Vector=====" << endl;
  vector<Account *> accounts{p1, p2, p3, p4};
  for (auto acc_ptr : accounts)
  {
    acc_ptr->withdraw(1000);
  }
  cout << "\n ====Vector=====" << endl;
  accounts.push_back(p4);
  accounts.push_back(p4);
  for (auto acc_ptr : accounts)
  {
    acc_ptr->withdraw(1000);
  }
  cout << "\n ====Clean up=====" << endl;

  delete p1;
  delete p2;
  delete p3;
  delete p4;
  return 0;
}