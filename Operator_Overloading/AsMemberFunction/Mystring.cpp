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
  if (str == nullptr)
  {
    std::cout << "Calling destructor for Mystring: nullptr" << std::endl;
  }
  else
  {
    std::cout << "Calling destructor for Mystring: " << str << std::endl;
  }
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
// Equality
bool Mystring::operator==(const Mystring &rhs) const
{
  return (std::strcmp(str, rhs.str) == 0);
}

// Lowercase
Mystring Mystring::operator-() const
{
  char *buff = new char[std::strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i = 0; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
  char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;

  return temp;
}

// Display method
void Mystring::display() const
{
  std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }