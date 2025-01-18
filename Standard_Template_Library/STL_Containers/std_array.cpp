#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void display(const std::array<int, 5> &arr)
{
  std::cout << "[ ";
  for (auto const &i : arr)
  {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}
void test1()
{
  std::cout << "\nTest1 ==========================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2;

  display(arr1);
  display(arr2);
  std::cout << "\n---" << std::endl;
  arr2 = {10, 20, 30, 40, 50};

  display(arr1);
  display(arr2);
  std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
  std::cout << "Size of arr2 is: " << arr2.size() << std::endl;
  std::cout << "\n---" << std::endl;
  arr1[0] = 100;    // No bounds checking
  arr1.at(2) = 200; // bounds checking
  display(arr1);
  std::cout << "Front of arr2 is:" << arr2.front() << std::endl;
  std::cout << "Back of arr2 is: " << arr2.back() << std::endl;
}
void test2()
{
  std::cout << "\nTest2 ==========================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2{10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);
  std::cout << "\n---" << std::endl;

  arr1.fill(0);
  display(arr1);
  display(arr2);

  std::cout << "\n--swap-" << std::endl;

  arr1.swap(arr2);
  display(arr1);
  display(arr2);
}
void test3()
{
  std::cout << "\nTest3 ==========================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  int *ptr = arr1.data();        // data method returns raw pointer to raw array
  std::cout << ptr << std::endl; // memory address
  *ptr = 10000;                  // a value is assgined to the dereferenced pointer
  display(arr1);
}
void test4()
{
  std::cout << "\nTest4 ==========================" << std::endl;
  std::cout << "\n--sort-" << std::endl;

  std::array<int, 5> arr1{2, 1, 5, 4, 3};
  display(arr1);
  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}
void test5()
{
  std::cout << "\nTest5 ==========================" << std::endl;
  std::cout << "\n--min/max-" << std::endl;
  std::array<int, 5> arr1{2, 1, 5, 4, 3};
  // Minimum
  std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
  // Maximum
  auto max_num = std::max_element(arr1.begin(), arr1.end());              // returns the iterator(address) of the element
  std::cout << "Min: " << *min_num << ", Max: " << *max_num << std::endl; // for the value, dereference it
}
void test6()
{
  std::cout << "\nTest6 ==========================" << std::endl;
  std::cout << "\n--adjacent find-" << std::endl;

  std::array<int, 5> arr1{3, 2, 2, 4, 3};
  auto adjacent = std::adjacent_find(arr1.begin(), arr1.end()); // return the iterator(address) of found element
  if (adjacent != arr1.end())
    std::cout << "Adjavent element found with value: " << *adjacent << std::endl;
  else
    std::cout << "No adjacent element found " << std::endl;
}
void test7()
{
  std::cout << "\nTest7 ==========================" << std::endl;
  std::cout << "\n--accumulate-" << std::endl;

  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  int sum = std::accumulate(arr1.begin(), arr1.end(), 0); //(begin, end, start_value)
  // type of start_value has to match the type of variable
  std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}
void test8()
{
  std::cout << "\nTest8 ==========================" << std::endl;
  std::cout << "\n--count-" << std::endl;
  std::array<int, 11> arr1{1, 2, 3, 1, 2, 3, 1, 2, 3, 3, 3};

  int count = std::count(arr1.begin(), arr1.end(), 3);
  std::cout << "Found 3: " << count << " times" << std::endl;
}
void test9()
{
  std::cout << "\nTest8 ==========================" << std::endl;
  std::cout << "\n--count if-" << std::endl;
  std::array<int, 10> arr1{1, 2, 3, 4, 50, 60, 70, 80, 100, 200};
  int count = std::count_if(arr1.begin(), arr1.end(), [](int x)
                            { return (x >= 50 && x < 200); });
  std::cout << "Found " << count << " matches" << std::endl;
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  return 0;
}