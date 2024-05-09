cmake_minimum_required(VERSION 3.28)
project(movie_library)

set(CMAKE_CXX_STANDARD 11)

add_executable(movie_library main.cpp
documentary_movie.cpp
documentary_movie.h
family_movie.cpp
family_movie.h
interface.cpp
interface.h
library.cpp
library.h
list.hpp
log_out.cpp
log_out.h
movie.cpp
movie.h
memtrace.cpp
memtrace.h
gtest_lite.h)

add_compile_definitions(MEMTRACE)
#add_compile_definitions(CPORTA)

add_compile_options(movie_library PRIVATE -Wall -Werror)