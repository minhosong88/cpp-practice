#ifndef _Movie_H_
#define _Movie_H_
#include <vector>
#include <string>

class Movie
{
private:
  std::string name;
  std::string rating;
  int watched;

public:
  // Constructor
  Movie(std::string name_val, std::string rating_val, int watched_val);

  // Copy Constructor
  Movie(const Movie &source)
      : Movie(source.name, source.rating, source.watched) {}
  // Destructor
  ~Movie();

  // getter & setter

  void set_name(std::string name_val) { name = name_val; }
  void set_rating(std::string rating_val) { rating = rating_val; }
  void set_watched(int watched_val) { watched = watched_val; }

  std::string get_name() const { return name; }
  std::string get_rating() const { return rating; }
  int get_watched() const { return watched; }

  void increment_watched() { ++watched; }

  void display() const;
};

#endif