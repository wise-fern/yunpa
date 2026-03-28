target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET CXX_MODULES FILES "Color.cppm" "Element.cppm" "Screen.cppm"
  PRIVATE "Color.cpp" "Element.cpp" "Screen.cpp")
add_subdirectory("Interfaces")
add_subdirectory("Elements")
