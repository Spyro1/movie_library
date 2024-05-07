#ifndef TAR_H_INCLUDED
#define TAR_H_INCLUDED

#include "movie.h"
#include "list.hpp"

class Library {
private:
    size_t size;
    List<Movie> list;
public:
    Library(size_t siz = 0) : size(siz) {}
    void add(Movie& new_movie);
    void edit(string title);
    Movie* search(Genre genre) const;
    Movie* search(std::string title) const;
    Movie* search(int year) const;
    void del(Movie& delete_movie);
    void list_all() const;
    ~Library();
};

#endif // TAR_H_INCLUDED
