#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include "serializable.h"

#include "memtrace.h"

using std::string;

enum Genre {
ACTION, COMEDY, ROMANCE, DRAMA, HORROR, THRILLER, SCIFI, CRIME, WESTERN, DOCUMENTARY, FAMILY
};
enum Movie_type {
MOVIE, DOCUMENTARY_MOVIE, FAMILY_MOVIE
};

class Movie : public Serializable {
protected:
    Movie_type type;
    string title;
    size_t playtime;
    size_t year;
    Genre genre;
public:
    static const string genre_names[];
    Movie(Movie_type ty = MOVIE, string t = "", size_t p = 0, size_t y = 0, Genre g = ACTION) : type(ty),\
          title(t), playtime(p), year(y), genre(g) {}
    Movie_type type_() const;
    string title_() const;
    size_t playtime_() const;
    size_t year_() const;
    Genre genre_() const;
    void title_(string new_title);
    void playtime_(size_t new_playtime);
    void year_(size_t new_year);
    void genre_(Genre new_genre);
    bool operator==(const Movie& rhs) const;
    void write(std::ostream& os) const;
    void read_from_file(std::ifstream& ifs, char s);
    void write_to_file(std::ofstream& ofs, char s) const;
};

#endif // FILM_H_INCLUDED
