target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "libyunpa.cppm"
         "Engine/Core.cppm"
         "Engine/Scene.cppm"
         "Engine/SceneManager.cppm"
         "Graphics/Drawable.cppm"
         "System/Time.cppm"
  PRIVATE "Engine/Core.cpp" "Engine/Scene.cpp" "Engine/SceneManager.cpp"
          "System/Time.cpp")
