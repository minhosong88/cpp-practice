#include <iostream>
#include <iomanip>

using namespace std;
void ruler()
{
  cout << "\n1234567890123456789012345678901234567890" << endl;
}
int main()
{

  int num1{1234};         // 4
  double num2{1234.5678}; // 7 (6 digit + .)
  string hello{"Hello"};  // 5
  cout << "------Default -----" << endl;
  ruler();
  cout << num1 << num2 << hello << endl; // 16

  cout << "------One per line -----" << endl;
  ruler();
  cout << num1 << endl;
  cout << num2 << endl;
  cout << hello << endl;

  cout << "------Set field width(10) -----------------------------------" << endl; // default right justified
  ruler();
  cout << setw(10) << num1 << num2 << hello << endl; // 22(10+7+5)

  cout << "------Set field width(10) for first 2---------------------------" << endl;
  ruler();

  cout << setw(10) << num1 << setw(10) << num2 << hello << endl; // 25(10+10+5)

  cout << "------Set field width(10) for all 3--------------------------" << endl;
  ruler();
  cout << setw(10) << num1 << setw(10) << num2 << setw(10) << hello << endl; // 30 (10+10+10)

  cout << "------Set field width(10) for all 3 with left justification--------------" << endl;
  ruler();
  cout << setw(10) << left << num1 << setw(10) << left << num2 << setw(10) << left << hello << endl;

  // Set Fill to a dash, this is persistent once set
  cout << "------Set field width(10) for all 3 with left justification for all setfill to dash----" << endl;
  ruler();
  cout << setfill('-');
  cout << setw(10) << left << num1 << setw(10) << left << num2 << setw(10) << left << hello << endl;

  cout << "------Set field width(10) for all 3 with left justification for all setfill to dash----" << endl;
  ruler();
  cout << setw(10) << left << setfill('*') << num1 << setw(10) << left << setfill('#') << num2 << setw(10) << left << setfill('-') << hello << endl;

  cout << endl;
  return 0;
}