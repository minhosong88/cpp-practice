#include <iostream>

using namespace std;

int main()
{

  int scores[]{100, 50, 20, 44, 30};
  int *score_ptr{scores}; // since array name itself is the address, so no need for &

  while (*score_ptr != 30)
  {
    cout << *score_ptr << endl; // read the value of the location
    score_ptr++;                // move to the location of the next element
  }

  cout << "\n------------" << endl;
  score_ptr = scores;
  while (*score_ptr != 30)
    cout << *score_ptr++ << endl;

  cout << "\nCompare pointers -----------" << endl;
  string s1{"Minho"};
  string s2{"Minho"};
  string s3{"Sunha"};

  string *p1{&s1};
  string *p2{&s2};
  string *p3{&s1};

  cout << boolalpha;
  cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl; // comparing pointers
  cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl; // true

  cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl; // comparing the values
  cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

  p3 = &s3;                                                     // pointer to a different variable
  cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl; // false

  cout << "\nSubtract pointer-------------" << endl;
  char name[]{"Minho"};
  char *char_ptr1{nullptr};
  char *char_ptr2{nullptr};

  char_ptr1 = &name[0]; // M
  char_ptr2 = &name[3]; // h

  cout << "in the string " << name << ", " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1 << endl; // char_ptr2 - char_ptr1 shows the size of types(1 byte)

  cout << endl;
  return 0;
}