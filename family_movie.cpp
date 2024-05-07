#include <iostream>

#include "family_movie.h"

#include "memtrace.h"

size_t Family_movie::age_limit_() const {
    return age_limit;
}
void Family_movie::age_limit_(size_t new_age_limit) {
    age_limit = new_age_limit;
}
