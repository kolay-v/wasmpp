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
file(GLOB RUNNER_SOURCE "${PROJECT_SOURCE_DIR}/runner/*.cpp")
file(GLOB PARSER_SOURCE "${PROJECT_SOURCE_DIR}/parser/*.cpp")
# add the executable
add_library(wasmpp_compiler STATIC ${PARSER_SOURCE})
add_executable(wasmpp ${RUNNER_SOURCE})
include_directories("${PROJECT_SOURCE_DIR}")
target_include_directories(wasmpp PRIVATE "${PROJECT_SOURCE_DIR}/parser")
target_link_libraries(wasmpp wasmpp_compiler)
