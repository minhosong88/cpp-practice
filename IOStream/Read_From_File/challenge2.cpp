#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // For std::transform
#include <cctype>
// Word Finder // Made it Case Insensitive
using namespace std;
void display(const int &total, const int &num_substr, string substring);
vector<int> return_counts(fstream &in_file, string substring);
void display(const int &total, const int &num_substr, string substring)
{
  cout << total << " words were searched...." << endl;
  cout << "The substring " << substring << " was found " << num_substr << " times" << endl;
}
string format_word(string word)
{
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
  return word;
}
bool is_found(const string &word, const string &substring)
{                                      // It only requires the search word exists or not
  size_t found = word.find(substring); // Find method returns the starting index of substring if exists, or npos
  if (found == string::npos)
    return false;
  else
    return true;
}
vector<int> return_counts(fstream &in_file, string substring)
{
  string word;
  vector<int> counts{};
  int total_count{0};
  int substr_count{0};
  while (in_file >> word)
  {
    ++total_count;
    word = format_word(word);
    substring = format_word(substring);
    if (is_found(word, substring))
      ++substr_count;
  }
  counts.push_back(total_count);
  counts.push_back(substr_count);
  return counts;
}

int main()
{
  fstream in_file;
  in_file.open("romeoandjuliet.txt");
  if (!in_file)
  {
    cerr << "Problem Opening File" << endl;
    exit(1);
  }
  cout << "Enter the substring to search for: ";
  string substring{};
  cin >> substring;

  vector<int> counts;

  counts = return_counts(in_file, substring);

  int total{counts.at(0)};
  int substr_count{counts.at(1)};
  display(total, substr_count, substring);
  in_file.close();
  cout << endl;
  return 0;
}