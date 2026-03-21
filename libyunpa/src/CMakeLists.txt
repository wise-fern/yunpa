target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "libyunpa.cppm"
         "Engine/Scene.cppm"
         "Graphics/Drawable.cppm"
         "System/Time.cppm"
  PRIVATE "Engine/Scene.cpp" "System/Time.cpp")
