cmake_minimum_required(VERSION 3.28)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES
    "${CMAKE_CURRENT_LIST_DIR}/cmake/TopLevel.cmake")
project(yunpa)

add_subdirectory("libyunpa")
