#ifndef DOCUMENTARY_MOVIE_H_INCLUDED
#define DOCUMENTARY_MOVIE_H_INCLUDED

#include "serializable.h"
#include "movie.h"

#include "memtrace.h"

class Documentary_movie : public Movie {
    string description;
public:
    Documentary_movie(Movie_type ty = DOCUMENTARY_MOVIE, string t = "", size_t p = 0, size_t y = 0,\
                      Genre g = DOCUMENTARY, string d = "") : Movie(ty, t, p, y, g), description(d) {}
    string description_() const;
    void description_(string new_description);
    void write(std::ostream& os) const;
    void read_from_file(std::ifstream& ifs, char s);
    void write_to_file(std::ofstream& ofs, char s) const;
};

#endif // DOCUMENTARY_MOVIE_H_INCLUDED
