cmake_minimum_required(VERSION 3.31)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES
    "${CMAKE_CURRENT_LIST_DIR}/cmake/TopLevel.cmake")
project(yunpa)
if(PROJECT_IS_TOP_LEVEL)
  FetchContent_MakeAvailable(pegtl)
endif()
add_subdirectory("libyunpa")
add_subdirectory("YoungPastry")
