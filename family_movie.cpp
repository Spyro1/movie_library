#include <iostream>

#include "family_movie.h"

#include "memtrace.h"

using std::endl;

size_t Family_movie::age_limit_() const {
    return age_limit;
}
void Family_movie::age_limit_(size_t new_age_limit) {
    age_limit = new_age_limit;
}
void Family_movie::write(std::ostream& os) const {
    os << "1.\tCim: " << title_() << endl;
    os << "2.\tLejatszasi ido: " << playtime_() << endl;
    os << "3.\tKiadas eve: " << year_() << endl;
    os << "4.\tMufaj: " << Movie::genre_names[genre_()] << endl;
    os << "5.\tKorhatar: " << age_limit << endl;
}
void Family_movie::read_from_file(std::ifstream& ifs, char s) {
    char i;
    ifs >> i;
    while(ifs.get(i) && i != s) { // a >> leveszi a spaceket, helyette get
        title += i;
    }
    int g;
    ifs >> playtime >> i >> year >> i >> g >> i >> age_limit >> i;
    genre = (Genre)g;
}
void Family_movie::write_to_file(std::ofstream& ofs, char s) const {
    ofs << type << s << title << s << playtime << s << year << s << genre << s << age_limit << s << endl;
}