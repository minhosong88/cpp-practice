#include <iostream> // Provides input and output functionality (cin, cout)

int main()
{
  // Declare a variable to store the user's favorite number
  int favorite_number;

  // Prompt the user to enter their favorite number
  std::cout << "Enter Your Favorite Number between 1 and 100:";

  // Read the user's input into the favorite_number variable
  std::cin >> favorite_number;

  // Acknowledge the user's input
  std::cout << "Amazing! " << favorite_number << " is my favorite number, too" << std::endl;

  return 0; // Indicate that the program ended successfully
}