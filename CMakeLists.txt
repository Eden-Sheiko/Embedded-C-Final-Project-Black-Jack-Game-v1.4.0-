cmake_minimum_required(VERSION 3.16)
project(wsl_black_jack_C99 C)

set(CMAKE_C_STANDARD 99)

add_executable(wsl_black_jack_C99 main.c Card.h CardList.h Card.c CardList.c)
