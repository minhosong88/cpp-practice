#include <iostream>
#include <string>

using namespace std;

int main()
{
  cout << "Enter a std::string: ";
  string input;
  getline(cin, input);
  for (size_t i{1}; i <= input.length(); ++i)
  {
    string forward;
    for (size_t j{0}; j < i; ++j)
    {
      forward += input.at(j);
    }

    for (int j{i - 2}; j >= 0; --j)
    {
      forward += input.at(j);
    }

    cout << forward << endl;
  }

  cout << endl;
  return 0;
}