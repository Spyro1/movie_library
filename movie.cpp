#include <iostream>

#include "movie.h"

#include "memtrace.h"

string Movie::title_() const {
    return title;
}
size_t Movie::playtime_() const {
    return playtime;
}
size_t Movie::year_() const {
    return year;
}
Genre Movie::genre_() const {
    return genre;
}
void Movie::title_(string new_title) {
    title = new_title;
}
void Movie::playtime_(size_t new_playtime) {
    playtime = new_playtime;
}
void Movie::year_(size_t new_year) {
    year = new_year;
}
void Movie::genre_(Genre new_genre) {
    genre = new_genre;
}
bool Movie::operator==(const Movie& rhs) const {
    return (*this==rhs);
}