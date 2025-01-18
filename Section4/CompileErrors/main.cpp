#include <iostream>

using namespace std;

// function for syntax error
void compile_error()
{
  cout << "Complie Error" << endl // missing semi colon
}

// function for semantic error
int semantic_error()
{
  int number;
  cout << "Enter an alphabet: " << endl;
  cin >> number;
  return number + "A"; // invalid conversion
}

int main()
{
  cout << "Hello, World" << endl;

  int result = semantic_error();
  cout << "entered: " << result << endl;
  compile_error();

  return 0;
}