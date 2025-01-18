#include <iostream>
#include <string>

using namespace std;

/*
NO CONSTRUCTOR
class Player
{
private:
  string name;
  int health;
  int xp;

public:
  void set_name(string name_val)
  {
    name = name_val;
  }
  string get_name()
  {
    return name;
  }
};*/

class Player
{
private:
  string name;
  int health;
  int xp;

public:
  void set_name(string name_val)
  {
    name = name_val;
  }
  string get_name()
  {
    return name;
  }
  // No arg constructor
  // Player()
  // {
  //   name = "None";
  //   health = 100;
  //   xp = 3;
  // }

  // 3-args constructor
  Player(string name_val, int health_val, int xp_val)
  {
    name = name_val;
    health = health_val;
    xp = xp_val;
  }
};

int main()
{
  // no constructor is declared so default constructor is automatically provided by c++
  // Player minho;
  // minho.set_name("Minho");
  // cout << endl;

  // with the default constructor, values for the attributes are provided by the constructor.
  // Player minho; // If you declare constructors with arguments without default constructor, c++ does not automatically offer default constructor.

  Player minho("Minho", 100, 13);
  minho.set_name("Minho");
  cout << endl;

  return 0;
}