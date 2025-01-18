#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <vector>
#include <string>

class Mystring
{
  friend Mystring operator-(Mystring &obj);                            // lowercase
  friend Mystring operator+(const Mystring &lhs, const Mystring &rhs); // concatenation
  friend Mystring operator*(Mystring &obj, int number);
  friend Mystring &operator*=(Mystring &obj, int number);
  friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
  friend bool operator==(const Mystring &lhs, const Mystring &rhs); // Comparison
  friend bool operator!=(const Mystring &lhs, const Mystring &rhs); // Comparison
  friend bool operator>(const Mystring &lhs, const Mystring &rhs);  // Comparison
  friend bool operator<(const Mystring &lhs, const Mystring &rhs);  // Comparison
  friend Mystring &operator++(Mystring &obj);
  friend Mystring operator++(Mystring &obj, int);
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
};

#endif