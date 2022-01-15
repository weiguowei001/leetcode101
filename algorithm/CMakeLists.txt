cmake_minimum_required(VERSION 3.10.0)

project(leetcode101)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# leetcode101 sources
include(cmake/leetcode101-search.cmake)
include(cmake/leetcode101-sort.cmake)

set(leetcode101_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${LEETCODE101_SEARCH_SOURCES}
    ${LEETCODE101_SORT_SOURCES}
    )

add_executable(leetcode101 ${leetcode101_SOURCES})

###########################################################
# TESTS
###########################################################

add_subdirectory(tests)