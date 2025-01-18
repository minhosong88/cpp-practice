#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << "==================" << endl;
  cout << "noboolalpha -default(10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha -default(10 == 20): " << (20 == 10) << endl;
  cout << "==================" << endl;

  cout << boolalpha;
  cout << "boolalpha -(10 == 10): " << (10 == 10) << endl;
  cout << "boolalpha -(10 == 20): " << (20 == 10) << endl;
  cout << "==================" << endl;

  // Toggle back to noboolalpha
  cout << noboolalpha;
  cout << "noboolalpha (10 == 10): " << (10 == 10) << endl;
  cout << "noboolalpha (10 == 20): " << (20 == 10) << endl;
  cout << "==================" << endl;

  // Using setf method
  cout.setf(ios::boolalpha);
  cout << "boolalpha -(10 == 10): " << (10 == 10) << endl;
  cout << "boolalpha -(10 == 20): " << (20 == 10) << endl;
  cout << "==================" << endl;

  // resets to default
  cout << resetiosflags(ios::boolalpha);
  cout << "Default (10 == 10): " << (10 == 10) << endl;
  cout << "Default (10 == 20): " << (10 == 20) << endl;

  cout << endl;
  return 0;
}