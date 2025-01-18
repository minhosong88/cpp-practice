#include "Movie.h";
#include <iostream>

Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
    : name{name_val}, rating{rating_val}, watched{watched_val} {}

// Copy Constructor
Movie::Movie(const Movie &source)
    : Movie(source.name, source.rating, source.watched) {}
// Destructor
Movie::~Movie()
{
}

// Implement method
void Movie::display() const
{
  std::cout << "Movie name: " << name << std::endl;
  std::cout << "Rating : " << rating << std::endl;
  std::cout << "Watched: " << watched << std::endl;
}