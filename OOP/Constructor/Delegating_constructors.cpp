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
  Player();
  Player(string name_val);
  Player(string name_val, int health_val, int xp_val);
};
Player::Player() // call the three-args constructor first and initialized
    : Player{"None", 0, 0}
{
  cout << "No-args constructor" << endl;
}

Player::Player(std::string name_val)
    : Player{name_val, 0, 0}
{
  cout << "one-args constructor" << endl;
}
// Delegation initialization to the three-arg constructor
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
  cout << "three-args constructor" << endl;
}

int main()
{
  Player empty;
  Player minho{"Minho"};
  Player villain{"Villain", 100, 50};
  return 0;
}