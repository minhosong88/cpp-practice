#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int num{1000};
  cout << "Value: " << num << endl;
  cout << "Size: " << sizeof num << endl;
  cout << "Address: " << &num << endl;

  int *ptr;
  cout << "\nValue" << ptr << endl; // garbage since no initialization
  cout << "Address: " << &ptr << endl;
  cout << "Size: " << sizeof ptr << endl;

  ptr = nullptr;
  cout << "\nValue: " << ptr << endl;

  int *p1{nullptr};
  double *p2{nullptr};
  unsigned long long *p3{nullptr};
  vector<string> *p4{nullptr};
  string *p5{nullptr};

  cout << "\nSize of p1: " << sizeof p1 << endl;
  cout << "Size of p2: " << sizeof p2 << endl;
  cout << "Size of p3: " << sizeof p3 << endl;
  cout << "Size of p4: " << sizeof p4 << endl;
  cout << "Size of p5: " << sizeof p5 << endl;

  int score{10};
  double high_temp{100.7};

  int *score_ptr{nullptr};

  score_ptr = &score;

  cout << "\nValue: " << score << endl;
  cout << "Address: " << &score << endl;
  cout << "Value of pointer: " << score_ptr << endl;

  // score_ptr = &high_temp; // score_ptr is for int but assign doublr
  // compile error

  cout << endl;
  return 0;
}