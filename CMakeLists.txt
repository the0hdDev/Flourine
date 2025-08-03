cmake_minimum_required(VERSION 3.31)
project(flourine CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(flourc src/main.cpp
        src/lexer.hpp)

configure_file(${CMAKE_SOURCE_DIR}/flourine/main.fl ${CMAKE_BINARY_DIR}/main.fl COPYONLY)
