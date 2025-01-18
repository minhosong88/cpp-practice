#include <iostream>
#include <vector>
#include <string>

using namespace std;

void double_data(int *int_ptr)
{
  *int_ptr *= 2;
}

void swab(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void display(const vector<string> *const v)
{
  for (auto str : *v)
    cout << str << " ";
  cout << endl;
}

void display(int *array, int sentinel)
{

  while (*array != sentinel)
    cout << *array++ << " "; // moves the pointer after the printing
  // pointer is updated in the body, cannot use const here.
  cout << endl;
}

int main()
{
  // Example 1 - Double
  // int value{10};
  // int *int_ptr{nullptr};

  // cout << "Value: " << value << endl;
  // double_data(&value);
  // cout << "Now: " << value << endl;

  // cout << "\n------------------------" << endl;
  // int_ptr = &value;
  // double_data(int_ptr);
  // cout << "Value: " << value << endl;

  // Example 2 -Swab
  // int x{100}, y{200};
  // cout << "\nx: " << x << endl;
  // cout << "y: " << y << endl;

  // swab(&x, &y);

  // cout << "\nx: " << x << endl;
  // cout << "y: " << y << endl;

  // Example - display & vector
  cout << "---------------------" << endl;
  vector<string> stooges{"minho", "sunha", "jianjun"};
  display(&stooges);

  cout << "\n-------------------" << endl;
  int scores[]{100, 98, 95, 99, 29, -1};
  display(scores, -1); // array is already working as a pointer so no need for &

  cout << endl;
  return 0;
}