#include <iostream>

#include "documentary_movie.h"

#include "memtrace.h"

using std::endl;

string Documentary_movie::description_() const {
    return description;
}
void Documentary_movie::description_(string new_description) {
    description = new_description;
}
void Documentary_movie::write(std::ostream& os) const {
    os << "1.\tCim: " << title_() << endl;
    os << "2.\tLejatszasi ido: " << playtime_() << endl;
    os << "3.\tKiadas eve: " << year_() << endl;
    os << "4.\tMufaj: " << Movie::genre_names[genre_()] << endl;
    os << "5.\tRovid leiras: " << description << endl;
}
void Documentary_movie::read_from_file(std::ifstream& ifs, char s) {
    char i;
    ifs >> s;
    while(ifs >> i && i != s) {
        title += i;
    }
    int g;
    ifs >> playtime >> i >> year >> i >> g >> i;
    genre = (Genre)g;
    while(ifs >> i && i != s) {
        description += i;
    }
}
void Documentary_movie::write_to_file(std::ofstream& ofs, char s) const {
    ofs << type << s << title << s << playtime << s << year << s << genre << s << description << s << endl;
}