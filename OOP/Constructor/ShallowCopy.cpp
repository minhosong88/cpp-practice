#include <iostream>

using namespace std;

class Shallow
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value()
  {
    return *data;
  }
  // Constructor
  Shallow(int d);
  // Copy constructor
  Shallow(const Shallow &source);
  // Destructor
  ~Shallow();
};

Shallow::Shallow(int d)
{
  data = new int;
  *data = d;
}

Shallow::Shallow(const Shallow &source) : data{source.data}
{
  cout << "Copy Constructor-shallow copy" << endl;
}
Shallow::~Shallow()
{
  cout << "Destructor -freeing data" << endl;
}
// object as a variable passed to a function
void display_shallow(Shallow s)
{
  cout << s.get_data_value() << endl;
}
int main()
{
  Shallow obj1{100};
  display_shallow(obj1); // Once the function is done, it frees up data including what the pointer points to.

  // even obj1 is not pointing to an invalid memory.

  Shallow obj2{obj1}; // Here obj2 is refering to the location where it is already freed up.

  // obj1 is now pointing to a location where the wanted value is not there anymore.

  // obj2.set_data_value{1000}; // Compile Error
  return 0;
}