#include <iostream>
#include <string>

using namespace std;
class Account
{
private:
  // attributes
  string name;
  double balance;

public:
  // methods
  // declare inline
  void set_balance(double bal) { balance = bal; }
  double get_balance() { return balance; }

  // declare outside
  void set_name(string n);
  string get_name();

  bool deposit(double amount);
  bool withdraw(double amount);
};

void Account::set_name(string n)
{
  name = n;
}
string Account::get_name()
{
  return name;
}
bool Account::deposit(double amount)
{
  balance += amount;
  return true;
}
bool Account::withdraw(double amount)
{
  if (balance - amount > 0)
  {
    balance -= amount;
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Account minho_acc;
  minho_acc.set_name("Minho Account");
  minho_acc.set_balance(1000.0);

  if (minho_acc.deposit(200.0))
    cout << "Success" << endl;
  else
    cout << "Failed" << endl;

  if (minho_acc.withdraw(500.0))
    cout << "Success" << endl;
  else
    cout << "Not enough Money" << endl;

  if (minho_acc.withdraw(1500.0))
    cout << "Success" << endl;
  else
    cout << "Not enough Money" << endl;

  cout << endl;
  return 0;
}