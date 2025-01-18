#include <iostream>
#include <vector>

using namespace std;

int main()
{ // Increment by 1
  // for (int i{1}; i <= 10; ++i)
  //   cout << i << endl;

  // Increment by 2
  // for (int i{1}; i <= 10; i += 2)
  //   cout << i << endl;

  // Decrement by 1
  // for (int i{10}; i > 0; --i)
  //   cout << i << endl;

  // Condition in the loop
  // for (int i{10}; i <= 100; i += 10)
  // {
  //   if (i % 15 == 0)
  //     cout << i << endl;
  // }

  // Two indices with comma operator
  // for (int i{1}, j{10}; i <= 5; ++i, --j)
  //   cout << i << " + " << j << " = " << (i + j) << endl;

  // with condition
  // for (int i{1}; i <= 100; i++)
  // {
  //   cout << i;
  //   if (i % 10 == 0)
  //     cout << endl;
  //   else
  //     cout << " ";
  // }

  // With Conditional operator '?'
  // for (int i{1}; i <= 100; i++)
  // {
  //   cout << i;
  //   cout << ((i % 10 == 0) ? "\n" : " ");
  // }

  // Using vectors
  vector<int> nums{10, 20, 30, 40, 50};

  for (unsigned i{0}; i < nums.size(); ++i)
    cout << nums[i] << endl;

  cout << endl;
  return 0;
}