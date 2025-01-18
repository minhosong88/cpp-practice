#include <iostream>
#include <vector>
#include <string>
/*
Begin challenge from codes in program control flow

- Create functions for each major functions
- Keep the functions small
- Keep the vector declaration in the main function and pass the vector to any function
- DO NOT move vector outside the main and make it global


Display Menu
P - Print numbers
A - Add a number
M - Display mean of the numbers
S - Display the smallest number
L - Display the largest number
Q - Quit

Enter your choice:

Ask the user to select options from the menu to perform operations on the list
Illegal choice displays "Unknown seletion, please try again" and the menu option displays again.abort

*** it's better to use const & for all other displaying functions as well (e.g., calc_mean, find_smallest, handle_largest) because:

* No Modification: These functions only read the vector.
* Efficiency: Avoids unnecessary copying for larger datasets.
* Consistency: Keeps the code clean and uniform.
*** Always prefer const & when reading large objects like vector without modification.

*/
using namespace std;
void display_menu();
char get_selection();
void print_numbers(const vector<int> &numbers);
void add_numbers(vector<int> &numbers);
void calc_mean(const vector<int> &numbers);
void handle_smallest(const vector<int> &numbers);
void handle_largest(const vector<int> &numbers);
void handle_find(const vector<int> &numbers);
void handle_quit();
void handle_default();
//=======================================//
int find_smallest(const vector<int> &numbers)
{
  int smallest{};

  smallest = numbers.at(0);
  for (size_t i{1}; i < numbers.size(); ++i)
  {
    if (smallest > numbers.at(i))
      smallest = numbers.at(i);
  }
  return smallest;
}
int find_largest(const vector<int> &numbers)
{
  int largest{};
  largest = numbers.at(0);
  for (size_t i{1}; i < numbers.size(); ++i)
  {
    if (largest < numbers.at(i))
      largest = numbers.at(i);
  }
  return largest;
}

bool find_number(const vector<int> &numbers, int number)
{
  bool found{false};
  for (auto num : numbers)
  {
    if (num == number)
    {
      found = true;
      break;
    }
  }
  return found;
}

void display_menu()
{
  cout << "-----------------------------" << endl;
  cout << "Menu" << endl;
  cout << "P - Print numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "S - Display the smallest number" << endl;
  cout << "L - Display the largest number" << endl;
  cout << "F - Find the integer" << endl;
  cout << "Q - Quit" << endl;
  cout << "\nEnter your choice: ";
}

char get_selection()
{
  char selection{};
  cin >> selection;
  selection = toupper(selection);
  return selection;
}

void print_numbers(const vector<int> &numbers)
{
  cout << "[";
  if (!numbers.empty())
    for (auto number : numbers)
    {
      cout << " " << number << " ";
    }
  cout << "]";
  if (numbers.empty())
    cout << " - the list is empty" << endl;
  ;
}
void add_numbers(vector<int> &numbers)
{
  int num{};
  cout << "Enter an integer to add to the list: ";
  cin >> num;
  numbers.push_back(num);
  cout << num << " added" << endl;
}

void calc_mean(const vector<int> &numbers)
{
  if (!numbers.empty())
  {
    size_t size{numbers.size()};
    int sum{0};
    double average{0.0};
    for (auto number : numbers)
    {
      sum += number;
    }
    average = static_cast<double>(sum) / size;
    cout << "The mean is: " << average << endl;
  }
  else
  {
    cout << "Unable to calculate mean- no data" << endl;
  }
}
void handle_smallest(const vector<int> &numbers)
{
  if (!numbers.empty())
  {
    cout << "The smallest number is: " << find_smallest(numbers) << endl;
  }
  else
  {
    cout << "Unable to calculate mean- no data" << endl;
  }
}
void handle_largest(const vector<int> &numbers)
{
  if (!numbers.empty())
  {
    cout << "The largest number is: " << find_largest(numbers) << endl;
  }
  else
  {
    cout << "Unable to calculate mean- no data" << endl;
  }
}

void handle_find(const vector<int> &numbers)
{
  int number{};
  bool found{};
  cout << "Enter an interger to look for: ";
  cin >> number;
  found = find_number(numbers, number);
  if (found)
  {
    cout << number << " is in the list" << endl;
  }
  else
  {
    cout << number << "is not in the list" << endl;
  }
}

void handle_quit()
{
  cout << "Good bye" << endl;
}

void handle_default()
{
  cout << "Unknown selection, please try again" << endl;
}

int main()
{
  char selection{};
  vector<int> numbers{};
  do
  {
    display_menu();
    selection = get_selection();
    switch (selection)
    {
    case 'P':
    {
      print_numbers(numbers);
      break;
    }
    case 'A':
    {
      add_numbers(numbers);
      break;
    }
    case 'M':
    {
      calc_mean(numbers);
      break;
    }
    case 'S':
    {
      handle_smallest(numbers);
      break;
    }
    case 'L':
    {
      handle_largest(numbers);
      break;
    }
    case 'F':
    {
      handle_find(numbers);
      break;
    }
    case 'Q':
      handle_quit();
      break;
    default:
      handle_default();
    }

  } while (selection != 'Q');
  cout << endl;

  return 0;
}