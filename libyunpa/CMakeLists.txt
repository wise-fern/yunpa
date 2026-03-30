cmake_minimum_required(VERSION 3.31)
project(
  libyunpa
  VERSION 0.0.1
  DESCRIPTION "A library to help gamers game."
  LANGUAGES CXX)

if(EMSCRIPTEN)
  add_library(${PROJECT_NAME} STATIC)
else()
  add_library(${PROJECT_NAME})
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" FOLDER
                                                           ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE pegtl PUBLIC ftxui::modules)
if(NOT MSVC)
  target_compile_options(
    ${PROJECT_NAME}
    PRIVATE -Wall
            -Wbool-operation
            -Wconversion
            -Wdocumentation
            -Weffc++
            -Wempty-body
            # -Werror
            -Wextra
            -Wimplicit
            -Wimplicit-fallthrough
            -Winfinite-recursion
            -Wloop-analysis
            -Wnonportable-include-path
            -Wparentheses
            -Wsign-conversion
            -Wsuggest-override
            -Wunreachable-code
            -Wunreachable-code-aggressive
            -Wunused
            -Wused-but-marked-unused)
endif()
add_subdirectory("src")
