#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "library.h"
#include "documentary_movie.h"
#include "family_movie.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::cerr;
using std::ofstream;
using std::ifstream;

enum Menu_Options {
    LOG_OUT,
    ADD,
    EDIT,
    SEARCH,
    DELETE,
    LIST_ALL
};

class Menu {
private:
    Library library;
    std::ostream& out;
    std::istream& in;
public:
    Menu(Library l, std::ostream& o = std::cout, std::istream& i = std::cin) : library(l), out(o), in(i) {}
    bool menu();
    void print_start();
    void print_menu();
    bool function_selector(int menu_num);
    int read_number_with_limits(const int min, const int max);
    static int get_current_year();
    static bool valid_string(string s);
    void edit_title(Movie& movie);
    void edit_playtime(Movie& movie);
    void edit_year(Movie& movie);
    void edit_genre(Movie& movie);
    void edit_age_limit(Family_movie& movie);
    void edit_description(Documentary_movie& movie);
    Movie& search_title(string title);
    bool add_movie();
    bool edit_movie();
    bool search_movie();
    bool delete_movie();
    bool list_all() const ;
    bool log_out() const ;
};

#endif // INTERFACE_H_INCLUDED
