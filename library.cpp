#include <iostream>

#include "library.h"
#include "documentary_movie.h"
#include "family_movie.h"

#include "memtrace.h"

size_t Library::size_() const {
    return size;
}
Movie* Library::list_member(size_t i) {
    try {
        return list[i];
    }
    catch(...) {
        return nullptr;
    }
}
void Library::add(Movie* new_movie) {
    list.add(new_movie);
    size++;
}
void Library::del(Movie* delete_movie) {
    list.del(delete_movie);
    size--;
}
void Library::read_from_file(std::ifstream& ifs, char s) {
    char movie_type;
    for(size_t i = 0; i < size_(); i++) {
        ifs >> movie_type;
        if(movie_type == 0) {
            Movie* new_movie = new Movie(MOVIE);
            new_movie->read_from_file(ifs, ';');
            add(new_movie);
        }
        else if(movie_type == 1) {
            Documentary_movie* new_movie = new Documentary_movie(DOCUMENTARY_MOVIE);
            new_movie->read_from_file(ifs, ';');
            add(new_movie);
        }
        else {
            Family_movie* new_movie = new Family_movie(FAMILY_MOVIE);
            new_movie->read_from_file(ifs, ';');
            add(new_movie);
        }
    }
}
void Library::write_to_file(std::ofstream& ofs, char s) {
    for(size_t i = 0; i < size_(); i++) {
        list_member(i)->write_to_file(ofs, ';');
    }
}
