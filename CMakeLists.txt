cmake_minimum_required(VERSION 3.28)
project(movie_library)

set(CMAKE_CXX_STANDARD 11)

add_executable(movie_library main.cpp
        documentary_movie.cpp
        documentary_movie.h
        family_movie.cpp
        family_movie.h
        gtest_lite.h
        library.cpp
        library.h
        list.hpp
        memtrace.cpp
        memtrace.h
        menu.cpp
        menu.h
        movie.cpp
        movie.h
        serializable.h
)

add_compile_definitions(MEMTRACE)
#add_compile_definitions(CPORTA)

add_compile_options(movie_library PRIVATE -Wall -Werror)