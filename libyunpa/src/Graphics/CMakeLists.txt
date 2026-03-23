target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET CXX_MODULES FILES "Color.cppm" "Element.cppm"
  PRIVATE "Color.cpp" "Element.cpp")
add_subdirectory("Interfaces")
