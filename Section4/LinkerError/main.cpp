#include <iostream>

using namespace std;
extern int x;

int main()
{
  cout << "Linker Error" << endl;
  cout << x; // undefined external variable reference
  return 0;
}