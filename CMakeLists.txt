cmake_minimum_required(VERSION 3.20)
project(flourine CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(flourc src/main.cpp
        src/tokenizer.hpp)

configure_file(${CMAKE_SOURCE_DIR}/flourine/main.fl ${CMAKE_BINARY_DIR}/main.fl COPYONLY)
