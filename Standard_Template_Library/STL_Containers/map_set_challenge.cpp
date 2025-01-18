#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
void display(const std::map<std::string, std::set<int>> &m)
{
  std::cout << "[ \n";
  for (const auto &elem : m)
  {
    std::cout << elem.first << ": [ ";
    for (const auto &set_elem : elem.second)
      std::cout << set_elem << " ";
    std::cout << "]\n";
  }
  std::cout << "]"
            << std::endl;
}
void part1()
{
  std::ifstream in_file{"words.txt"};
  if (!in_file)
    std::cout << "Problem Opening File" << std::endl;
  // Part 1. Word count
  std::map<std::string, int> word_count;
  std::string word;

  while (in_file >> word)
  {
    word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
    word_count[word]++;
  }

  std::cout << std::setw(10) << std::left << "Word" << std::setw(6) << std::right << "Count" << std::endl;
  std::cout << "================" << std::endl;
  for (const auto &elem : word_count)
  {
    std::cout << std::setw(10) << std::left << elem.first << std::setw(6) << std::right << elem.second << std::endl;
  }
}

void part2()
{
  std::ifstream in_file{"words.txt"};
  if (!in_file)
    std::cout << "Problem Opening File" << std::endl;
  std::map<std::string, std::set<int>> word_line;
  std::string line;
  int line_num{1};

  while (std::getline(in_file, line))
  {
    std::string word;
    std::istringstream iss{line};
    while (iss >> word)
    {
      word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
      word_line[word].insert(line_num);
    }
    line_num++;
  }
  std::cout << std::setw(10) << std::left << "Word" << std::setw(6) << std::right << "set: line numbers" << std::endl;
  std::cout << "===========================================" << std::endl;

  display(word_line);
}
int main()
{
  part1();
  std::cout << "===========================================" << std::endl;

  part2();

  return 0;
}