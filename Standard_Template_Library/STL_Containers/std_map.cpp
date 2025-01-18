#include <iostream>
#include <set>
#include <map>

// Without this specific display, printing this obeject will cause a compile error
void display(const std::map<std::string, std::set<int>> &m)
{
  std::cout << "[ ";
  for (const auto &elem : m)
  {
    std::cout << elem.first << ": [ ";
    for (const auto &set_elem : elem.second)
      std::cout << set_elem << " ";
    std::cout << "] ";
  }
  std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &m)
{
  std::cout << "[ ";
  for (const auto &elem : m)
    std::cout << elem.first << ":" << elem.second << " ";
  std::cout << "]" << std::endl;
}

void test1()
{
  std::cout << "\nTest 1==========================" << std::endl;
  std::map<std::string, int> m{
      {"Minho", 20},
      {"Sunha", 10},
      {"Jianjun", 30},
  };
  display(m);

  m.insert(std::pair<std::string, int>("Georgia", 50));
  display(m);
  m.insert(std::make_pair("Boakye", 60));
  display(m);
  m["Minho"] = 18;
  display(m);
  m["Minho"] += 30;
  display(m);
  m.erase("Minho");
  display(m);

  std::cout << "Count for Minho: " << m.count("Minho") << std::endl;
  std::cout << "Count for Sunha: " << m.count("Sunha") << std::endl;

  auto it = m.find("Jianjun");
  // return key-value pair(first, second)
  if (it != m.end())
    std::cout << "Found " << it->first << ":" << it->second << std::endl;
  m.clear();
  display(m);
}
void test2()
{
  std::cout << "\nTest 2==========================" << std::endl;
  std::map<std::string, std::set<int>> grades{
      {"Minho", {95, 100, 96}},
      {"Sunha", {99, 93, 95}},
      {"Jianjun", {88, 95, 86}}};
  display(grades);
  grades["Minho"].insert(100);

  display(grades);

  auto it = grades.find("Sunha");
  if (it != grades.end())
  {
    it->second.insert(100);
  }
  display(grades);
}

int main()
{
  test1();
  test2();
  return 0;
}