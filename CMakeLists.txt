cmake_minimum_required(VERSION 3.6)
project(assign3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        assign3.cpp
        Entree.h
        MatchTree.cpp
        MatchTree.h
        Menu.cpp
        Menu.h
        menu1.txt
        menu2.txt
        Node.cpp
        Node.h)

add_executable(assign3 ${SOURCE_FILES})