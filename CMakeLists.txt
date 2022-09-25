cmake_minimum_required(VERSION 3.23)
project(WSL C)

set(CMAKE_C_STANDARD 99)

add_executable(WSL main.c Card.h Card.c CardList.h CardList.c)
