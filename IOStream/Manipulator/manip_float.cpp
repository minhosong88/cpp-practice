#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double num1{123456789.98765431};
  double num2{1234.5678};
  double num3{1234.0};

  // Using default setting
  cout << "------Default(Precision 6)---------" << endl;
  cout << num1 << endl; // 1.23457e+08
  cout << num2 << endl; // 1234.57 (round after 6 digits)
  cout << num3 << endl; // 1234

  cout << "------Set Precision 2---------" << endl;
  cout << setprecision(2);
  cout << num1 << endl; // 1.2e+08
  cout << num2 << endl; // 1.2e+03
  cout << num3 << endl; // 1.2e+03

  cout << "------Set Precision 5---------" << endl;
  cout << setprecision(5);
  cout << num1 << endl; // 1.2346e+08
  cout << num2 << endl; // 1234.6
  cout << num3 << endl; // 1234

  cout << "------Set Precision 9---------" << endl;
  cout << setprecision(9);
  cout << num1 << endl; // 1.234567890
  cout << num2 << endl; // 1234.5678
  cout << num3 << endl; // 1234

  cout << "------Set Precision 3 and fixed---------" << endl;
  cout << setprecision(3) << fixed;
  cout << num1 << endl; // 123456789.988
  cout << num2 << endl; // 1234.568
  cout << num3 << endl; // 1234.000

  cout << "------Set Precision 3 and scientific---------" << endl;
  cout << scientific;
  cout << num1 << endl; // 1.235e+08
  cout << num2 << endl; // 1.235e+03
  cout << num3 << endl; // 1.234e+03

  cout << "------Set Precision 3 and Uppercase---------" << endl;
  cout << uppercase;
  cout << num1 << endl; // 1.235E+08
  cout << num2 << endl; // 1.235E+03
  cout << num3 << endl; // 1.234E+03

  cout << "------Set Precision 3 and ShowPositive---------" << endl;
  cout << showpos;
  cout << num1 << endl; // +1.235E+08
  cout << num2 << endl; // +1.235E+03
  cout << num3 << endl; // +1.234E+03

  cout << "------Back to Default---------" << endl;
  cout.unsetf(ios::scientific | ios::fixed);
  cout << resetiosflags(ios::showpos);

  cout << "------Precision 10 and ShowPoint---------" << endl;
  cout << setprecision(10) << showpoint;

  cout << num1 << endl; // 123456789.0
  cout << num2 << endl; // 1234.567800
  cout << num3 << endl; // 1234.000000
  cout << "------Back to Default Again---------" << endl;
  cout.unsetf(ios::scientific | ios::fixed);
  cout << resetiosflags(ios::showpos);
  cout << resetiosflags(ios::showpoint);
  cout << setprecision(6);
  cout << num1 << endl; // 1.23457e+08
  cout << num2 << endl; // 1234.57 (round after 6 digits)
  cout << num3 << endl; // 1234
  cout << endl;

  return 0;
}