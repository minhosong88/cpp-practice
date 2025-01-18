#include <iostream>

using namespace std;

class Base
{
private:
  int value;

public:
  Base() : value{0} { cout << "Base no arges Constructor" << endl; }
  Base(int x) : value{x} { cout << "Base (int) overloaded Constructor" << endl; }
  ~Base()
  {
    cout << "Base Destructor" << endl;
  }
};

class Derived : public Base
{
  // using Base::Base
private:
  int doubled;

public:
  Derived() : doubled{0} { cout << "Derived no args constructor" << endl; }
  Derived(int x) : doubled{x * 2} { cout << "Derived (int) overloaded constructor" << endl; }
  ~Derived() { cout << "Derived Destructor" << endl; }
};

int main()
{

  // Base b{100};
  // Derived d;
  Derived d{1000};
  cout << endl;
  return 0;
}