cmake_minimum_required (VERSION 3.10)
project (wasmpp)
# The version number.
set (wasmpp_VERSION_MAJOR 1)
set (wasmpp_VERSION_MINOR 0)
set (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
#  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(wasmpp "${PROJECT_SOURCE_DIR}/main.cpp")
