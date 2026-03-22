target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "libyunpa.cppm"
         "Engine/Core.cppm"
         "Engine/Scene.cppm"
         "Engine/SceneManager.cppm"
         "Engine/TermManager.cppm"
         "Graphics/Color.cppm"
         "Graphics/Colorable.cppm"
         "Graphics/Drawable.cppm"
         "System/Events.cppm"
         "System/Point2.cppm"
         "System/Time.cppm"
  PRIVATE "Engine/Core.cpp"
          "Engine/Scene.cpp"
          "Engine/SceneManager.cpp"
          "Engine/TermManager.cpp"
          "Graphics/Color.cpp"
          "Graphics/Colorable.cpp"
          "System/Time.cpp")
