#include <iostream>
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
bool is_palindrome(const std::string &s)
{
  std::stack<char> stacked;
  std::queue<char> queued;

  for (const char c : s)
  {
    if (!::ispunct(c) && !::isspace(c))
    {
      stacked.push(std::toupper(c));
      queued.push(std::toupper(c));
    }
  }

  while (!stacked.empty())
  {
    if (stacked.top() != queued.front())
    {
      return false;
    }
    else
    {
      stacked.pop();
      queued.pop();
    }
  }
  return true;
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