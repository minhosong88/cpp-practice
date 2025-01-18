#include <iostream>

using namespace std;

int main()
{
  bool equal_result{false};
  bool not_equal_result{false};

  int num1{}, num2{};
  cout << boolalpha; // display true/false instead of 1/0

  // cout << "Enter two integers separated by a space: " << endl;
  // cin >> num1 >> num2;
  // equal_result = (num1 == num2);
  // not_equal_result = (num1 != num2);
  // cout << "Comparison result(equal): " << equal_result << endl;
  // cout << "Comparison result(not_equal): " << not_equal_result << endl;

  // char char1{}, char2{};
  // cout << "Enter two characters separated by a space: " << endl;
  // cin >> char1 >> char2;
  // equal_result = (char1 == char2);
  // not_equal_result = (char1 != char2);
  // cout << "Comparison result(equal): " << equal_result << endl;
  // cout << "Comparison result(not_equal): " << not_equal_result << endl;

  double double1{}, double2{};
  // cout << "Enter two doubles separated by a space: " << endl;
  // cin >> double1 >> double2;
  // equal_result = (double1 == double2);
  // not_equal_result = (double1 != double2);
  // cout << "Comparison result(equal): " << equal_result << endl;
  // cout << "Comparison result(not_equal): " << not_equal_result << endl;

  cout << "Enter an integer and a double separated by a space: " << endl;
  cin >> num1 >> double1;
  equal_result = (num1 == double1);
  not_equal_result = (num1 != double1);
  cout << "Comparison result(equal): " << equal_result << endl;
  cout << "Comparison result(not_equal): " << not_equal_result << endl;

  // Example: 10 10.0 ==> 10 will be promoted to double 10.0 so the equality becomes true.
  // Example: 10 9.9999999999999 ==> 10 will be converted to double 10.0, 9.99999999999999 will be 10.0 since the program rounds up the number. So internally 9.99999999999 is equal to 10.0

  return 0;
}