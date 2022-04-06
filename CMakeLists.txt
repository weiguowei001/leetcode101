cmake_minimum_required(VERSION 3.10.0)

project(leetcode101)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# leetcode101 sources
include(cmake/leetcode101-search.cmake)
include(cmake/leetcode101-sort.cmake)
include(cmake/leetcode101-dp.cmake)
include(cmake/leetcode101-str.cmake)
include(cmake/leetcode101-tree.cmake)
include(cmake/leetcode101-ds.cmake)

set(leetcode101_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${LEETCODE101_SEARCH_SOURCES}
    ${LEETCODE101_SORT_SOURCES}
    ${LEETCODE101_DC_SOURCES}
    ${LEETCODE101_STR_SOURCES}
    ${LEETCODE101_TREE_SOURCES}
    ${LEETCODE101_DS_SOURCES}
    ${LEETCODE101_DC_SOURCES}
    )

add_executable(leetcode101 ${leetcode101_SOURCES})
target_precompile_headers(leetcode101 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/precompiledheader.h)
###########################################################
# TESTS
###########################################################

add_subdirectory(tests)

# TODO: install