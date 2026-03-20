cmake_minimum_required(VERSION 3.28)
project(
  libyunpa
  VERSION 0.0.1
  DESCRIPTION "A library to help gamers game."
  LANGUAGES CXX)

add_library(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" FOLDER
                                                           ${PROJECT_NAME})
add_subdirectory("src")
