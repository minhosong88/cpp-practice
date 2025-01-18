#include <cstring>
#include "Mystring.h"
#include <iostream>

using namespace std;

// No args Constructor
Mystring::Mystring()
    : str{nullptr}
{
  str = new char[1];
  *str = '\0';
}

// Overloaded Constructor
Mystring::Mystring(const char *s)
    : str{nullptr}
{
  if (s == nullptr)
  {
    str = new char[1];
    *str = '\0';
  }
  else
  {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
  }
}

// Copy Constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
}

// Move Constructor
Mystring::Mystring(Mystring &&source)
    : str{source.str} // stealing the pointer from the source
{
  source.str = nullptr; // and nullifying the source pointer
  std::cout << "Move assignment" << std::endl;
}

// Destructor
Mystring::~Mystring()
{

  delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
  std::cout << "Copy Assignment" << endl;
  if (this != &rhs) // if this(pointer) is the same as the address of rhs
  {
    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
  }
  else
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
  std::cout << "Move Assignment" << endl;
  if (this == &rhs) // check if the addresses are the same first(comparing addresses)
    return *this;
  delete[] str;      // Remove the pointer from LHS
  str = rhs.str;     // Move pointer of RHS to LHS
  rhs.str = nullptr; // nullify RHS pointer
  return *this;
}
// Display method
void Mystring::display() const
{
  std::cout << str << ": " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return std::strlen(str); }
const char *Mystring::get_str() const { return str; }

// Regular global function
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
  return (std::strcmp(lhs.str, rhs.str) == 0);
}
Mystring operator-(const Mystring &obj)
{
  char *buff = new char[std::strlen(obj.str) + 1];
  std::strcpy(buff, obj.str);
  for (size_t i{0}; i < std::strlen(buff); ++i)
    buff[i] = tolower(buff[i]);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
  char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
  strcpy(buff, lhs.str);
  strcpy(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}