cmake_minimum_required(VERSION 3.10.0)

project(sort)

set(SORT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    )

add_executable(sort 
                ${SORT_SOURCES} 
                "./merge_sort/merge_sort.cpp"
                )

target_include_directories(sort  PUBLIC "./merge_sort/merge_sort.h")