cmake_minimum_required(VERSION 3.26)
project(StringClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(StringClass main.cpp
        String.cpp
        String.h
        Ui.cpp
        Ui.h)
