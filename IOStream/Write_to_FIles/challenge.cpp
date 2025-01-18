#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  ifstream in_file("romeoandjuliet.txt");
  if (!in_file)
  {
    cerr << "Problem Opening File" << endl;
    return 1;
  }
  ofstream out_file("copy_romeoandjuliet.txt");
  if (!out_file)
  {
    cerr << "Problem Creating Files" << endl;
    return 1;
  }

  string line;
  int line_num{1};
  while (getline(in_file, line))
  {
    if (!line.empty())
      out_file << setw(6) << left << line_num++ << right << line << endl;
    else
      out_file << line << endl;
  }
  cout << "Copy Complete" << endl;
  in_file.close();
  out_file.close();
  cout << endl;
  return 0;
}