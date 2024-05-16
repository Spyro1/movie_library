#ifndef TAR_H_INCLUDED
#define TAR_H_INCLUDED

#include "movie.h"
#include "list.hpp"

#include "memtrace.h"

class Library {
    List<Movie*> list;
    size_t size;
public:
    Library() : list(), size(list.size_()) {}
    size_t size_() const;
    Movie* list_member(size_t i = 0);
    void add(Movie* new_movie);
    void del(Movie* delete_movie);
};

#endif // TAR_H_INCLUDED
