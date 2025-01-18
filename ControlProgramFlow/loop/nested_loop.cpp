#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // 1. Multiplication Example
  // for (int num1{1}; num1 <= 10; ++num1)
  // {
  //   for (int num2{1}; num2 <= 10; ++num2)
  //   {
  //     cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
  //   }
  //   cout << "----------" << endl;
  // }

  // 2. Histogram
  int num_items{};
  cout << "How many data items do you have?:";
  cin >> num_items;

  vector<int> data{};
  for (int i{1}; i <= num_items; ++i)
  {
    cout << "Enter data item " << i << " :";
    int data_item{};
    cin >> data_item;
    data.push_back(data_item);
  }

  cout << "\n Displaying Histogram" << endl;
  for (auto val : data)
  {
    for (int i{1}; i <= val; ++i)
    {
      cout << "*";
      if (i % 5 == 0)
        cout << "/";
    }
    cout << endl;
  }

  cout << endl;
  return 0;
}