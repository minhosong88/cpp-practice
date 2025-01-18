#include <iostream>
#include <fstream>
#include <string>

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

  string line;

  while (getline(in_file, line))
    out_file << line << endl;

  cout << "File Copied" << endl;

  in_file.close();
  out_file.close();

  cout << endl;
  return 0;
}