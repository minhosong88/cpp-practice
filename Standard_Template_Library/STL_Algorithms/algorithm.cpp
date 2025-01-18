#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cctype>
class Person
{
  std::string name;
  int age;

public:
  // Constructor
  Person() = default;
  Person(std::string name, int age)
      : name{name}, age{age} {}
  // Overloaded operators
  bool operator<(const Person &rhs) const
  {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

void find_test()
{
  std::cout << "\n=======================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  auto loc = std::find(std::begin(vec), std::end(vec), 6); // equivalent to vec.begin, vec.end
  if (loc != std::end(vec))                                // find returns locatino of end when found nothing
    std::cout << "Found the number: " << *loc << std::endl;
  else
    std::cout << "Couldn't find the number" << std::endl;

  std::list<Person> players{
      {"Minho", 36}, {"Sunha", 34}, {"Jianjun", 30}};
  auto loc1 = std::find(players.begin(), players.end(), Person{"Sunha", 34}); // Use overloaded == operator to compare values between target and element( name is the same and age is the same)
  if (loc1 != players.end())
    std::cout << "Found Sunha" << std::endl;
  else
    std::cout << "Sunha not found" << std::endl;
}
void count_test()
{
  std::cout << "\n=======================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};
  int num = std::count(vec.begin(), vec.end(), 1);
  // return the number of occurences of the target element
  std::cout << num << " Occurences Found" << std::endl;
}
void count_if_test()
{
  std::cout << "\n=======================" << std::endl;

  // count only if the element is even
  std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 100};
  int num = std::count_if(vec.begin(), vec.end(), [](int x)
                          { return x % 2 == 0; });
  std::cout << num << " even numbers found" << std::endl;

  num = std::count_if(vec.begin(), vec.end(), [](int x)
                      { return x % 2 != 0; });
  std::cout << num << " odd numbers found" << std::endl;
  num = std::count_if(vec.begin(), vec.end(), [](int x)
                      { return x >= 5; });
  std::cout << num << " numbers larger than or equal to 5 found" << std::endl;
}

void replace_test()
{
  std::cout << "\n=======================" << std::endl;

  std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};
  for (auto const &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::replace(vec.begin(), vec.end(), 1, 100);
  for (auto const &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
void all_of_test()
{
  std::cout << "\n=======================" << std::endl;
  std::vector<int> vec{1, 3, 5, 7, 9, 1, 3, 13, 19, 5, 3, 4, 6, 2, 4, 4, 1, 6};
  if (std::all_of(vec.begin(), vec.end(), [](int x)
                  { return x > 5; }))
    std::cout << "All the elements are > 5" << std::endl;
  else
    std::cout << "Not all the elements are > 5" << std::endl;

  if (std::all_of(vec.begin(), vec.end(), [](int x)
                  { return x < 20; }))
    std::cout << "All the elements are < 20" << std::endl;
  else
    std::cout << "Not all the elements are < 20" << std::endl;
  // There is any_of()
}
void string_transform_test()
{
  std::cout << "\n=======================" << std::endl;
  std::string str1{"This is a test"};
  std::cout << "Before treansform: " << str1 << std::endl;
  std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
  std::cout << "After treansform: " << str1 << std::endl;
}
int main()
{

  // find_test();
  // count_test();
  // count_if_test();
  // replace_test();
  // all_of_test();
  string_transform_test();
  return 0;
}