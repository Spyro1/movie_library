#include <iostream>

#include "documentary_movie.h"

#include "memtrace.h"

string Documentary_movie::description_() const {
    return description;
}
void Documentary_movie::description_(string new_description) {
    description = new_description;
}
