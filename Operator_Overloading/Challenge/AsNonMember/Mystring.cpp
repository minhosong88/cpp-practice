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

// Destructor
Mystring::~Mystring()
{
  delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
  if (this != &rhs)
  {
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
  }
  else
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
  if (this != &rhs)
  {
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
  }
  else
    return *this;
}

void Mystring::display() const
{
  std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }

// Overloaded operators
Mystring operator-(Mystring &obj)
{
  char *buff = new char[strlen(obj.str) + 1];
  strcpy(buff, obj.str);
  for (size_t i{0}; i < strlen(buff); ++i)
    buff[i] = tolower(buff[i]);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
  char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
  strcpy(buff, lhs.str);
  strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;

} // concatenation
Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
  char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
  strcpy(buff, lhs.str);
  strcat(buff, rhs.str);
  delete[] lhs.str; // deallocate str from previous memory
  lhs.str = buff;   // allocate buff to str
  return lhs;
}
// Repetition
Mystring operator*(Mystring &obj, int number)
{
  char *buff = new char[strlen(obj.str) * number + 1];
  buff[0] = '\0'; // Sets the first character to null terminator
  for (size_t i{0}; i < number; ++i)
  {
    strcat(buff, obj.str);
  }
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

Mystring &operator*=(Mystring &obj, int number)
{
  char *buff = new char[strlen(obj.str) * number + 1];
  buff[0] = '\0';
  for (size_t i{0}; i < number; ++i)
  {
    strcat(buff, obj.str);
  }
  // Deallocate memory
  delete[] obj.str;
  obj.str = buff;

  return obj;
}

// Comparison
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
  return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
  return (strcmp(lhs.str, rhs.str) != 0);
}
bool operator>(const Mystring &lhs, const Mystring &rhs)
{
  return (strcmp(lhs.str, rhs.str) > 0);
}
bool operator<(const Mystring &lhs, const Mystring &rhs)
{
  return (strcmp(lhs.str, rhs.str) < 0);
}

// Capitalize
Mystring &operator++(Mystring &obj)
{ // pre_increment
  for (size_t i{0}; i < strlen(obj.str); ++i)
  {
    obj.str[i] = toupper(obj.str[i]);
  }
  return obj;
}
Mystring operator++(Mystring &obj, int)
{
  // post_increment
  Mystring temp{obj};
  for (size_t i{0}; i < strlen(obj.str); ++i)
  {
    obj.str[i] = toupper(obj.str[i]);
  }

  return temp;
}
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
  os << rhs.str;
  return os;
}
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
  char *buff = new char[1000];
  is >> buff;           // store input to buff
  rhs = Mystring{buff}; // assign buff object to rhs
  delete[] buff;        // free up buff storage
  return is;
}
