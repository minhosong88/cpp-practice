#include <iostream>
#include <vector>
#include <string>

enum Direction
{
  North, // 0
  South, // 1
  East,  // 2
  West   // 3
};
// enum Street {Main, North, Elm} ; Error : North is used twice

// A function that expects Direction parameter and returns a string
std::string direction_to_string(Direction direction)
{
  std::string result;
  switch (direction)
  {
  case North:
    result = "North";
    break;
  case South:
    result = "South";
    break;
  case East:
    result = "East";
    break;
  case West:
    result = "West";
    break;
  default:
    result = "Unknown direction";
  }
  return result;
}

void test1()
{
  std::cout << "\n ---Test1 ---------------------\n"
            << std::endl;
  Direction direction{North};
  std::cout << "\nDirection " << direction << std::endl;
  std::cout << direction_to_string(direction) << std::endl;

  direction = West;
  std::cout << "\nDirection " << direction << std::endl;
  std::cout << direction_to_string(direction) << std::endl;

  // direction = 5 Compiler Error

  // Be careful Casting
  direction = Direction(100);
  std::cout << "\nDirection " << direction << std::endl;
  std::cout << direction_to_string(direction) << std::endl;

  direction = static_cast<Direction>(100);
  std::cout << "\nDirection " << direction << std::endl;
  std::cout << direction_to_string(direction) << std::endl;
}

enum Grocery_Item
{
  Milk,
  Bread,
  Apple,
  Orange
};

// Overloading stream insertion operator
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
  switch (grocery_item)
  {
  case Milk:
    os << "Milk";
    break;
  case Bread:
    os << "Bread";
    break;
  case Apple:
    os << "Apple";
    break;
  case Orange:
    os << "Orange";
    break;
  default:
    os << "Unknown Item";
  }
  return os;
}
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
  switch (grocery_item)
  {
  case Milk:
  case Bread:
  case Apple:
  case Orange:
    return true;
  default:
    return false;
  }
}

void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
  std::cout << "Grocery List " << "\n =======================" << std::endl;
  int invalid_item_count{0};
  int valid_item_count{0};
  for (Grocery_Item grocery_item : grocery_list)
  {
    // Overloaded insertion operator works here
    std::cout << grocery_item << std::endl;
    if (is_valid_grocery_item(grocery_item))
      valid_item_count++;
    else
      invalid_item_count++;
  }

  std::cout << " ============================" << std::endl;
  std::cout << "Valid items: " << valid_item_count << std::endl;
  std::cout << "Invalid items: " << invalid_item_count << std::endl;
  std::cout << "Total items: " << valid_item_count + invalid_item_count << std::endl;
}

void test2()
{
  std::cout << "\n ---Test2 ---------------------\n"
            << std::endl;
  std::vector<Grocery_Item> shopping_list;
  shopping_list.push_back(Apple);
  shopping_list.push_back(Apple);
  shopping_list.push_back(Milk);
  shopping_list.push_back(Orange);
  shopping_list.push_back(Orange);
  shopping_list.push_back(Bread);
  shopping_list.push_back(Apple);

  // Grocery_Item item = 100; Complier Error // strict type safety
  int Helicopter{1000};
  // Explicit type cast is necessary for enum
  shopping_list.push_back(Grocery_Item(Helicopter));
  shopping_list.push_back(Grocery_Item(0)); // Milk

  display_grocery_list(shopping_list);
}

enum State
{
  Engine_Failure,
  Inclement_Weather,
  Nominal,
  Unknown
};
enum Sequence
{
  Abort,
  Hold,
  Launch
};
// Overloading extraction operator
std::istream &operator>>(std::istream &is, State &state)
{
  // Notice underlying_type_t
  std::underlying_type_t<State> user_input;
  is >> user_input;

  switch (user_input)
  {
  case Engine_Failure:
  case Inclement_Weather:
  case Nominal:
  case Unknown:
    state = State(user_input);
    break;
  default:
    std::cout << "User input is not a valid launch state." << std::endl;
    state = Unknown;
  }
  return is;
}
// Overloading insertion operator
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
  switch (sequence)
  {
  case Abort:
    os << "Abort";
    break;
  case Hold:
    os << "Hold";
    break;
  case Launch:
    os << "Launch";
    break;
  }
  return os;
}
void initiate(Sequence sequence)
{
  std::cout << "Initiate " << sequence << " Sequence!" << std::endl; // Uses overloaded insertion operator above
}
void test3()
{
  std::cout << "\n ---3 ---------------------\n"
            << std::endl;
  State state;
  std::cout << "Launch state: ";
  std::cin >> state; // overloaded extraction operator >>

  switch (state)
  {
  case Engine_Failure:
  case Unknown:
    initiate(Abort);
    break;
  case Inclement_Weather:
    initiate(Hold);
    break;
  case Nominal:
    initiate(Launch);
    break;
  }
}
int main()
{
  // test1();
  // test2();
  test3();
  return 0;
}