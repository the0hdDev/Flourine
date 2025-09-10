cmake_minimum_required(VERSION 3.16)
project(flourine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lexer)
add_subdirectory(util)
add_subdirectory(parsing)
add_subdirectory(core)

configure_file(${CMAKE_SOURCE_DIR}/flourine/main.fl ${CMAKE_BINARY_DIR}/main.fl COPYONLY)

target_include_directories(flourine PRIVATE
        ${CMAKE_SOURCE_DIR}
)