#ifndef DOCUMENTARY_MOVIE_H_INCLUDED
#define DOCUMENTARY_MOVIE_H_INCLUDED

#include "movie.h"

class Documentary_movie : public Movie {
private:
    string description;
public:
    Documentary_movie(Movie_type ty = DOCUMENTARY_MOVIE, string t = "", size_t p = 0, size_t y = 0,\
                      Genre g = DOCUMENTARY, string d = "") : Movie(ty, t, p, y, g), description(d) {}
    string description_() const;
    void description_(string new_description);
};

#endif // DOCUMENTARY_MOVIE_H_INCLUDED
