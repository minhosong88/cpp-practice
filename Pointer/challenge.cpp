#include <iostream>
/*
function name: apply_all with 2 arrays of integers, and sizes
DO: dynamically allocate a new array of integers whose size is the product of the sizes of the 2 arrays

- nested-loop through the second array and multiple element across each element of array 1
- store the product in the new array
- return a pointer to the newly located array
- print function that expects a pointer to an array and its size and display the elements

int array1[] {1, 2, 3, 4, 5};
int array2[] {10,20,30,40,50};
print(array1, 5);
print(array2, 5);

int *results = apply_all(array1, 5, array2, 5);
print(results, 15);


*/
using namespace std;

void print(const int *const arr, size_t size);
int *apply_all(int arr1[], size_t size1, int arr2[], size_t size2);

int main()
{
  const size_t size1{5};
  const size_t size2{5};

  int array1[]{1, 2, 3, 4, 5};
  int array2[]{10, 20, 30, 40, 50};
  print(array1, size1);
  print(array2, size2);

  int *results = apply_all(array1, 5, array2, 5);
  print(results, size1 * size2);
  delete[] results;
  cout << endl;
  return 0;
}

int *apply_all(int arr1[], size_t size1, int arr2[], size_t size2)
{
  int *new_size{nullptr};
  new_size = new int[size1 * size2];
  int index{0};
  for (size_t i{0}; i < size2; ++i)
  {
    for (size_t j{0}; j < size1; ++j)
    {
      new_size[index++] = arr1[j] * arr2[i];
    }
  }
  return new_size;
}

void print(const int *const arr, size_t size)
{
  for (size_t i{0}; i < size; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}