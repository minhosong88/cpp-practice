#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int *int_ptr{nullptr};
  int_ptr = new int;       // allocating heap storage/address location for int
  cout << int_ptr << endl; // currently no name and exceptionally accessible by the pointer.
  delete int_ptr;          // deallocation

  size_t size{0};

  double *temp_ptr{nullptr};
  cout << "How many temps?:";
  cin >> size;

  temp_ptr = new double[size];

  cout << temp_ptr << endl;

  delete[] temp_ptr; // delete the array
  // if you don't delete and free up the allocation, it leads to memory leak.
  // since the only way to get to that memory location was through the pointer

  cout << endl;
  return 0;
}