#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
  void say_hello() const
  {
    cout << "Hello - I'm a Base class object" << endl;
  }
};

class Derived : public Base
{
public:
  void say_hello() const
  {
    cout << "Hello - I'm a Derived class object" << endl;
  }
};

void greetings(const Base &obj)
{
  cout << "Greetings: ";
  obj.say_hello();
}

int main()
{
  // static binding
  Base b;
  b.say_hello();

  Derived d;
  d.say_hello();

  // since obj is a reference to Base
  greetings(b); // Greetings: Hello - I'm a Base class object
  greetings(d); // Greetings: Hello - I'm a Base class object

  Base *ptr = new Derived(); // ptr is able to hold any Base obj
                             // Derived is a Base obj
  ptr->say_hello();          // without dynamic polymorhism, it only points to Base

  unique_ptr<Base> ptr1 = make_unique<Derived>();
  ptr1->say_hello(); // even with smart pointer it does not show Derived say_hello()

  delete ptr;
  cout << endl;
  return 0;
}