cmake_minimum_required(VERSION 3.20)
project(flourine CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(flourc core/main.cpp
        lexer/tokenizer.hpp
        lexer/lexer_main.cpp
        parsing/parsing_main.cpp
        parsing/parsing_main.h)

configure_file(${CMAKE_SOURCE_DIR}/flourine/main.fl ${CMAKE_BINARY_DIR}/main.fl COPYONLY)
