#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// for_each - Non-modifying sequence operation

void test1()
{
  std::cout << "\n -- Test1 ---------------" << std::endl;
  std::vector<int> nums{10, 20, 30, 40, 50};
  std::for_each(nums.begin(), nums.end(), [](int num)
                { std::cout << num << " "; });
}
// is_permutation - Non-modifying sequence operation
// test whether two triangles are equivalent

void test2()
{
  std::cout << "\n -- Test2 ---------------" << std::endl;
  struct Point
  {
    int x;
    int y;
  };

  Point pt1{1, 2};
  Point pt2{4, 3};
  Point pt3{3, 5};
  Point pt4{3, 1};

  std::vector<Point> triangle1{pt1, pt2, pt3};
  std::vector<Point> triangle2{pt2, pt3, pt1};
  std::vector<Point> triangle3{pt1, pt2, pt4};
  // Test Triangle 1 and Triangle 2
  if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs)
                          { return (rhs.x == lhs.x && rhs.y == lhs.y); }))
    std::cout << "Triangle 1 and Triangle 2 are equivalent!" << std::endl;
  else
    std::cout << "Triangle 1 and Triangle 2 are not equivalent!" << std::endl;

  // Test Triangle 1 and Triangle 3
  if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs)
                          { return (rhs.x == lhs.x && rhs.y == lhs.y); }))
    std::cout << "Triangle 1 and Triangle 3 are equivalent!" << std::endl;
  else
    std::cout << "Triangle 1 and Triangle 3 are not equivalent!" << std::endl;
}
// Transform - Modifying sequence operation

void test3()
{
  std::cout << "\n -- Test3 ---------------" << std::endl;
  std::vector<int> test_scores{99, 88, 75, 68, 65};
  int bonus_points{5};

  std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points](int score)
                 { return score += bonus_points; });
  for (int score : test_scores)
    std::cout << score << " ";
}
// Remove_if - Modifying sequence operation
// erase-remove idiom is a common use of lambda.
// remove_if returns a new end iterator. erase removes the garbage space between the new end iterator and the original end iterator.
void test4()
{
  std::cout << "\n -- Test4 ---------------" << std::endl;
  std::vector<int> nums{1, 2, 3, 4, 5};
  // remove_if makes the non-removed elements override the removed elements by shifting them to the front.
  nums.erase(std::remove_if(nums.begin(), nums.end(), [](int num)
                            { return num % 2 == 0; }),
             nums.end());
  // Display updated nums
  for (int num : nums)
    std::cout << num << " ";
}
class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);

private:
  std::string name;
  int age;

public:
  Person(std::string name, int age) : name{name}, age{age} {}
  Person(const Person &p) : name{p.name}, age{p.age} {}
  ~Person() = default;
  std::string get_name() const { return name; }
  void set_name(std::string name) { this->name = name; }
  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }
};
std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << "[ Person: " << p.name << ":" << p.age << " ]";
  return os;
}
// sort- sort elements in the sequence according to the predicate lambda
void test5()
{
  std::cout << "\n -- Test5 ---------------" << std::endl;
  Person person1("Minho", 36);
  Person person2("Sunha", 34);
  Person person3("Jianjun", 30);

  std::vector<Person> people{person1, person2, person3};

  // sort people by name in ascending order
  std::sort(people.begin(), people.end(), [](Person lhs, Person rhs)
            { return lhs.get_name() < rhs.get_name(); });
  // Display sorted vector
  for (Person person : people)
    std::cout << person << std::endl;

  std::cout << std::endl;
  // sort people by age in ascending order

  std::sort(people.begin(), people.end(), [](Person lhs, Person rhs)
            { return lhs.get_age() < rhs.get_age(); });
  // Display sorted vector
  for (Person person : people)
    std::cout << person << std::endl;
}
bool in_between(const std::vector<int> &nums, int start_value, int end_value)
{
  bool result{false};
  result = std::all_of(nums.begin(), nums.end(), [start_value, end_value](int value)
                       { return value >= start_value && value <= end_value; });
  return result;
}
// all_of : Non-Modifying sequence operation
// return true if all elements in the squence satisfy the condition
void test6()
{
  std::cout << "\n -- Test6 ---------------" << std::endl;
  std::cout << std::boolalpha;
  std::vector<int> nums(10);
  //  fills a range with sequential values starting from a specified value.
  std::iota(nums.begin(), nums.end(), 50);
  for (int num : nums)
    std::cout << num << " ";
  std::cout << std::endl;

  std::cout << in_between(nums, 50, 60) << std::endl;
  std::cout << in_between(nums, 1, 10) << std::endl;
  std::cout << in_between(nums, 5, 7) << std::endl;
}

class Password_Validator1
{
private:
  char restricted_symbol{'$'};

public:
  bool is_valid(std::string password)
  {
    return std::all_of(password.begin(), password.end(), [this](char character)
                       { return character != restricted_symbol; });
  }
};
class Password_Validator2
{
private:
  std::vector<char> restricted_symbols{'!', '$', '+'};

public:
  bool is_valid(std::string password)
  {
    return std::all_of(password.begin(), password.end(), [this](char character)
                       { return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), [character](char symbol)
                                             { return character == symbol; }); });
  }
};
void test7()
{
  std::cout << "\n -- Test7 ---------------" << std::endl;
  // Password Validator1
  std::string password{"holywood1$"};
  Password_Validator1 pv1; // this object holds the info of restricted symbol

  // Test
  if (pv1.is_valid(password))
    std::cout << "The Password " << password << " is Valid" << std::endl;
  else
    std::cout << "The Password " << password << " is not Valid" << std::endl;
  // reassign a new password
  password = "holywood1";
  // Test
  if (pv1.is_valid(password))
    std::cout
        << "The Password " << password << " is Valid" << std::endl;
  else
    std::cout << "The Password " << password << " is not Valid" << std::endl;

  // Password Validator2
  password = "C++Rocks!";
  Password_Validator2 pv2;

  if (pv2.is_valid(password))
    std::cout << "The Password " << password << " is Valid" << std::endl;
  else
    std::cout << "The Password " << password << " is not Valid" << std::endl;

  password = "CPlusPlusRocks!";
  if (pv2.is_valid(password))
    std::cout << "The Password " << password << " is Valid" << std::endl;
  else
    std::cout << "The Password " << password << " is not Valid" << std::endl;

  password = "CPlusPlusRocks";
  if (pv2.is_valid(password))
    std::cout << "The Password " << password << " is Valid" << std::endl;
  else
    std::cout << "The Password " << password << " is not Valid" << std::endl;
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