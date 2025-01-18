#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
  std::string name;
  int age;

public:
  // Constructor
  Person(std::string name, int age) : name{name}, age{age} {}
  // Copy Constructor (Shallow Copy)
  Person(const Person &p) : name{p.name}, age{p.age} {}
  // Destructor
  ~Person() = default;

  // Getter and Setter
  std::string get_name() const
  {
    return name;
  }
  void set_name(std::string name) { this->name = name; }

  int get_age() const
  {
    return age;
  }
  void set_age(int age) { this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
  os << "[Person: " << rhs.name << " : " << rhs.age << "]";
  return os;
}

void test1()
{
  std::cout << "\n===Test 1==============" << std::endl;
  // Lambda Operation
  []()
  { std::cout << "Hi" << std::endl; }();
  [](int x)
  { std::cout << x << std::endl; }(100);
  [](int x, int y)
  { std::cout << x + y << std::endl; }(100, 200);
}
// Using values and references as lambda parameters
void test2()
{
  std::cout << "\n===Test 2==============" << std::endl;
  auto l1 = []()
  { std::cout << "HI" << std::endl; };
  l1();

  int num1{100};
  int num2{100};
  auto l2 = [](int x, int y)
  {
    std::cout << x + y << std::endl;
    // since the variables are passed by value, no effect outside this scope
    x = 1000;
    y = 1000;
  };
  l2(10, 20);
  // passing variables by value (copied value)
  l2(num1, num2);

  // passing by reference
  auto l3 = [](int &x, int &y)
  { std::cout << "x :" << x <<  " y: " << y << std::endl;
  // x and y are passed by reference: 
  // modifying the value at the reference(not the copy)
  x = 1000;
  y = 2000; };

  l3(num1, num2);
  // num1, num2 are passed by reference: actual value are modified.
  std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}
// Using value and reference objects as lambda paramters
void test3()
{
  std::cout << "\n===Test 3==============" << std::endl;
  // Passing object instead of primitive type
  Person stooge{"Minho", 36};
  std::cout << stooge << std::endl; // overloaded operator works

  // In order to pass an object by value: Need Copy Constructor
  auto l1 = [](Person p)
  {
    std::cout << p << std::endl;
  };
  l1(stooge);

  auto l2 = [](const Person &p)
  {
    std::cout << p << std::endl;
  };
  l2(stooge);
  // Modify the object
  auto l3 = [](Person &p)
  {
    p.set_name("Sunha");
    p.set_age(34);
    std::cout << p << std::endl;
  };
  l3(stooge);
  std::cout << stooge << std ::endl;
}
// using std::fuunction as a parameter
//  or auto
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)
// void filter_vector(const std::vector<int> &vec, auto func) C++20
// the function expects integer and return boolean(Predicate Lambda)
{
  std::cout << "[ ";
  for (int i : vec)
  {
    if (func(i))
      std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}
// Passing a lambda to a function
void test4()
{
  std::cout << "\n===Test 4==============" << std::endl;
  std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  filter_vector(nums, [](int x)
                { return x > 50; }); // Notice that the lambda expression expects an integer and return boolean
  filter_vector(nums, [](int x)
                { return x <= 30; });
  filter_vector(nums, [](int x)
                { return x >= 30 && x <= 60; });
}

auto make_lambda()
{
  // Return a lambda
  return []()
  { std::cout << "This lambda was made using the make_lambda function" << std::endl; };
}
// Returning a lambda from a function
void test5()
{
  std::cout << "\n===Test 5==============" << std::endl;
  auto l = make_lambda();
  l();
}

// Using auto in the lambda parameter list
void test6()
{
  std::cout << "\n===Test 6==============" << std::endl;
  // Lambda that prints the passed values
  auto l = [](auto x, auto y)
  {
    std::cout << "x: " << x << " y: " << y << std::endl;
  };

  l(10, 20);
  l(100.3, 200);
  l(12.3, 13.54);
  // Overloaded operator<< works here
  l(Person{"Minho", 36}, Person{"Sunha", 34});
}
// Simple Lambda Examples with std::sort and std::for_each
void test7()
{
  std::cout << "\n===Test 7==============" << std::endl;
  std::vector<Person> stooges{
      {"Minho", 36},
      {"Sunha", 34},
      {"Jianjun", 30}};
  // Sort by name (operation is passed as a lambda)
  std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2)
            { return p1.get_name() < p2.get_name(); });
  // Print the vector
  std::for_each(begin(stooges), end(stooges), [](const Person &p)
                { std::cout << p << std::endl; });
  // Sort by age
  std::cout << std::endl;
  std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2)
            { return p1.get_age() < p2.get_age(); });
  // Print the vector
  std::for_each(begin(stooges), end(stooges), [](const Person &p)
                { std::cout << p << std::endl; });
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
  return 0;
}