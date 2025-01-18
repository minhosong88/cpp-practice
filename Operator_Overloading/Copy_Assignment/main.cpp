#include "Mystring.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  Mystring a{"Hello"}; // overloaded constructor
  Mystring b;          // no args constructor
  b = a;               // b.operator={a}

  b = "This is a test"; // b.operator={"This is a test"};

  Mystring empty;
  Mystring larry("Larry");
  Mystring stooge{larry};
  Mystring stooges;

  empty = stooge;

  empty.display();
  larry.display();
  stooge.display();

  stooges = "Larry, Moe, and Curly";
  stooges.display();

  vector<Mystring> stooges_vec;
  stooges_vec.push_back("Larry");
  stooges_vec.push_back("Moe");
  stooges_vec.push_back("Curly");

  cout << "=========Loop1==========" << endl;
  for (const Mystring &s : stooges_vec)
    s.display();

  cout << "=========Loop2==========" << endl;
  for (Mystring &s : stooges_vec)
    s = "changed"; // copy assignment

  cout << "=========Loop3==========" << endl;
  for (const Mystring &s : stooges_vec)
    s.display();

  return 0;
}