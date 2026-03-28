target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "Colorable.cppm"
         "Drawable.cppm"
         "Formattable.cppm"
         "Positionable.cppm"
  PRIVATE "Colorable.cpp" "Formattable.cpp" "Positionable.cpp")
