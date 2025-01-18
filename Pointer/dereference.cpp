#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

  int score{100};
  int *score_ptr{&score};

  cout << *score_ptr << endl;

  *score_ptr = 200;
  cout << "dereferenced_ponter:" << *score_ptr << endl;
  cout << "what pointer points to: " << score << endl;

  cout << "\n---------------------" << endl;
  double high_temp{100.7};
  double low_temp{37.4};
  double *temp_ptr{&high_temp};

  cout << "Current pointer: " << *temp_ptr << endl;
  cout << "Pointer value: " << temp_ptr << endl;
  temp_ptr = &low_temp;
  cout << "Now pointer is: " << *temp_ptr << endl;
  cout << "Pointer value: " << temp_ptr << endl;

  cout << "\n---------------------" << endl;
  string name{"Minho"};
  string *string_ptr{&name};

  cout << "Current pointer: " << *string_ptr << endl;
  cout << "Pointer value: " << string_ptr << endl;
  name = "Sunha";
  cout << "Now pointer is: " << *string_ptr << endl;
  cout << "Pointer value: " << string_ptr << endl; // pointer address does not change since the changed name is at the same location with different value
  cout << "\n---------------------" << endl;
  vector<string> stooges{"minho", "sunha", "jianjun"};
  vector<string> *vector_ptr{nullptr};

  vector_ptr = &stooges;

  cout << "First stooge: " << (*vector_ptr).at(0) << endl;
  cout << "Stooges: ";
  for (auto stooge : *vector_ptr)
    cout << stooge << ", ";
  cout << endl;

  cout << endl;
  return 0;
}