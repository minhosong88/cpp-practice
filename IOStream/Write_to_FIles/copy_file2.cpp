#include <iostream>
#include <fstream>
#include <string>
// File copy using get/put
using namespace std;

int main()
{
  ifstream in_file("poem.txt");
  ofstream out_file("poem_output.txt");

  if (!in_file)
  {
    cerr << "Error opening file" << endl;
    return 1;
  }

  if (!out_file)
  {
    cerr << "Error creating file" << endl;
    return 1;
  }

  char c;
  while (in_file.get(c))
    out_file.put(c);
  cout << "File Copied" << endl;

  in_file.close();
  out_file.close();

  cout << endl;
  return 0;
}