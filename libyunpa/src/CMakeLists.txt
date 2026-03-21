target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "libyunpa.cppm"
         "Engine/Scene.cppm"
         "Engine/SceneManager.cppm"
         "Graphics/Drawable.cppm"
         "System/Time.cppm"
  PRIVATE "Engine/Scene.cpp" "Engine/SceneManager.cpp" "System/Time.cpp")
