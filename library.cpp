#include <iostream>

#include "library.h"

#include "memtrace.h"

using std::cout;
using std::endl;

size_t Library::size_() const {
    return size;
}
Movie& Library::list_member(int i) {
    return list[i];
}
void Library::add(Movie& new_movie) {
    list.add(new_movie);
    size++;
}

void Library::del(Movie& delete_movie) {
    //list.del(delete_movie);
}
void Library::list_all() const {
    /*List<Movie>::iterator i;
    for(i = list.begin(); i != list.end(); i++) {

    }*/
}
/*Library::~Library() {

}*/
