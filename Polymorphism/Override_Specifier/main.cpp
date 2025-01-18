#include <iostream>

using namespace std;
class Base
{
public:
  virtual void say_hello() const
  {
    cout << "Hello- I am a Base class object" << endl;
  }
  virtual ~Base() {}
};

class Derived : public Base
{
public:
  virtual void say_hello() const override // forgot const
  {
    cout << "Hello- I am a Derived class object" << endl;
  }
  virtual ~Derived() {}
};
int main()
{

  Base *p1 = new Base();
  p1->say_hello();

  Derived *p2 = new Derived();
  p2->say_hello();

  Base *p3 = new Derived();
  p3->say_hello();

  cout << endl;
  return 0;
}