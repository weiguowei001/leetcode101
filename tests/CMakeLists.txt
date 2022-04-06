include(CTest)

# TODO: test macro
# catkin compatibility

if(NOT TARGET run_tests)
  add_custom_target(run_tests)
endif()

if(BUILD_TESTING)
  set(TESTS search_test)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  include_directories(
    ${PROJECT_SOURCE_DIR}/search
  )

  foreach(test ${TESTS})
    add_executable(${test} EXCLUDE_FROM_ALL 
      ${test}.cpp 
      ${PROJECT_SOURCE_DIR}/search/dfs.cpp
      ${PROJECT_SOURCE_DIR}/search/bfs.cpp
      ${PROJECT_SOURCE_DIR}/search/backtracking.cpp
      )
    add_test(NAME ${test} COMMAND ${test})
  endforeach()

  add_custom_target(check
    COMMAND ctest -V
    DEPENDS ${TESTS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )

  add_dependencies(run_tests check)
endif()

add_subdirectory(dp_test)
