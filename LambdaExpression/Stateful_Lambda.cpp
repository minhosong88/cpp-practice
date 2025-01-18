#include <iostream>
#include <vector>
#include <algorithm>

// Global variable cannot be captured
//  but can be accessed in the body
int global_X{1000};

// Capture by value
void test1()
{
  std::cout << "\n===Test1 ==================" << std::endl;
  int local_x{100};
  auto l = [local_x]()
  {
    std::cout << local_x << std::endl;
    std::cout << global_X << std::endl;
  };
  l();
}
// Capture by value-mutable
void test2()
{
  std::cout << "\n===Test2 ==================" << std::endl;
  int x{100};

  auto l = [x]() mutable
  {
    x += 100;
    std::cout << x << std::endl;
  };
  // copied value is used in the lambda expression
  l();
  // original value does not change
  std::cout << x << std::endl;
  // captured variable becomes a member varible in a closure class
  // keeps updated in lambda
  l();
  std::cout << x << std::endl;
}

// Capture by reference

void test3()
{
  std::cout << "\n===Test3 ==================" << std::endl;
  int x{100};
  auto l = [&x]() mutable
  {
    x += 100;
    std::cout << x << std::endl;
  };

  l();
  // Since x was captured by reference, the original value is modified with lambda
  std::cout << x << std::endl;
}
void test4()
{
  std::cout << "\n===Test4 ==================" << std::endl;
  int x{100};
  int y{200};
  int z{300}; // z is not caputred since not used => warning
  // `=` Capture everything by value by default
  auto l = [=]() mutable
  {
    x += 100;
    y += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
  };

  l();
  std::cout << std::endl;

  // Capture by value
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  // x and y are member variables now in a class that saves the changes in lambda
  std::cout << std::endl;

  l();
  std::cout << std::endl;
  // Capture by value
  std::cout << x << std::endl;
  std::cout << y << std::endl;
}
// Default capture by reference
void test5()
{
  std::cout << "\n===Test5 ==================" << std::endl;
  int x{100};
  int y{200};
  int z{300};

  auto l = [&]() mutable
  {
    x += 100;
    y += 100;
    z += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
  };
  l();
  std::cout << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
}
// Default capture by value, capture y by reference
void test6()
{
  std::cout << "\n===Test6 ==================" << std::endl;
  int x{100};
  int y{200};
  int z{300};
  auto l = [=, &y]() mutable
  {
    x += 100;
    y += 100;
    z += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
  };
  l();
  std::cout << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  // reference y increased with lambda expression
  std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
void test7()
{
  std::cout << "\n===Test7 ==================" << std::endl;
  int x{100};
  int y{200};
  int z{300};
  auto l = [&, x, z]() mutable
  {
    x += 100;
    y += 100;
    z += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
  };
  l();
  std::cout << std::endl;
  // The result is the same as test 6
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
}

class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);

private:
  std::string name;
  int age;

public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  Person(const Person &p) = default;
  ~Person() = default;
  // getter setter
  void set_name(std::string name) { this->name = name; }
  std::string get_name() { return name; }
  void set_age(int age) { this->age = age; }
  int get_age() const { return age; }
  // functions that return lambda expression
  auto change_person1() // Use this version only
  {
    return [this](std::string new_name, int new_age)
    { name = new_name; 
    age = new_age; };
  }

  // auto change_person2()
  // {
  //   return [=](std::string new_name, int new_age) mutable
  //   { name = new_name;
  //   age =new_age; };
  // }
  // auto change_person3()
  // {
  //   return [&](std::string new_name, int new_age)
  //   { name = new_name;
  //   age =new_age; };
  // }
};
std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << "[Person: " << p.name << ":" << p.age << "]";
  return os;
}

void test8()
{
  std::cout << "\n===Test8 ==================" << std::endl;
  Person person("Minho", 36);
  std::cout << person << std::endl;
  // Default capture [this]
  auto change_person1 = person.change_person1(); // lambda expression is returned
  change_person1("Sunha", 34);
  std::cout << person << std::endl;
}

// This class is exactly what happens with lambda expression behind the scene
class Lambda
{
private:
  int y;

public:
  Lambda(int y) : y{y} {};
  void operator()(int x) const
  {
    std::cout << x + y << std::endl;
  };
};
// Lambda class equivalence example
void test9()
{
  std::cout << "\n===Test9 ==================" << std::endl;
  int y{100};
  Lambda lambda1{y};
  auto lambda2 = [y](int x)
  { std::cout << x + y << std::endl; };
  lambda1(200);
  lambda2(200);
}

class People
{
  std::vector<Person> people;
  int max_people;

public:
  People(int max = 10) : max_people{max} {}
  People(const People &p) = default;
  void add(std::string name, int age)
  {
    people.emplace_back(name, age);
  }
  void set_max_people(int max)
  {
    max_people = max;
  }
  int get_max_people() const
  {
    return max_people;
  }
  // age > max_age && <= max_people
  std::vector<Person> get_people(int max_age)
  {
    std::vector<Person> result;
    int count{0};
    // copy_if(first, last, operation, condition)
    std::copy_if(people.begin(), people.end(), std::back_inserter(result), [this, &count, max_age](const Person &p)
                 { return p.get_age() > max_age && ++count <= max_people; });
    // used this, capture by reference, capture by value.
    return result;
  }
};
void test10()
{
  std::cout << "\n===Test10 ==================" << std::endl;
  People friends;
  friends.add("Minho", 18);
  friends.add("Sunha", 25);
  friends.add("Jianjun", 16);
  friends.add("Boakye", 56);
  friends.add("Qi", 65);

  auto result = friends.get_people(17);
  // 17 is max_age.
  std::cout << std::endl;
  for (const auto &p : result)
    std::cout << p << std::endl;

  friends.set_max_people(3);
  result = friends.get_people(17);
  std::cout << std::endl;
  for (const auto &p : result)
    std::cout << p << std::endl;

  result = friends.get_people(50);
  std::cout << std::endl;
  for (const auto &p : result)
    std::cout << p << std::endl;
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

  return 0;
}