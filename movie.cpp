#include <iostream>

#include "movie.h"

#include "memtrace.h"

using std::endl;

const string Movie::genre_names[] = {
        "ACTION", "COMEDY", "ROMANCE", "DRAMA", "HORROR",
        "THRILLER", "SCIFI", "CRIME", "WESTERN", "DOCUMENTARY", "FAMILY"
};
Movie_type Movie::type_() const {
    return type;
}
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
    if(new_genre == DOCUMENTARY) {
        type = DOCUMENTARY_MOVIE;
    }
    else if(new_genre == FAMILY) {
        type = FAMILY_MOVIE;
    }
    else {
        type = MOVIE;
    }
}
bool Movie::operator==(const Movie& rhs) const {
    return (*this==rhs);
}
void Movie::write(std::ostream& os) const {
    os << "1.\tCim: " << title << endl;
    os << "2.\tLejatszasi ido: " << playtime << endl;
    os << "3.\tKiadas eve: " << year << endl;
    os << "4.\tMufaj: " << Movie::genre_names[genre] << endl;
}
void Movie::read_from_file(std::ifstream& ifs, char s) {
    ifs  >> s >> title >> s >> playtime >> s >> year >> s\
        >> reinterpret_cast<char*>(genre) >> s;
}
void Movie::write_to_file(std::ofstream& ofs, char s) const{
    ofs << type << s << title << s << playtime << s << year << s << genre << s << endl;
}