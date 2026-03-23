cmake_minimum_required(VERSION 3.28)
project(
  YoungPastry
  VERSION 0.0.1
  DESCRIPTION "A game about the hunt for a magical pet."
  LANGUAGES CXX)

add_executable(${PROJECT_NAME})
if(EMSCRIPTEN)
  set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE libyunpa)
add_subdirectory("src")
