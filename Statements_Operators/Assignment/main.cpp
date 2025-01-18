#include <iostream>

using namespace std;

int main()
{
  int num1{10};
  int num2{20};

  num1 = 100;
  // num1=num2;
  // num1 = num2 = 100; //chaining assignment

  cout << "num1 is " << num1 << endl;
  cout << "num2 is " << num2 << endl;

  cout << endl;

  return 0;
}