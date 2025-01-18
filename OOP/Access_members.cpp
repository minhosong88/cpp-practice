#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
  // attributes (data)
  string name{"Player"};
  int health{0};
  int xp{3};

  // methods (operations and functinos)
  void talk(string text_to_say)
  {
    cout << name << " says " << text_to_say << endl;
  }
  bool is_dead();
};
class Account
{
public:
  // attributes
  string name{"Account"};
  double balance{0};

  // methods
  void deposit(double bal)
  {
    balance += bal;
    cout << "in deposit" << endl;
  }
  void withdraw(double bal)
  {
    balance - +bal;
    cout << "in withdrawal" << endl;
  }
};

int main()
{
  Account minho_acc;
  minho_acc.name = "Minho's account";
  minho_acc.balance = 5000.0;

  minho_acc.deposit(1000.0);
  minho_acc.withdraw(500.0);

  Player minho;
  minho.name = "Minho";
  minho.health = 120;
  minho.xp = 10;

  minho.talk("Hi, there");

  Player *enemy = new Player; // pointer to the player, currenly garbage
  (*enemy).name = "Enemy";    // assign values
  (*enemy).health = 100;
  enemy->xp = 15;

  enemy->talk("I will destroy you");
  delete enemy;
  cout
      << endl;
  return 0;
}