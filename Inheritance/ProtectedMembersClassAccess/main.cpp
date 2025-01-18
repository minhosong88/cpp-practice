#include <iostream>

using namespace std;

class Base
{
public:
  int a{0};
  void display()
  {
    cout << a << ", " << b << ", " << c << endl;
  } // member method has access to all

protected:
  int b{0};

private:
  int c{0};
};

class Derived : public Base
{
  // friends of derived only have access to what derived has access to
  // c is not accessbile from derived since it is private
public:
  void access_base_members()
  {
    a = 100;
    b = 200; //  okay since b is protected
    // c = 300; // Not accessible
  }
};

int main()
{
  cout << "======Base Member Acess from Base object ===" << endl;
  Base base;
  base.a = 100;
  // base.b = 200; // Compiler Error
  // base.c = 300; // Compiler Error
  cout << "======Base Member Acess from Derived object ===" << endl;
  Derived d;
  d.a = 100;
  // d.b = 200; // Compiler Error
  // d.c = 300;// Compiler Error

  cout << endl;
  return 0;
}