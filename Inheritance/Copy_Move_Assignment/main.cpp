#include <iostream>

using namespace std;

class Base
{
private:
  int value;

public:
  Base() : value{0} { cout << "Base no arges Constructor" << endl; }
  Base(int x) : value{x} { cout << "Base (int) overloaded Constructor" << endl; }
  // Copy Constructor
  Base(const Base &other) : value{other.value}
  {
    cout << "Base Copy Constructor" << endl;
  }
  // Copy Assignment Operator
  Base &operator=(const Base &rhs)
  {
    cout << "Base Operator=" << endl;
    if (this == &rhs)
      return *this;
    value = rhs.value;
    return *this;
  }

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

  // Copy Constructor
  Derived(const Derived &other)
      : Base(other), doubled{other.doubled}
  {
    cout << "Derived Copy Constructor" << endl;
  }
  // Copy Assignment
  Derived &operator=(const Derived &rhs)
  {
    cout << "Derived Operator =" << endl;
    if (this == &rhs)
      return *this;
    Base::operator=(rhs);
    doubled = rhs.doubled;
    return *this;
  }

  ~Derived() { cout << "Derived Destructor" << endl; }
};

int main()
{
  // Base b{100};
  // Base b1{b};
  // b = b1;

  Derived d{100}; // Overloaded Constructor
  Derived d1{d};  // Copy Constructor
  d = d1;         // Copy Assignment

  return 0;
}