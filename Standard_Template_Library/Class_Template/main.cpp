#include <iostream>
#include <string>
#include <vector>
// Template Class(Typically contained in header files. You would have the tamplates class in Item.h and no .cpp file would be used)
template <typename T>
class Item
{
private:
  std::string name;
  T value;

public:
  Item(std::string name, T value) : name{name}, value{value}
  {
  }
  std::string get_name() const { return name; }
  T get_value() const { return value; }
};

template <typename T1, typename T2>
struct My_pair
{
  T1 first;
  T2 second;
};

main()
{
  // value :int
  Item<int> item1{"Minho", 100};
  std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

  // value : string
  Item<std::string> item2{"Sunha", "Nurse"};
  std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

  // value : Item object
  Item<Item<std::string>> item3{"Jianjun", {"C++", "Professor"}};
  std::cout << item3.get_name() << " " << item3.get_value().get_name() << " " << item3.get_value().get_value() << std::endl;

  std::cout << "\n-------------------------------" << std::endl;

  std::vector<Item<double>> vec{};
  vec.push_back(Item<double>("Minho", 100.0));
  vec.push_back(Item<double>("Sunha", 200.0));
  vec.push_back(Item<double>("Jianjun", 300.0));

  for (const auto &item : vec)
  {
    std::cout << item.get_name() << " " << item.get_value() << std::endl;
  }
  std::cout << "\n-------------------------------" << std::endl;

  My_pair<std::string, int> p1{"Minho", 100};
  My_pair<int, double> p2{124, 200.00};
  std::cout << p1.first << ", " << p1.second << std::endl;
  std::cout << p2.first << ", " << p2.second << std::endl;

  return 0;
}