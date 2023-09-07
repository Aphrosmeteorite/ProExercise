cmake_minimum_required(VERSION 3.26)
project(StringClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(StringClass main.cpp
        String.cpp
        String.h
        Ui.cpp
        Ui.h)

# you can add some test to test the code.
enable_testing()

# for example(not use!)
# add_test(NAME Usage COMMAND StringClass)
# set_tests_properties(Usage
#   PROPERTIES PASS_REGULAR_EXPRESSION 
#   "Usage:
#   *************************************
#   *         choose a method           *
#   *  A.create a string(less than 10)  *
#   *  B.show all the strings           *
#   *  C.connect two strings            *
#   *  D.length of which string         *
#   *  E.copy a string to another       *
#   *  F.compare two strings            *
#   *  M.open the Menu                  *
#   *  N.clear the string made before   *
#   *  Q.escape                         *
#   *************************************
#   Wait for choosing......

#   "
#   )