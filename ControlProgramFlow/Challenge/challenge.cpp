#include <iostream>
#include <vector>
using namespace std;
/*
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



*/
int main()
{
  char selection{};
  vector<int> numbers{};
  do
  {
    cout << "-----------------------------" << endl;
    cout << "Menu" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
    cin >> selection;

    switch (selection)
    {
    case 'p':
    case 'P':
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
      break;
    }
    case 'a':
    case 'A':
    {
      int num{};
      cout << "Enter an integer to add to the list: ";
      cin >> num;
      numbers.push_back(num);
      cout << num << " added" << endl;
      break;
    }
    case 'm':
    case 'M':
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
      break;
    }
    case 's':
    case 'S':
    {
      int smallest{};
      if (!numbers.empty())
      {
        smallest = numbers.at(0);
        for (size_t i{1}; i < numbers.size(); ++i)
        {
          if (smallest > numbers.at(i))
            smallest = numbers.at(i);
        }
        cout << "The smallest number is: " << smallest << endl;
      }
      else
      {
        cout << "Unable to calculate mean- no data" << endl;
      }
      break;
    }
    case 'l':
    case 'L':
    {
      int largest{};
      if (!numbers.empty())
      {
        largest = numbers.at(0);
        for (size_t i{1}; i < numbers.size(); ++i)
        {
          if (largest < numbers.at(i))
            largest = numbers.at(i);
        }
        cout << "The largest number is: " << largest << endl;
      }
      else
      {
        cout << "Unable to calculate mean- no data" << endl;
      }
      break;
    }
    case 'q':
    case 'Q':
      cout << "Good bye" << endl;
      break;
    default:
      cout << "Unknown selection, please try again" << endl;
    }

  } while (selection != 'q' && selection != 'Q');
  cout << endl;

  return 0;
}