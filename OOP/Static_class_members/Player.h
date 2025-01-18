#ifndef _Player_H_
#define _Player_H_
#include <vector>
#include <string>

class Player
{
private:
  static int num_players;
  std::string name;
  int health;
  int xp;

public:
  std::string get_name() { return name; }
  int get_health() { return health; }
  int get_xp() { return xp; }
  Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
  // Copy Constructor
  Player(const Player &source);
  // Destructor
  ~Player();

  static int get_num_players();
};

#endif