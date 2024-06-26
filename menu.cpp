#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "menu.h"
#include "family_movie.h"
#include "documentary_movie.h"

#include "memtrace.h"

bool Menu::menu() {
    print_menu();
    Menu_Options menu_num = (Menu_Options)read_number_with_limits(LOG_OUT, LIST_ALL);
    bool run = function_selector(menu_num);
    return run;
}
void Menu::print_start() {
    out << endl << "- - - - Filmtar - - - -" << endl << endl;
    out << "  \tUdvozoljuk!" << endl;
}
void Menu::print_menu() {
    out << endl << ADD << ".\tFilm felvetele" << endl;
    out << EDIT << ".\tFilm modositasa" << endl;
    out << SEARCH << ".\tFilm keresese" << endl;
    out << DELETE << ".\tFilm torlese" << endl;
    out << LIST_ALL << ".\tFilmek listazasa" << endl;
    out << LOG_OUT << ".\tKilepes" << endl << endl;
    out << "Valasztott menupont: " << endl;
}
bool Menu::function_selector(Menu_Options menu_num) {
    int i = 3;
    switch(menu_num) {
    case ADD: {
        while(i==3) {
            i = add_movie();
            if(i==1) return false;
            else if(i==2) return true;
        }
        break;
    }
    case EDIT: {
        while(i==3) {
            i = edit_movie();
            if(i==1) return false;
            else if(i==2) return true;
        }
        break;
    }
    case SEARCH: {
        while(i==3) {
            i = search_movie();
            if(i==1) return false;
            else if(i==2) return true;
        }
        break;
    }
    case DELETE: {
        while(i==3) {
            i = delete_movie();
            if(i==1) return false;
            else if(i==2) return true;
        }
        break;
    }
    case LIST_ALL: {
        while(i==3) {
            i = list_all();
            if(i==1) return false;
            else if(i==2) return true;
        }
        break;
    }
    default:
        log_out(); break;
    }
    return false;
}
int Menu::read_number_with_limits(const int min, const int max, string error_output) const {
    int read;
    std::string helper;
    in.clear();
    while (true) {
        getline(in, helper);
        try{
            read = stoi(helper);
            if (read >= min && read <= max) {
                break;
            }
            else throw "Hibas input.";
        }
        catch (...){
            out << endl << "Hibas input (min: " << min << ", max: " << max << "). " << error_output << ":" << endl;
        }
    }
    in.clear();
    return read;
}
bool Menu::exit_to_main_menu() {
    out << "1.\tVissza a fomenube" << endl;
    out << "2.\tUjraprobalas" << endl;
    out << "Valasztott menupont: " << endl;
    int i = read_number_with_limits(1, 2);
    return i == 1;
}
int Menu::get_current_year() {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    return local_time->tm_year + 1900;
}
bool Menu::valid_string(string s) {
    for(size_t i = 0; i < s.size(); i++) {
        if (s[i] == ';') return false;
        if (!std::isspace(s[i])) return true;
    }
    return false;
}
bool Menu::unique_title(string title) {
    for(size_t i = 0; i < library.size_(); i++) {
        if(library.list_member(i)->title_() == title) return false;
    }
    return true;
}
void Menu::edit_title(Movie* movie) {
    string new_title;
    while(true) {
        out << endl << "Cim:" << endl;
        getline(in, new_title);
        if (!valid_string(new_title))
            out << "Hibas input (legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
        else {
            if (!unique_title(new_title))
                out << "Hibas input (ilyen cimu film mar letezik a nyilvantartasban).";
            else break;
        }
    }
    movie->title_(new_title);
}
void Menu::edit_playtime(Movie* movie) {
    out << "Lejatszasi ido:" <<endl;
    int new_playtime = read_number_with_limits(1, 1000, "Lejatszasi ido");
    movie->playtime_(new_playtime);
}
void Menu::edit_year(Movie* movie) {
    out << "Kiadasi ev:" <<endl;
    int new_year = read_number_with_limits(1888, get_current_year(), "Kiadasi ev");
    movie->year_(new_year);
}
void Menu::edit_genre(Movie* movie) {
    for(int i = 0; i < 11; i++)
        out << i+1 << ".\t" << Movie::genre_names[i] << endl;
    out << "Mufaj:" <<endl;
    Genre new_genre = (Genre)read_number_with_limits(1, 11, "Mufaj");
    movie->genre_(new_genre);
}
void Menu::edit_age_limit(Family_movie* movie) {
    out << "Korhatar:" <<endl;
    int new_age_limit = read_number_with_limits(6, 16, "Korhatar");
    movie->age_limit_(new_age_limit);
}
void Menu::edit_description(Documentary_movie* movie) {
    string new_description;
    while(true) {
        out << endl << "Leiras:" << endl;
        getline(in, new_description);
        if (!valid_string(new_description))
            out << "Hibas input (legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
        else
            break;
    }
    movie->description_(new_description);
}
Movie* Menu::search_title(string title) {
    size_t n = 0;
    string* search_results = nullptr;
    for(size_t i = 0; i < library.size_(); i++) {
        if(title.compare(0, title.size(), library.list_member(i)->title_(), 0, title.size()) == 0) {
            out << n+1 << ".\t" << library.list_member(i)->title_() << endl;
            if(search_results != nullptr) {
                string* temp = new string[n+1];
                for(size_t j = 0; j < n; j++)
                    temp[j] = search_results[j];
                temp[n++] = library.list_member(i)->title_();
                delete[] search_results;
                search_results = temp;
            }
            else {
                search_results = new string[n+1];
                search_results[n++] = library.list_member(i)->title_();
            }
        }
    }
    if(n == 0) {
        out << "Nincs a keresesnek megfelelo film." << endl;
        return nullptr;
    }
    out << "Valasztott film sorszama:" << endl;
    int searched_title = read_number_with_limits(1, (const int)n, "Valasztott film sorszama");
    title = search_results[searched_title-1];
    for(size_t i = 0; i < library.size_(); i++) {
        if(title == library.list_member(i)->title_())
            return library.list_member(i);
    }
    return nullptr;
}
int Menu::add_movie() {
    string title;
    while(true) {
        out << endl << "Film cime: " << endl;
        getline(in, title);
        if(!valid_string(title))
            out << "Hibas input (legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
        else {
            if (!unique_title(title))
                out << "Hibas input (ilyen cimu film mar letezik a nyilvantartasban).";
            else break;
        }
    }
    out << "Film lejatszasi ideje:" << endl;
    int playtime = read_number_with_limits(1, 1000, "Film lejatszasi ideje");
    out << "Film kiadasi eve:" << endl;
    int release_year = read_number_with_limits(1888, get_current_year(), "Film kiadasi eve");
    for(int i = 0; i < 11; i++)
        out << i+1 << ".\t" << Movie::genre_names[i] << endl;
    out << "Film mufaja:" << endl;
    Genre genre = (Genre)(read_number_with_limits(1, 11,  "Film mufaja")-1);
    if(genre == 9) {
        string description;
        while(true) {
            out << endl << "Film rovid leirasa:" << endl;
            getline(in, description);
            if(!valid_string(description))
                out << "Hibas input (legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
            else
                break;
        }
        Documentary_movie* new_movie = new Documentary_movie(DOCUMENTARY_MOVIE, title, playtime, release_year,\
                                                             genre, description);
        library.add(new_movie);
    }
    else if(genre == 10) {
        out << "Film korhatara:" << endl;
        int age_limit = read_number_with_limits(6, 16, "Film korhatara");
        Family_movie* new_movie = new Family_movie(FAMILY_MOVIE, title, playtime, release_year, genre,\
                                                   age_limit);
        library.add(new_movie);
    }
    else {
        Movie* new_movie = new Movie(MOVIE, title, playtime, release_year, genre);
        library.add(new_movie);
    }
    std::ofstream ofs ("movie_library.txt");
    library.write_to_file(ofs, ';');
    ofs.close();
    out << endl << "Sikeresen felvett film." << endl;
    return 2;
}
int Menu::edit_movie() {
    if(library.size_() == 0) {
        out << "Nincs felvett film." << endl;
        return 2;
    }
    string title;
    out << endl << "Film cime (vagy cimenek kezdete): " << endl;
    getline(in, title);
    Movie* searched_movie = search_title(title);
    if(!searched_movie) {
         if(exit_to_main_menu()) return 2;
         return 3;
    }
    if(searched_movie->type_() == DOCUMENTARY_MOVIE) ((Documentary_movie*)searched_movie)->write(out);
    else if(searched_movie->type_() == FAMILY_MOVIE) ((Family_movie*)searched_movie)->write(out);
    else searched_movie->write(out);
    out << "Modositando adat sorszama:" << endl;
    int editable_data;
    if(searched_movie->type_() == DOCUMENTARY_MOVIE) {
        editable_data = read_number_with_limits(1, 5, "Modositando adat sorszama");
        switch(editable_data) {
        case 1:
            edit_title(searched_movie); break;
        case 2:
            edit_playtime(searched_movie); break;
        case 3:
            edit_year(searched_movie); break;
        case 4:
            edit_genre(searched_movie); break;
        case 5:
            edit_description((Documentary_movie*)searched_movie); break;
        default:
            return 1;
        }
    }
    else if(searched_movie->type_() == FAMILY_MOVIE) {
        editable_data = read_number_with_limits(1, 5, "Modositando adat sorszama");
        switch(editable_data) {
            case 1:
                edit_title(searched_movie); break;
            case 2:
                edit_playtime(searched_movie); break;
            case 3:
                edit_year(searched_movie); break;
            case 4:
                edit_genre(searched_movie); break;
            case 5:
                edit_age_limit((Family_movie*)searched_movie); break;
            default:
                return 1;
        }
    }
    else {
        editable_data = read_number_with_limits(1, 4, "Modositando adat sorszama");
        switch(editable_data) {
            case 1:
                edit_title(searched_movie); break;
            case 2:
                edit_playtime(searched_movie); break;
            case 3:
                edit_year(searched_movie); break;
            case 4:
                edit_genre(searched_movie); break;
            default:
                return 1;
        }
    }
    std::ofstream ofs ("movie_library.txt");
    library.write_to_file(ofs, ';');
    ofs.close();
    out << endl << "Sikeresen modositott film." << endl;
    return 2;
}
int Menu::search_movie() {
    if(library.size_() == 0) {
        out << "Nincs felvett film." << endl;
        return 2;
    }
    out << endl << "1.\tCim szerinti kereses" << endl;
    out << "2.\tMufaj szerinti kereses" << endl;
    out << "Valasztott menupont:" << endl;
    int search_type = read_number_with_limits(1, 2);
    Movie* searched_movie = nullptr;
    if(search_type == 1) {
        string title;
        out << endl << "Film cime (vagy cimenek kezdete):" << endl;
        getline(in, title);
        searched_movie = search_title(title);
    }
    else {
        for(int i = 0; i < 11; i++)
            out << i+1 << ".\t" << Movie::genre_names[i] << endl;
        out << "Film mufaja:" << endl;
        Genre genre = (Genre)(read_number_with_limits(1, 11,  "Film mufaja")-1);
        int n = 0;
        string* search_results = nullptr;
        for(size_t i = 0; i < library.size_(); i++) {
            if(library.list_member(i)->genre_() == genre) {
                out << n+1 << ".\t" << library.list_member(i)->title_() << endl;
                if(search_results != nullptr) {
                    string* temp = new string[n+1];
                    for(int j = 0; j < n; j++)
                        temp[j] = search_results[j];
                    temp[n++] = library.list_member(i)->title_();
                    delete[] search_results;
                    search_results = temp;
                }
                else {
                    search_results = new string[n+1];
                    search_results[n++] = library.list_member(i)->title_();
                }
            }
        }
        if(n == 0) {
            out << "Nincs a keresesnek megfelelo film." << endl;
            return 2;
        }
        out << "Valasztott film sorszama:" << endl;
        int searched_title = read_number_with_limits(1, (const int)n, "Valasztott film sorszama");
        string title = search_results[searched_title-1];
        for(size_t i = 0; i < library.size_(); i++) {
            if(title == library.list_member(i)->title_())
                searched_movie = library.list_member(i);
        }
    }
    if(!searched_movie) {
        if(exit_to_main_menu()) return 2;
        return 3;
    }
    if(searched_movie->type_() == DOCUMENTARY_MOVIE) ((Documentary_movie*)searched_movie)->write(out);
    else if(searched_movie->type_() == FAMILY_MOVIE) ((Family_movie*)searched_movie)->write(out);
    else searched_movie->write(out);
    return 2;
}
int Menu::delete_movie() {
    if(library.size_() == 0) {
        out << "Nincs felvett film." << endl;
        return 2;
    }
    string title;
    out << endl << "Film cime (vagy cimenek kezdete):" << endl;
    getline(in, title);
    Movie* searched_movie = search_title(title);
    if(!searched_movie) {
        if(exit_to_main_menu()) return 2;
        return 3;
    }
    library.del(searched_movie);
    std::ofstream ofs ("movie_library.txt");
    library.write_to_file(ofs, ';');
    ofs.close();
    out << endl << "Sikeresen torolt film." << endl;
    return 2;
}
int Menu::list_all() {
    out << endl;
    if(library.size_() == 0) {
        out << "Nincs felvett film." << endl;
        return 2;
    }
    int j = 1;
    for(int i = (int)library.size_()-1; i >= 0; i--)
        out << j++ << ".\t" << library.list_member(i)->title_() << endl;
    return 2;
}
int Menu::log_out() const {
    out << endl << "Viszontlatasra!" << endl;
    return 1;
}
