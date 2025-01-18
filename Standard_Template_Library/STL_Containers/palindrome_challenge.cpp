#include <iostream>
#include <cctype>
#include <deque>
#include <string>
#include <vector>
#include <iomanip>

/*
//instructor's solution: efficient since you can identify non-palindrome more quickly without total comparison.
bool is_palindrome(const std::string& s)
{
    std::deque<char> d;

    // add all the string characters that are alpha to the back of the deque in uppercase
    for(char c : s)
        if(std::isalpha(c))
            d.push_back(std::toupper(c));

    char c1{};
    char c2{};
    // while are more than 1 characters in the deque
    //      remove and compare the front character with the back character
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true
    while(d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        d.pop_front();
        d.pop_back();
        if(c1 != c2)
            return false;
    }
    return true;
}
*/

bool is_palindrome(const std::string &s)
{
  std::deque<char> d1;
  std::deque<char> d2;
  for (const char &c : s)
  {
    if (!std::ispunct(c) && !std::isspace(c))
    {
      char copy = std::toupper(c);
      d1.push_front(copy);
      d2.push_back(copy);
    }
  }

  return d1 == d2;
}

int main()
{
  std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva", "Amore,Roma", "A Toyota's a toyota", "A Santa at NASA", "C++", "A man, a plan, a cat, a ham, a yak, a yam, ahat, a canal-Panama!", "This is a palindrome", "palindrome"};
  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result " << "String" << std::endl;
  for (const auto &s : test_strings)
  {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
  }
  std::cout << std::endl;

  return 0;
}