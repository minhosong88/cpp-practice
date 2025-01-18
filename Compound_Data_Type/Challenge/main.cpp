#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> vector1;
  vector<int> vector2;

  vector1.push_back(10);
  vector1.push_back(20);

  cout << "Elements in vector1 is: " << vector1.at(0) << " and " << vector1.at(1) << endl;
  cout << "The size of the vector is " << vector1.size() << endl;

  vector2.push_back(100);
  vector2.push_back(200);

  cout << "Elements in vector2 is: " << vector2.at(0) << " and " << vector2.at(1) << endl;
  cout << "The size of the vector is " << vector2.size() << endl;

  // 2D-vector
  vector<vector<int>> vector_2d;
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout << "Elements in vector_2d is " << endl;
  cout << vector_2d.at(0).at(0) << endl;
  cout << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << endl;
  cout << vector_2d.at(1).at(1) << endl;

  // Interesting part

  vector1.at(0) = 1000;
  cout << "Elements in vector_2d now is " << endl;

  cout << vector_2d.at(0).at(0) << endl;
  cout << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << endl;
  cout << vector_2d.at(1).at(1) << endl;

  cout << "Elements in vector1 now is: " << vector1.at(0) << " and " << vector1.at(1) << endl;

  // The element of vector1 in vector_2d does not change but vector1's element changed.
  // This is because the changed value is not added to vector_2d yet. >> because you are adding copy of the value
  // behave as I expected
  return 0;
}