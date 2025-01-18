#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <limits>
#include <vector>

class Song
{
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;

public:
  Song() = default;
  Song(std::string name, std::string artist, int rating) : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() const
  {
    return name;
  }
  std::string get_artist() const
  {
    return artist;
  }
  int get_rating() const
  {
    return rating;
  }

  bool operator<(const Song &rhs) const
  {
    return this->name < rhs.name;
  }

  bool operator==(const Song &rhs) const
  {
    return this->name == rhs.name;
  }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
  os << std::setw(20) << std::left << s.name << std ::setw(30) << std::left << s.artist << std::setw(2) << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu()
{
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next Song" << std::endl;
  std::cout << "P - Play Previous Song" << std::endl;
  std::cout << "A - Add and Play a new Song at current location" << std::endl;
  std::cout << "L - List the current Playlist" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << "Enter a selection(Q to quit): ";
}

void play_current_song(const Song &song)
{
  std::cout << "Playing...\n"
            << song << std::endl;
}
void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
  for (const auto &song : playlist)
    std::cout << song << std::endl;
  std::cout << "Current Song: \n"
            << current_song << std::endl;
}
int main()
{
  std::list<Song> playlist{
      {"Song1", "Artist1", 5},
      {"Song2", "Artist2", 5},
      {"Song3", "Artist3", 5},
      {"Song4", "Artist4", 5},
      {"Song5", "Artist5", 5}};

  std::list<Song>::iterator current_song = playlist.begin();

  char selection{};
  display_playlist(playlist, *current_song);
  do
  {
    display_menu();
    std::cin >> selection;
    selection = toupper(selection);
    switch (selection)
    {
    case 'F':
    {
      std::cout << "Playing first song:" << std::endl;
      current_song = playlist.begin();
      play_current_song(*current_song);
      break;
    }
    case 'N':
    {
      std::cout << "Playing Next song:" << std::endl;

      if (std::next(current_song) != playlist.end())
        std::advance(current_song, 1);
      else
        current_song = playlist.begin();
      play_current_song(*current_song);
      break;
    }
    case 'P':
    {
      std::cout << "Playing Previous song:" << std::endl;

      if (current_song != playlist.begin())
        std::advance(current_song, -1);
      else
        current_song = std::prev(playlist.end());

      play_current_song(*current_song);
      break;
    }
    case 'A':
    {
      std::cout << "Adding and playing new song" << std::endl;
      std::string name{"unknown song"};
      std::string artist{"unknown artist"};
      int rating{0};
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter the name of the new song: ";
      std::cin >> name;
      std::cout << "Enter the artist of the new song: ";
      std::cin >> artist;
      std::cout << "Enter the rating of the new song: ";
      std::cin >> rating;
      playlist.emplace(current_song, name, artist, rating);
      std::advance(current_song, -1);
      play_current_song(*current_song);
      break;
    }
    case 'L':
    {
      display_playlist(playlist, *current_song);
      break;
    }
    case 'Q':
    {
      std::cout << "Quitting..." << std::endl;
      break;
    }
    default:
      std::cout << "Unknown selection, please try again" << std::endl;
    }

  } while (selection != 'Q');
  std::cout
      << "Thanks for listening" << std::endl;

  return 0;
}