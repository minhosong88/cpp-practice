#include <iostream>
#include "Movies.h"

using namespace std;

void increment_watched(Movies &movies, string name);
void add_movie(Movies &movies, string name, string rating, int watched);

void increment_watched(Movies &movies, string name)
{
  if (!movies.increment_watched(name))
  {
    std::cout << "No such movie found in the collection" << std::endl;
  }
}

void add_movie(Movies &movies, string name, string rating, int watched)
{
  if (!movies.add_movie(name, rating, watched))
    std::cout << name << " already exists" << std::endl;
}
int main()
{
  Movies my_movies;
  my_movies.display();

  add_movie(my_movies, "Big", "PG-13", 2);
  add_movie(my_movies, "Starwars", "PG", 5);
  add_movie(my_movies, "Cinderella", "PG", 7);
  increment_watched(my_movies, "Starwars");
  increment_watched(my_movies, "Avatar");  // Should display an error
  add_movie(my_movies, "Big", "PG-13", 2); // Should display an error

  cout << endl;
  return 0;
}