cmake_minimum_required(VERSION 3.21)
project(bibliotheca)

set(CMAKE_CXX_STANDARD 20)
add_library(bibliotheca bibliotheca.cpp)
target_include_directories(bibliotheca PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)