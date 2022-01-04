cmake_minimum_required(VERSION 3.10.0)

	project(sort)

		set(SORT_SOURCES ${CMAKE_CURRENT_LIST_DIR} /
			main.cpp ${CMAKE_CURRENT_LIST_DIR} / bubble_sort /
			bubble_sort.hpp ${CMAKE_CURRENT_LIST_DIR} / bubble_sort /
			bubble_sort.cpp ${CMAKE_CURRENT_LIST_DIR} / insertion_sort /
			insertion_sort.hpp ${CMAKE_CURRENT_LIST_DIR} / insertion_sort /
			insertion_sort.cpp ${CMAKE_CURRENT_LIST_DIR} / merge_sort /
			merge_sort.hpp ${CMAKE_CURRENT_LIST_DIR} / merge_sort /
			merge_sort.cpp ${CMAKE_CURRENT_LIST_DIR} / selection_sort /
			selection_sort.hpp ${CMAKE_CURRENT_LIST_DIR} / selection_sort /
			selection_sort.cpp)

			add_executable(sort ${SORT_SOURCES})
