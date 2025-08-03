cmake_minimum_required(VERSION 3.31)
project(flourine C)

set(CMAKE_C_STANDARD 23)

add_executable(flourc src/main.c
        src/lexer.h)

configure_file(${CMAKE_SOURCE_DIR}/flourine/main.fl ${CMAKE_BINARY_DIR}/main.fl COPYONLY)
