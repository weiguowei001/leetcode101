# function(leetcode101_add_test _name)
#   set(_srcs ${ARGN})
# #  message (STATUS "${_name} sources: ${_srcs}")
#   add_executable (${_name} ${_srcs})
#   target_link_libraries (${_name} ${log4cplus})
#   get_filename_component (_log4cplus_properties "log4cplus.properties.in"
#     ABSOLUTE)
#   add_test(NAME ${_name}
#     WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
#     COMMAND ${_name} ${_log4cplus_properties})
# endfunction()


# add_subdirectory (dp_test)


include(CTest)

# catkin compatibility
if(NOT TARGET run_tests)
  add_custom_target(run_tests)
endif()

if(BUILD_TESTING)
  set(TESTS dp_test)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  include_directories(
    ${PROJECT_SOURCE_DIR}/dp
  )

  foreach(test ${TESTS})
    add_executable(${test} EXCLUDE_FROM_ALL 
      main.cpp 
      ${PROJECT_SOURCE_DIR}/dp/dp.cpp
      ${PROJECT_SOURCE_DIR}/dp/one_dimensional.cpp
      ${PROJECT_SOURCE_DIR}/dp/two_dimensional.cpp
      )
    add_test(NAME ${test} COMMAND ${test})
  endforeach()

  add_custom_target(check_dp
    COMMAND ctest -V
    DEPENDS ${TESTS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )

  add_dependencies(run_tests check_dp)

endif()

