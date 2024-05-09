#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstring>

#include "menu.h"
#include "family_movie.h"
#include "documentary_movie.h"

#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool Menu::menu() {
    print_menu();
    int menu_num = read_number_with_limits(LOG_OUT, LIST_ALL);
    bool run = function_selector(menu_num);
    return run;
}
void Menu::print_start() {
    cout << endl << "- - - - Filmtar - - - -" << endl << endl;
    cout << "  \tUdvozoljuk!" << endl;
}
void Menu::print_menu() {
    cout << endl << ADD << ".\tFilm felvetele" << endl;
    cout << EDIT << ".\tFilm modositasa" << endl;
    cout << SEARCH << ".\tFilm keresese" << endl;
    cout << DELETE << ".\tFilm torlese" << endl;
    cout << LIST_ALL << ".\tFilmek listazasa" << endl;
    cout << LOG_OUT << ".\tKilepes" << endl << endl;
    cout << "Valasztott menupont: " << endl;
}
bool Menu::function_selector(int menu_num) {
    bool run;
    switch(menu_num) {
    case 0:
        run = log_out(); break;
    case 1:
        run = add_movie(); break;
    case 2:
        run = edit_movie(); break;
    /*case 3:
        run = ; break;
    case 4:
        run = ; break;
    case 5:
        run = ; break;*/
    default:
        break;
    }
    return run;
}
int Menu::read_number_with_limits(const int min, const int max) {
    int read;
    std::cin.clear();
    while (true) {
        if (std::cin >> read && read >= min && read <= max) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << endl << "Hibas input (min: " << min << ", max: " << max << "). Valasztott menupont: ";
        }
    }
    return read;
}
int Menu::get_current_year() {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    return local_time->tm_year + 1900;
}
bool Menu::valid_string(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ';')
            return false;
        if (!std::isspace(s[i]))
            return true;
    }
    return false;
}
bool Menu::add_movie() {
    string title;
    while(true) {
        cout << endl << "Film cime: " << endl;
        cin >> title;
        if(!valid_string(title))
            cout << "Hibas input (Legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
        else
            break;
    }
    cout << "Film lejatszasi ideje: " << endl;
    int playtime = read_number_with_limits(1, 1000);
    cout << "Film kiadasi eve: " << endl;
    int release_year = read_number_with_limits(1888, get_current_year());
    const std::string genre_names[] = {
    "ACTION", "COMEDY", "ROMANCE", "DRAMA", "HORROR",
    "THRILLER", "SCIFI", "CRIME", "WESTERN", "DOCUMENTARY", "FAMILY"};
    for(int i = 0; i < 11; i++)
        cout << i+1 << ".\t" << genre_names[i] << endl;
    cout << "Film mufaja: " << endl;
    Genre genre = static_cast<Genre>(read_number_with_limits(1, 11));
    if(genre == 10) {
        string description;
        while(true) {
            cout << endl << "Film rovid leirasa: " << endl;
            cin >> description;
            if(!valid_string(description))
                cout << "Hibas input (Legalabb 1 - szokoztol kulonbozo - karakter, nem tartalmazhat ';' karaktert).";
            else
                break;
        }
        Documentary_movie new_movie(title, playtime, release_year, genre, description);
        library.add(new_movie);
    }
    else if(genre == 11) {
        cout << "Film korhatara: ";
        int age_limit = read_number_with_limits(6, 16);
        Family_movie new_movie(title, playtime, release_year, genre, age_limit);
        library.add(new_movie);
    }
    else {
        Movie new_movie(title, playtime, release_year, genre);
        library.add(new_movie);
    }
    cout << endl << "Sikeresen felvett film." << endl;
    return true;
}
bool Menu::edit_movie() {
    string title;
    cout << endl << "Film cime (vagy cimenek kezdete): " << endl;
    cin >> title;
    int j = 0;
    for(size_t i = 0; i < library.size_(); i++) {
        if(std::strncmp(title.c_str(), library.list_member().title_().c_str(), title.size()) == 0)
            cout << ++j << ".\t" << library.list_member().title_();
    }
    if(j == 0) cout << "Nincs a keresesnek megfelelo film." << endl;
    return true;
}
bool Menu::log_out() {
    cout << endl << "Viszontlatasra!" << endl;
    return false;
}
