cmake_minimum_required(VERSION 3.29)
project(Fee_Manage)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fee_Manage main.cpp
        Header.h
        System.cpp
        System.h
        Admini.cpp
        Admini.h
        Resident.cpp
        Resident.h
        Opera.cpp
        Opera.h
)
