#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  int scores[]{10, 20, 30};
  // using 'auto' keyword
  // for (auto score : scores)
  // {
  //   cout << score << endl;
  // }

  // Using Vector
  // vector<double> temperatures{89.3, 23.4, 80.3, 54.3};
  // double average_temp{};
  // double total{};
  // for (auto temp : temperatures)
  // {
  //   total += temp;
  // }
  // if (temperatures.size() != 0)
  //   average_temp = total / temperatures.size();
  // cout << fixed << setprecision(1);
  // cout << "Average temperature is " << average_temp << "F" << endl;

  // Explicit leyout of array
  //  for (auto val:{1,2,3,4,5})
  //    cout << val << endl;

  // Example of string iteration
  // for (auto c : "This is a test")
  //   if (c != ' ')
  //     cout << c;

  for (auto c : "This is a test")
    if (c == ' ')
      cout << "\t";
    else
      cout << c;
  cout << endl;

  return 0;
}