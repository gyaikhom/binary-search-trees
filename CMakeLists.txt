cmake_minimum_required (VERSION 2.8)
project (BINARY_SEARCH_TREES)
set (CMAKE_CXX_FLAGS "-g -Wall")
add_subdirectory (src)
include_directories (${BINARY_SEARCH_TREES_SOURCE_DIR}/src)
link_directories (${BINARY_SEARCH_TREES_SOURCE_DIR}/src)
add_executable (testBinarySearchTrees src/Main.cpp)
target_link_libraries (testBinarySearchTrees DataStructures)
