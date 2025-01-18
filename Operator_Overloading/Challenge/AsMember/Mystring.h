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

  Mystring &operator=(const Mystring &rhs); // copy assignment
  Mystring &operator=(Mystring &&rhs);      // Move assignment

  void display() const;
  int get_length() const;
  const char *get_str() const;

  // other operators

  Mystring operator-() const;                    // lowercase
  Mystring operator+(const Mystring &rhs) const; // concatenation
  Mystring operator*(int number) const;
  Mystring &operator*=(int number);
  Mystring &operator+=(Mystring &rhs);
  bool operator==(const Mystring &rhs) const; // Comparison
  bool operator!=(const Mystring &rhs) const; // Comparison
  bool operator>(const Mystring &rhs) const;  // Comparison
  bool operator<(const Mystring &rhs) const;  // Comparison
  Mystring &operator++();
  Mystring operator++(int);
};

#endif