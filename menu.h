#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "library.h"
#include "documentary_movie.h"
#include "family_movie.h"

#include "memtrace.h"

using std::endl;

enum Menu_Options {
    LOG_OUT, ADD, EDIT, SEARCH, DELETE, LIST_ALL
};
class Menu {
    Library library;
    std::ostream& out;
    std::istream& in;
public:
    Menu(Library l, std::ostream& o = std::cout, std::istream& i = std::cin) : library(l), out(o), in(i) {}
    bool menu();
    void print_start();
    void print_menu();
    bool function_selector(Menu_Options menu_num);
    int read_number_with_limits(const int min, const int max, string error_output = "Valasztott menupont") const;
    bool exit_to_main_menu();
    static int get_current_year();
    static bool valid_string(string s);
    bool unique_title(string title);
    void edit_title(Movie* movie);
    void edit_playtime(Movie* movie);
    void edit_year(Movie* movie);
    void edit_genre(Movie* movie);
    void edit_age_limit(Family_movie* movie);
    void edit_description(Documentary_movie* movie);
    Movie* search_title(string title);
    int add_movie();
    int edit_movie();
    int search_movie();
    int delete_movie();
    int list_all();
    int log_out() const ;
};

#endif // INTERFACE_H_INCLUDED
