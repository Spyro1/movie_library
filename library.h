#ifndef TAR_H_INCLUDED
#define TAR_H_INCLUDED
#include "movie.h"
#include "list.hpp"

class Library {
private:
    size_t size;
    List<Movie*> list;
public:
    Library(size_t siz = 0) : size(siz) {}
    size_t size_() const;
    Movie* list_member(size_t i = 0);
    void add(Movie* new_movie);
    void del(Movie* delete_movie);
    //~Library();
};

#endif // TAR_H_INCLUDED
