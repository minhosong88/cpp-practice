#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <vector>
#include <string>

class Mystring
{
  friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
  friend std::istream &operator>>(std::istream &is, Mystring &rhs);

private:
  char *str; // pointer to a char[]

public:
  Mystring();                       // No args constructor
  Mystring(const char *s);          // Overloaded constructor
  Mystring(const Mystring &source); // copy constructor
  Mystring(Mystring &&source);      // Move constructor
  ~Mystring();                      // destructor

  Mystring &operator=(const Mystring &rhs); // Copy assignment
  Mystring &operator=(Mystring &&rhs);      // Move assignment

  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif