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
  string get_name() { return name; }
  int get_health() { return health; }
  int get_xp() { return xp; }
  Player(string name_val = "None", int health_val = 0, int xp_val = 0);
  // Copy Constructor:prototype
  Player(const Player &source);
  // Destructor
  ~Player() { cout << "Destructor called for " << name << endl; }
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
  cout << "three-args constructor" << endl;
}
// Copy Constructor implementation (const Type &reference)
Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp(source.xp)
    : Player{source.name,
             source.health,
             source.xp} // Delegating constructor
{
  cout << "Copy constructor - made copy of: " << source.name << endl;
}

// Using the value of copy constructor
void display_player(Player p)
{
  cout << "Name: " << p.get_name() << endl;
  cout << "Health: " << p.get_health() << endl;
  cout << "XP: " << p.get_xp() << endl;
}

int main()
{
  Player empty;
  display_player(empty);
  Player minho{"Minho"};
  display_player(minho);

  Player base_object{"Base", 10, 10};
  // constructing an object based on another
  Player new_object{base_object};

  Player hero{"Hero", 100};
  Player villain{"Villain", 100, 50};
  return 0;
}