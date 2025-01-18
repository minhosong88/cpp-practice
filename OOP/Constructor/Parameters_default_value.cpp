#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
  string name;
  int health;
  int xp;

public:
  // Overloaded Constructors
  // Constructor with default parameter values
  Player(string name_val = "None", int health_val = 0, int xp_val = 0);
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
  cout << "three-args constructor" << endl;
}

int main()
{
  Player empty;
  Player minho{"Minho"};
  Player hero{"Hero", 100};
  Player villain{"Villain", 100, 50};
  return 0;
}