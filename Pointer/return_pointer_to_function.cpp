#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0)
{
  int *new_storage{nullptr};   // initialize
  new_storage = new int[size]; // allocate dynamic storage
  for (size_t i{0}; i < size; ++i)
  {
    *(new_storage + i) = init_value; // iteration by address and update the value at the location // pointer offset notation
  }
  return new_storage; // return storage on the heap
}

void display(const int *const array, size_t size)
{
  for (size_t i{0}; i < size; ++i)
    cout << array[i] << " "; // point subscript notation
  cout << endl;
}

int main()
{
  int *my_array{nullptr}; // point
  size_t size;
  int init_value{};

  cout << "\nHow manu integers would you like to allocate?: ";
  cin >> size;
  cout << "What value would you like them initialized to?: ";
  cin >> init_value;

  my_array = create_array(size, init_value); // return storage in heap // this value has to be copied to a variable to keep track of the information
  cout << "\n--------------------------" << endl;

  display(my_array, size);

  delete[] my_array;

  cout << endl;
  return 0;
}