#include <iostream>

using namespace std;

class Player
{
private:
  // attribute
  string name{"Player"};
  int health;
  int xp;

public:
  // method
  void talk(string text)
  {
    cout << name << " says " << text << endl;
  }
  bool is_dead();
};

int main()
{
  Player minho;
  // minho.name = "Minho"; // Compiler Error // Accessing private member
  // minho.health = 1000;
  minho.talk("Hello");
  cout << endl;
  return 0;
}