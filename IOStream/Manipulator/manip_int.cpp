#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int num{255};
  cout << "\n------------------------" << endl;
  cout << dec << num << endl;
  cout << hex << num << endl;
  cout << oct << num << endl;

  cout << "\n------------------------" << endl;
  cout << showbase;
  cout << dec << num << endl;
  cout << hex << num << endl; // prefix 0X for hex
  cout << oct << num << endl; // prefix 0 for oct

  cout << "\n------Uppercase for Hex------------------" << endl;
  cout << showbase << uppercase;
  cout << hex << num << endl;

  cout << "\n---------ShowPos for Dec---------------" << endl;
  cout << showpos;
  cout << dec << num << endl;
  cout << hex << num << endl;
  cout << oct << num << endl;

  cout << "\n-------Set Method-----------------" << endl;

  cout.setf(ios::showbase);
  cout.setf(ios::uppercase);
  cout.setf(ios::showpos);
  cout << "\n-------Reset IO Flags------------" << endl;

  cout << resetiosflags(ios::basefield);
  cout << resetiosflags(ios::showbase);
  cout << resetiosflags(ios::showpos);
  cout << resetiosflags(ios::uppercase);
  cout << "\n------------------------" << endl;
  cout << "Enter an Integer: ";
  cin >> num;

  cout << "Decimal default: " << num << endl;
  cout << "Hexadeciam : " << hex << num << endl;
  cout << "Hexadeciam : " << hex << num << uppercase << endl;
  cout << "Hexadeciam : " << hex << num << endl;
  cout << "Hexadeciam : " << hex << num << nouppercase << endl;

  cout << "Octal : " << oct << num << endl;
  cout << "Hexadeciam : " << hex << showbase << num << endl;
  cout << "Octal : " << oct << num << endl;

  cout << endl;
  return 0;
}