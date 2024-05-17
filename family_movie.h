#ifndef FAMILY_MOVIE_H_INCLUDED
#define FAMILY_MOVIE_H_INCLUDED

#include "serializable.h"
#include "movie.h"

#include "memtrace.h"

class Family_movie : public Movie {
    size_t age_limit;
public:
    Family_movie(Movie_type ty = FAMILY_MOVIE, string t = "", size_t p = 0, size_t y = 0,\
                 Genre g = FAMILY, size_t a = 0) : Movie(ty, t, p, y, g), age_limit(a) {}
    size_t age_limit_() const;
    void age_limit_(size_t new_age_limit);
    void write(std::ostream& os) const;
    void read_from_file(std::ifstream& ifs, char s);
    void write_to_file(std::ofstream& ofs, char s) const;
};

#endif // FAMILY_MOVIE_H_INCLUDED
