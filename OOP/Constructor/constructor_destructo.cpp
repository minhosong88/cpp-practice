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
  void set_name(string name_val) { name = name_val; }
  // Overloaded Constructors
  Player()
  {
    cout << " No args Constructor called" << endl;
  }
  Player(string name)
  {
    cout << " string args Constructor called" << endl;
  }
  Player(string name, int health, int xp)
  {
    cout << " three args Constructor called" << endl;
  }
  ~Player()
  {
    cout << "Destructor called for " << name << endl;
  }
};

main()
{
  {
    Player slayer;
    slayer.set_name("Slayer");
  } // within the scope of this block
  // it goes out of this scope, destructor is called automatically
  {
    Player minho;
    minho.set_name("Minho");
    Player hero("Hero");
    hero.set_name("Hero");
    Player villain("Villain", 100, 12);
    villain.set_name("Villain");
  }

  Player *enemy = new Player;
  enemy->set_name("Enemy");
  Player *level_boss = new Player("Level Boss", 1000, 300);
  level_boss->set_name("Level Boss");
  delete enemy; // Destructor called with delete keyword
  delete level_boss;
  cout << endl;
  return 0;
}