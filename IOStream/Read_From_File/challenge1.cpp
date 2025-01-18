#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void header()
{
  cout << setw(26) << setfill('-') << "\n";
  cout << setfill(' ');
  cout << setw(13) << left << "Student" << setw(12) << right << "Score" << endl;
  cout << setw(26) << setfill('-') << "\n";
  cout << setfill(' ');
}

void footer(double average)
{
  cout << setw(26) << setfill('-') << "\n";
  cout << setfill(' ');
  cout << setw(13) << left << "Avergage" << setw(12) << fixed << setprecision(1) << right << average;
}
void display_students(vector<string> names, vector<int> scores)
{
  for (size_t i{0}; i < names.size(); ++i)
  {
    cout << setw(13) << left << names.at(i);

    cout << setw(12) << right << scores.at(i) << endl;
  }
}
int process_answers(const string &answer, const string &response)
{
  int score{0};
  for (size_t i{0}; i < answer.size(); ++i)
  {
    if (answer[i] == response[i])
      ++score;
  }
  return score;
}

int main()
{
  fstream in_file;
  in_file.open("responses.txt");
  if (!in_file)
  {
    cerr << "Problem Opening File" << endl;
    exit(1);
  }
  string answer{};
  vector<string> names;
  vector<int> scores;
  string name{};
  string response{};
  int total{0};

  in_file >> answer;

  while (in_file >> name >> response)
  {
    names.push_back(name);
    int score{process_answers(answer, response)};
    scores.push_back(score);
    total += score;
  }
  double average{static_cast<double>(total) / names.size()};

  header();
  display_students(names, scores);
  footer(average);

  in_file.close();

  return 0;
}