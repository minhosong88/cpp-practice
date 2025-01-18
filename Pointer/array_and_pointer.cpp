#include <iostream>

using namespace std;

int main()
{
  int scores[]{100, 90, 86};
  cout << "Value of scores: " << scores << endl; // address of the first element

  int *score_ptr{scores};                              // array name is the address of the first element
  cout << "Value of score_ptr: " << score_ptr << endl; // the same as above

  cout << "\nArray subscription notation ---------------" << endl;
  cout << scores[0] << endl; // value of the first element
  cout << scores[1] << endl; // value of the second element
  cout << scores[2] << endl; // value of the third element

  cout << "\nPointer subscription notation ---------------" << endl;
  cout << score_ptr[0] << endl; // value of the first element
  cout << score_ptr[1] << endl; // value of the second element
  cout << score_ptr[2] << endl; // value of the third element

  cout << "\nPointer offset notation ---------------" << endl;
  cout << *score_ptr << endl;       // value of the first element
  cout << *(score_ptr + 1) << endl; // value of the second element
  cout << *(score_ptr + 2) << endl; // value of the third element

  cout << "\nArray offset notation ---------------" << endl;
  cout << *scores << endl;       // value of the first element
  cout << *(scores + 1) << endl; // value of the second element
  cout << *(scores + 2) << endl; // value of the third element

  // The results are the same for all 4 cases because each change happens in the memory location level

  cout << endl;
  return 0;
}