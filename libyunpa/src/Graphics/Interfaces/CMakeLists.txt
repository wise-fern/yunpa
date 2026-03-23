target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET CXX_MODULES FILES "Colorable.cppm" "Drawable.cppm"
  PRIVATE "Colorable.cpp")
