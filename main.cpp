#include <iostream>

#include "gtest_lite.h"

#include "menu.h"
#include "library.h"

#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

//#define CPORTA

int main() {
    #ifdef CPORTA

    TEST(declaration, d) {
        EXPECT_NO_THROW(Movie m1);
        EXPECT_NO_THROW(Documentary_movie d1);
        EXPECT_NO_THROW(Family_movie f1);
        EXPECT_NO_THROW(List<int> l);
        EXPECT_NO_THROW(List<Movie> list);
        EXPECT_NO_THROW(Library library);
    } END
    TEST(movie_member_functions, mmf) {
        Movie m1;
        EXPECT_STREQ("val", m1.title_().c_str());
        EXPECT_EQ(1, (int)m1.playtime_());
        EXPECT_EQ(1, (int)m1.year_());
        EXPECT_EQ(ACTION, m1.genre_());
    } END
    TEST(documentary_movie_member_functions, dmmf) {
        Documentary_movie d1;
        EXPECT_STREQ("val", d1.description_().c_str());
    } END
    TEST(family_movie_member_functions, fmmf) {
        Family_movie f1;
        EXPECT_EQ(1, (int)f1.age_limit_());
    } END
    TEST(list_member_functions, fmmf) {
        Movie m1;
        Documentary_movie d1;
        Family_movie f1;
        List<Movie> list;
        EXPECT_NO_THROW(list.add(m1));
        EXPECT_NO_THROW(list.add(d1));
        EXPECT_NO_THROW(list.add(f1));
        EXPECT_NO_THROW(list.del(m1));
        EXPECT_NO_THROW(list.search(d1));
    } END
    TEST(library_member_functions, fmmf) {
        Movie m1;
        Documentary_movie d1;
        Family_movie f1;
        Library library;
        EXPECT_NO_THROW(library.add(m1));
        EXPECT_NO_THROW(library.add(d1));
        EXPECT_NO_THROW(library.add(f1));
        EXPECT_NO_THROW(library.del(d1));
        EXPECT_NO_THROW(library.search(m1.title_()));
        EXPECT_NO_THROW(library.search(m1.title_()));
        EXPECT_NO_THROW(library.edit(f1.title_()));
        EXPECT_NO_THROW(library.list_all());
    } END
    #endif // CPORTA

    #ifndef CPORTA

    Library library;
    Menu m(library);
    m.print_start();
    bool run = true;
    while(run) {
        run = m.menu();
    }
    return 0;

    #endif // CPORTA
}
