#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
  // attributes (data)
  string name{"Player"};
  int health{0};
  int xp{3};

  // methods (operations and functinos)
  void talk(string);
  bool is_dead();
};
class Account
{
  // attributes
  string name{"Account"};
  double balance{0};

  // methods
  bool deposit(double);
  bool withdraw(double);
};

int main()
{
  Account minho_acc;
  Account sunha_acc;

  Player minho;
  Player hero;

  Player players[]{minho, hero};

  vector<Player> player_vec{minho};
  player_vec.push_back(hero);

  Player *enemy{nullptr};
  enemy = new Player;

  delete enemy;

  cout << endl;
  return 0;
}