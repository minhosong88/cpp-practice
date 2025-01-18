#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() = default;
  Person(std::string name, int age)
      : name{name}, age{age} {}
  // When using your own classes with stl, ALWAYS Overload <, == operator
  bool operator<(const Person &rhs) const
  {
    return age < rhs.age;
  }
  bool operator==(const Person &rhs) const
  {
    return (name == rhs.name && age == rhs.age);
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << p.name << ":" << p.age;
  return os;
}

// Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec)
{
  std::cout << "[ ";
  std::for_each(vec.begin(), vec.end(), [](int x)
                { std::cout << x << " "; });

  std::cout << "]" << std::endl;
}
// Template function to display vector
template <typename T>
void display(const std::vector<T> &vec)
{
  std::cout << "[ ";
  for (const auto &elem : vec)
    std::cout << elem << " ";
  std::cout << "]" << std::endl;
}
void test1()
{
  std::cout << "\nTest1 ==========================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);

  vec = {2, 3, 4, 5};
  display2(vec);

  std::vector<int> vec1(10, 100);
  display(vec1);
}
void test2()
{
  std::cout << "\nTest2 ==========================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  std::cout << "\nvec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  vec.push_back(6);
  // once beyond capacity, the memory spaces doubles
  display(vec);
  std::cout << "\nvec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  std::cout << "--shrink to fit-" << std::endl;
  vec.shrink_to_fit();
  // shrink the expanded space to the exact size of the vectors
  display(vec);
  std::cout << "\nvec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  std::cout << "--reserve-" << std::endl;
  // reserving memory space for the vector
  vec.reserve(10);
  display(vec);
  std::cout << "\nvec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;
}
void test3()
{
  std::cout << "\nTest3 ==========================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  std::cout << "--Direct access to element-" << std::endl;

  vec[0] = 100;
  vec.at(2) = 300;
  display(vec);
}
void test4()
{
  std::cout << "\nTest4 ==========================" << std::endl;
  std::vector<Person> stooges;
  Person p1{"Minho", 18};
  display(stooges);

  stooges.push_back(p1);
  display(stooges);

  stooges.push_back(Person{"Sunha", 19});
  display(stooges);
  // Emplace back is useful
  stooges.emplace_back("Jianjun", 28);
  display(stooges);
}
void test5()
{
  std::cout << "\nTest5 ==========================" << std::endl;
  std::vector<Person> stooges{
      {"Minho", 10}, {"Sunha", 15}, {"Jianjun", 61}};
  std::cout << "--front/back/pop -" << std::endl;

  display(stooges);
  std::cout << "\nFront: " << stooges.front() << std::endl;
  std::cout << "Back: " << stooges.back() << std::endl;
  stooges.pop_back();
  display(stooges);
}
void test6()
{
  std::cout << "\nTest6 ==========================" << std::endl;
  std::cout << "--Remove Elements -" << std::endl;

  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);

  vec.clear(); // remove all elements
  display(vec);

  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(vec);
  vec.erase(vec.begin(), vec.begin() + 2);
  display(vec);
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // erase all even numbers
  auto it = vec.begin();
  while (it != vec.end())
  {
    if (*it % 2 == 0)
      vec.erase(it);

    else
      it++; // increment when not erased since once erased, the next item comes in the place of removal
  }
  display(vec);
}
void test7()
{
  std::cout << "\nTest7 ==========================" << std::endl;
  std::cout << "--Swap -" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};
  display(vec1);
  display(vec2);

  std::cout << std::endl;

  vec2.swap(vec1);
  display(vec1);
  display(vec2);
}
void test8()
{
  std::cout << "\nTest8 ==========================" << std::endl;
  std::cout << "--Sort -" << std::endl;

  std::vector<int> vec1{1, 21, 3, 40, 15};
  display(vec1);
  std::sort(vec1.begin(), vec1.end());
  display(vec1);
  std::sort(vec1.rbegin(), vec1.rend());
  display(vec1);
}
void test9()
{ // back_inserter constructs a back-insert iterator that inserts new elements at the end of the container
  std::cout << "\nTest9 ==========================" << std::endl;
  std::cout << "--Back Inserter -" << std::endl;

  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  // copy all elements of vec1 and insert the values to the back of vec2
  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec2 = {10, 20};
  display(vec1);
  display(vec2);
  std::cout << std::endl;
  // Copy only even numbers and insert at the back of vec2
  // copy and copy_if with back_inserter are really good to know to impress interviewers
  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x)
               { return x % 2 == 0; });
  display(vec1);
  display(vec2);
}
void test10()
{
  std::cout << "\nTest10 ==========================" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};
  std::vector<int> vec3;
  // transform(first, last, res, op);                 // For Unary Operation
  // transform(first, last, first1, res, op);      // For Binary Operation
  // res: Iterator to the beginning of the output range
  // first1: Iterator to the first element of second input range.
  // op: Operation to be performed
  std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), [](int x, int y)
                 { return x * y; });

  display(vec3);
}
void test11()
{
  std::cout << "\nTest11 ==========================" << std::endl;

  std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2{100, 200, 300, 400, 500};
  display(vec1);
  display(vec2);
  // v.insert(pos, val);              // Insert single element
  // v.insert(pos, n, val);         // Insert multiple copies of an element
  // v.insert(pos, first, last);   // Insert range of elements
  auto it = std::find(vec1.begin(), vec1.end(), 5);
  // find returns iterator before the target element
  if (it != vec1.end())
  {
    std::cout << "inserting..." << std::endl;
    vec1.insert(it, vec2.begin(), vec2.end());
    // inserting the entire vec2 before 5
  }
  else
  {
    std::cout << "Sorry, 5 not found" << std::endl;
  }
  display(vec1);
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
  test10();
  test11();
  return 0;
}