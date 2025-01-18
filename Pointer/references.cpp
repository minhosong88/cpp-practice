#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int num{100};
  int &ref{num};
  cout << num << endl; // 100
  cout << ref << endl; // 100

  num = 200;
  cout << "\n----------------" << endl;
  cout << num << endl; // 200
  cout << ref << endl; // 200

  ref = 300;
  cout << "\n----------------" << endl;
  cout << num << endl; // 300
  cout << ref << endl; // 300

  cout << "\n----------------" << endl;
  vector<string> stooges{"minho", "sunha", "jianjun"};

  for (auto str : stooges)
    str = "Funny"; // no change since str is a copy
  for (auto str : stooges)
    cout << str << endl;

  cout << "\n----------------" << endl;
  for (auto &str : stooges) // str is a reference to each vector element '&'
    str = "Funny";          // this is changing
  for (auto const &str : stooges)
    cout << str << endl;

  cout << endl;
  return 0;
}