#include <iostream>
using namespace std;
void func_a();
void func_b();
void func_c();

void func_a()
{
  cout << "starting function_a" << endl;
  func_b();
  cout << "Ending function_a" << endl;
}
// void func_b()
// {
//   cout << "starting function_b" << endl;
//   func_c();
//   cout << "Ending function_b" << endl;
// }
void func_b()
{
  cout << "starting function_b" << endl;
  try
  {
    func_c();
  }
  catch (int &e)
  {
    cout << "Caught error in func_b" << endl;
  } // this allows func_b continue execute the printing.

  cout << "Ending function_b" << endl;
}
void func_c()
{
  cout << "starting function_c" << endl;
  throw 100;
  cout << "Ending function_c" << endl;
}

int main()
{
  cout << "starting main" << endl;
  try
  {
    func_a();
  }
  catch (int &e)
  {
    cout << "Caught error in main" << endl;
  }
  cout << "Finishing main" << endl;
  cout << endl;
  return 0;
}