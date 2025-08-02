cmake_minimum_required(VERSION 3.31)
project(tlangc C)

set(CMAKE_C_STANDARD 23)

add_executable(T src/main.c
        src/lexer.h)

configure_file(${CMAKE_SOURCE_DIR}/tlang/main.tlg ${CMAKE_BINARY_DIR}/main.tlg COPYONLY)
