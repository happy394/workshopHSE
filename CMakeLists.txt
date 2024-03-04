cmake_minimum_required(VERSION 3.0)
project(titanic)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        titanic.h
        titanic.cpp obesity.cpp obesity.h)