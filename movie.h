#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

using std::string;

enum Genre {
ACTION, COMEDY, ROMANCE, DRAMA, HORROR, THRILLER, SCIFI, CRIME, WESTERN, DOCUMENTARY, FAMILY
};
enum Movie_type {
MOVIE, DOCUMENTARY_MOVIE, FAMILY_MOVIE
};

class Movie {
private:
    Movie_type type;
    string title;
    size_t playtime;
    size_t year;
    Genre genre;
public:
    Movie(Movie_type ty = MOVIE, string t = "", size_t p = 0, size_t y = 0, Genre g = ACTION) : type(ty), title(t), playtime(p), year(y), genre(g) {}
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
};

#endif // FILM_H_INCLUDED
