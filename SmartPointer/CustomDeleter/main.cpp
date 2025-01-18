#include <iostream>
#include <memory>
using namespace std;
class Test
{
private:
  int data;

public:
  // No args constructor - delegating
  Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
  // args constructor
  Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
  // getter
  int get_data() const { return data; }
  ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test *ptr)
{
  cout << "\tUsing my custom function deleter" << endl;
  delete ptr;
}

int main()
{
  {
    // Using a function
    shared_ptr<Test> ptr1{new Test{100}, my_deleter};
  }
  cout << "==================" << endl;
  {
    // Using Lambda expression
    shared_ptr<Test> ptr2(
        new Test{100}, [](Test *ptr)
        { 
          cout << "\tUsing my custom lambda deleter" << endl; 
          delete ptr; });
  }
  cout << endl;
  return 0;
}