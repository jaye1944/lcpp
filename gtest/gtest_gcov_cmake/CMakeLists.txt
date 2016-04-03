cmake_minimum_required (VERSION 2.6)
project (Test)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

#set gcov flages
#set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage") 
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TestConfig.h.in"
  "${PROJECT_BINARY_DIR}/TestConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(Test test.cpp)
