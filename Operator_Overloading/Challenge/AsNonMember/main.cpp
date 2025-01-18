#include "Mystring.h"
#include <iostream>

using namespace std;

int main()
{
  cout << boolalpha << endl;

  Mystring a{"minho"};
  Mystring b{"minho"};

  cout << (a == b) << endl;
  cout << (a != b) << endl;

  b = "garbage";
  cout << (a == b) << endl;
  cout << (a != b) << endl;
  cout << (a < b) << endl;
  cout << (a > b) << endl;

  Mystring s1{"MINHO"};
  s1 = -s1;
  cout << s1 << endl;

  s1 = s1 + "XX";
  cout << s1 << endl;

  Mystring s2{"12345"};
  s1 = s2 * 3;
  cout << s1 << endl;

  Mystring s3{"abc"};
  s3 *= 5;

  Mystring s = "Minho";
  ++s;
  cout << s << endl;

  Mystring result;
  s = -s;
  cout << s << endl;
  result = s++;
  cout << s << endl;
  cout << result << endl;
  cout
      << endl;

  return 0;
}