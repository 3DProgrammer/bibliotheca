cmake_minimum_required(VERSION 3.21)
project(bibliotheca)
set(BIBLIOTHECA_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 20)
add_library(bibliotheca bibliotheca.cpp word.cpp)
target_include_directories(bibliotheca PRIVATE ${BIBLIOTHECA_INCLUDE_DIRS})
add_executable(test test.cpp)
target_link_libraries(test bibliotheca)
target_include_directories(test PRIVATE ${BIBLIOTHECA_INCLUDE_DIRS})
add_custom_target(doc
        COMMAND doxygen
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})