#include <iostream>

#include "library.h"

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
