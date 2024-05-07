#include <iostream>
#include <string>
#include <fstream>

#include "interface.h"
#include "log_out.h"

#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

bool menu() {
    print_menu();
    int menu_num = -1;
    menu_num = read_number_with_limits(LOG_OUT, LIST_ALL);
    bool run = function_selector(menu_num);
    return run;
}

void print_start() {
    cout << endl << "- - - - Filmtar - - - -" << endl << endl;
    cout << "  \tUdvozoljuk!" << endl << endl;
}

void print_menu() {
    cout << ADD << ".\tFilm felvetele" << endl;
    cout << EDIT << ".\tFilm modositasa" << endl;
    cout << SEARCH << ".\tFilm keresese" << endl;
    cout << DELETE << ".\tFilm torlese" << endl;
    cout << LIST_ALL << ".\tFilmek listazasa" << endl;
    cout << LOG_OUT << ".\tKilepes" << endl << endl;
    cout << "Valasztott menupont: " << endl;
}

bool function_selector(int menu_num) {
    bool run;
    switch(menu_num) {
    case 0:
        run = log_out(); break;
    /*case 1:
        run = ; break;
    case 2:
        run = ; break;
    case 3:
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
int read_number_with_limits(const Menu_Options min, const Menu_Options max) {
    int read;
    while (true) {
        if (std::cin >> read) {
            break;
        } else {
            //std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << endl << "Hibas input (min: " << min << ", max: " << max << "). Valasztott menupont: ";
        }
    }
    return read;
}
