#include "Mystring.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  Mystring a{"Hello"}; // overloaded constructor
  a = Mystring{"Hola"};
  a = "Bonjour";

  Mystring empty;
  Mystring larry("Larry");
  Mystring stooge{larry}; // copy constructor
  Mystring stooges;

  empty = stooge; // copy assignment operator since stooge is an l-value

  empty = "Funny"; // move assignment operator "Funny" is an r-value

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
    s = "changed"; // move assignment

  cout << "=========Loop3==========" << endl;
  for (const Mystring &s : stooges_vec)
    s.display();

  return 0;
}