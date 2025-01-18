#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void print_vector(vector<string> v);

void pass_by_value1(int num)
{
  num = 1000;
}

void pass_by_value2(string s)
{
  s = "Changed";
}

void pass_by_value3(vector<string> v)
{
  v.clear();
}

void print_vector(vector<string> v)
{
  for (auto s : v)
  {
    cout << s << " ";
    cout << endl;
  }
}

int main()
{
  int num{10};
  int another_num{20};

  cout << "number before calling pass_by_value: " << num << endl;
  pass_by_value1(num);
  cout << "number after calling pass_by_value: " << num << endl;

  cout << "\n another number before calling pass_by_value: " << another_num << endl;
  pass_by_value1(another_num);
  cout << "\n another number after calling pass_by_value: " << another_num << endl;

  string name{"Minho"};
  cout << "name before calling pass_by_value2: " << name << endl;
  pass_by_value2(name);
  cout << "name after calling pass_by_value2: " << name << endl;

  vector<string> stooges{"minho", "sunha", "jianjun"};
  cout << "stooges before calling pass_by_value3: ";
  print_vector(stooges);
  pass_by_value3(stooges);
  cout << "stooges after calling pass_by_value3: ";
  print_vector(stooges);
  cout << endl;

  return 0;
}