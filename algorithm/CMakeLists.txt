cmake_minimum_required(VERSION 3.10.0)

project(sort)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SORT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/quick_sort/quick_sort.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/quick_sort/quick_sort.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/bubble_sort/bubble_sort.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/bubble_sort/bubble_sort.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/insertion_sort/insertion_sort.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/insertion_sort/insertion_sort.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/merge_sort/merge_sort.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/merge_sort/merge_sort.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/selection_sort/selection_sort.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/selection_sort/selection_sort.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/topk.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sort/topk.hpp
    ${CMAKE_CURRENT_LIST_DIR}/search/search.cpp
    ${CMAKE_CURRENT_LIST_DIR}/search/search.hpp
    )

add_executable(sort ${SORT_SOURCES})

###########################################################
# TESTS
###########################################################

add_subdirectory(tests)