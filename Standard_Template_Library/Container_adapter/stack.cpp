#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
void display(std::stack<T> s) // get the copy not the reference
{
  std::cout << "[ ";
  while (!s.empty())
  {
    T elem = s.top();         // value copy
    s.pop();                  // pop
    std::cout << elem << " "; // print
  }
  std::cout << "]" << std::endl;
}

int main()
{
  std::stack<int> s;
  std::stack<int, std::vector<int>> s1;
  std::stack<int, std::list<int>> s2;

  for (int i : {1, 2, 3, 4, 5})
    s.push(i);
  display(s);
  s.push(100);
  display(s);

  s.pop();
  s.pop();
  display(s);

  while (!s.empty())
    s.pop();
  display(s);
  // the previous stack has been emptied.
  std::cout << "Size: " << s.size() << std::endl;

  s.push(10);
  display(s);
  s.top() = 100;
  display(s);

  return 0;
}