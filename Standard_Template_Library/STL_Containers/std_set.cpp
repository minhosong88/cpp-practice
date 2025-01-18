#include <iostream>
#include <set>

class Person
{

  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() : name{"Unknown"}, age{0} {}
  Person(std::string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) const
  {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << p.name << ":" << p.age;
  return os;
}

template <typename T>
void display(const std::set<T> &s)
{
  std::cout << "[ ";
  for (auto &elem : s)
    std::cout << elem << " ";
  std::cout << "]" << std::endl;
}

void test1()
{
  // Sets
  std::cout << "\nTest 1==========================" << std::endl;
  std::set<int> s1{1, 3, 4, 2, 5};

  display(s1);
  s1 = {1, 2, 3, 1, 1, 2, 3, 4, 5, 3, 2, 4};
  display(s1);

  s1.insert(0);
  s1.insert(10);
  display(s1);

  if (s1.count(10))
    std::cout << "10 is in the set" << std::endl;
  else
    std::cout << "10 is NOT in the set" << std::endl;

  auto it = s1.find(5); // set.find() method knows how the set is implemented behined. No need to pass the range.
  if (it != s1.end())
    std::cout << "Found: " << *it << std::endl;
  s1.clear();
  display(s1);
}
void test2()
{
  std::cout << "\nTest 2==========================" << std::endl;
  std::set<Person> stooges{
      {"Minho", 20},
      {"Sunha", 30},
      {"Jianjun", 40}};
  display(stooges);
  stooges.emplace("Kaley", 50);
  display(stooges);

  stooges.emplace("SMU", 50); // Not allowed since 50 exists already
  display(stooges);

  auto it = stooges.find(Person{"Sunha", 30});
  if (it != stooges.end())
    stooges.erase(it);
  display(stooges);

  it = stooges.find(Person{"XXXX", 50}); // this uses operator < to find it.
  if (it != stooges.end())
    stooges.erase(it); // Remove SMU
  display(stooges);
}
void test3()
{
  std::cout << "\nTest 3==========================" << std::endl;
  std::set<std::string> s{"A", "B", "C"};
  display(s);

  auto result = s.insert("D"); // return std::pair(first, second) first:iterator of the inserted element, second: boolean whether execution succeeded ot failed.
  display(s);

  std::cout << std::boolalpha;
  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl;

  std::cout << std::endl;

  result = s.insert("A");
  display(s);
  std::cout << std::boolalpha;
  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl;
}

int main()
{
  test1();
  test2();
  test3();

  return 0;
}