cmake_minimum_required(VERSION 3.28)
project(duokernel)

set(CMAKE_CXX_STANDARD 17)

add_executable(duokernel shell.h
        main.cpp)
