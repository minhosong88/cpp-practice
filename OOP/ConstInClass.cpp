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
  void set_name(string name_val)
  {
    name = name_val;
  }
  string get_name() const
  {
    return name;
  }
  // Overloaded Constructo
  Player();
  Player(string name_val);
  Player(string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player{"None", 0, 0}
{
}
Player::Player(string name_val)
    : Player{name_val, 0, 0}
{
}
Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}
void display_player_name(const Player &p)
{
  cout << p.get_name() << endl;
}
int main()
{
  const Player villain{"Villain", 100, 55};
  Player hero{"Hero", 100, 15};

  cout << villain.get_name() << endl;
  cout << hero.get_name() << endl;

  display_player_name(hero);
  display_player_name(villain);

  cout << endl;
  return 0;
}