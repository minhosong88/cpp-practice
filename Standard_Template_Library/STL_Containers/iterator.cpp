#include <iostream>
// containers
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
//
using namespace std;

void display(const std::vector<int> &vec)
{
  std::cout << "[ ";
  for (auto const &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << "]" << endl;
}

void test1()
{
  std::cout << "\n===========================" << std::endl;
  std::vector<int> nums1{1, 2, 3, 4, 5};
  auto it = nums1.begin();
  std::cout << *it << std::endl; // Since 'it' is an address, you need to dereference it for values
  it++;
  std::cout << *it << std::endl;
  it += 2;
  std::cout << *it << std::endl;
  it -= 2;
  std::cout << *it << std::endl;
  it = nums1.end() - 1; // the end is right after the last element.
  std::cout << *it << std::endl;
}

void test2()
{ // disply all vector elements
  std::cout << "\n===========================" << std::endl;
  std::vector<int> nums1{1, 2, 3, 4, 5};
  auto it = nums1.begin();
  while (it != nums1.end())
  {
    std::cout << *it << std::endl;
    it++;
  }

  // change all vector elements to 0
  it = nums1.begin();
  while (it != nums1.end())
  {
    *it = 0; //
    it++;
  }
  display(nums1);
}
void test3()
{ // using a const iterator
  std::cout << "\n===========================" << std::endl;
  std::vector<int> nums1{1, 2, 3, 4, 5};

  std::vector<int>::const_iterator it1 = nums1.begin();
  // or auto it1 = nums1.cbegin(); << cbegin is used to represent constant iterator
  while (it1 != nums1.end())
  {
    std::cout << *it1 << std::endl;
    it1++;
  }
  // Complier error when we try to change element
  it1 = nums1.begin();
  while (it1 != nums1.end())
  {
    //*it1 = 0;
    it1++;
  }
}

void test4()
{
  // More iterators
  // Reverse Iterator
  std::vector<int> vec{1, 2, 3, 4, 5};
  auto it1 = vec.rbegin(); // Notice it's rbegin
  while (it1 != vec.rend())
  {
    std::cout << *it1 << std::endl;
    it1++;
  }
  // Const Reverse Iterator
  std::list<std::string> name{"Minho", "Sunha", "Jianjun"};
  auto it2 = name.crbegin(); // Notice it's crbegin
  std::cout << *it2 << std::endl;
  it2++; // Move point to the next element
  std::cout << *it2 << std::endl;

  // Map Iterator
  std::map<std::string, std::string> favorites{
      {"Minho", "Love"}, {"Sunha", "Eggs"}, {"Jianjun", "Cheap"}};
  auto it3 = favorites.begin();
  while (it3 != favorites.end())
  {
    std::cout << it3->first << " : " << it3->second << std::endl;
    it3++;
  }
}
void test5()
{
  // iterator over a subset of a container
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto start = vec.begin() + 2;
  auto finish = vec.end() - 3;

  while (start != finish)
  {
    std::cout << *start << std::endl;
    start++;
  }
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();
  test5();

  return 0;
}