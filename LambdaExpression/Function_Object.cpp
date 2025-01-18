#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
struct Square_Functor
{
  void operator()(int x)
  {
    std::cout << x * x << " ";
  }
};

template <typename T>
struct Displayer
{
  void operator()(const T &data)
  {
    std::cout << data << " ";
  }
};

class Multiplier
{
private:
  int num{};

public:
  Multiplier(int n) : num{n} {}
  int operator()(int n) const
  {
    return n * num;
  }
};

void test1()
{
  std::cout << "\nTest1 =========================" << std::endl;

  Square_Functor square;
  square(4); // this is not a function but an object : square.operator()(4) executed

  Displayer<int> d1;
  Displayer<std::string> d2;

  d1(100);     // d.operator()(100)
  d2("Minho"); // d.operator()("Minho")
}
void test2()
{
  std::cout << "\nTest2 =========================" << std::endl;
  Square_Functor square;
  Displayer<int> d1;
  Displayer<std::string> d2;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<std::string> vec2{"Minho", "Sunha", "Jianjun"};

  // Operator() executes with for_each function
  std::for_each(vec1.begin(), vec1.end(), square);
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(), d1);
  std::cout << std::endl;
  // String vectors
  std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
  std::cout << std::endl;

  std::for_each(vec2.begin(), vec2.end(), d2);
  std::cout << std::endl;
}
void test3()
{
  std::cout << "\nTest3 =========================" << std::endl;
  Square_Functor square;
  Displayer<int> d1;
  Displayer<std::string> d2;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<std::string> vec2{"Minho", "Sunha", "Jianjun"};

  std::for_each(vec1.begin(), vec1.end(), [](int x)
                { std::cout << x * x << " "; });
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(), [](int x)
                { std::cout << x * 10 << " "; });
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(), [](int x)
                { std::cout << x << " "; });
  std::cout << std::endl;

  std::for_each(vec2.begin(), vec2.end(), [](std::string s)
                { std::cout << s << " "; });
  std::cout << std::endl;
}
void test4()
{
  std::cout << "\nTest4 =========================" << std::endl;
  Displayer<int> d1;
  std::vector<int> vec1{1, 2, 3, 4, 5};

  Multiplier mult{100}; // anything passed to the object is multiplied by 100
  std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
  std::for_each(vec1.begin(), vec1.end(), d1);
  std::cout << std::endl;

  vec1 = {1, 2, 3, 4, 5};
  std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x)
                 { return x * 100; });
  std::for_each(vec1.begin(), vec1.end(), [](int x)
                { std::cout << x << " "; });
  std::cout << std::endl;
}
int main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}