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
         "Graphics/Drawable.cppm"
         "System/Events.cppm"
         "System/Point2.cppm"
         "System/Time.cppm"
         "System/Unicode.cppm"
  PRIVATE "Engine/Core.cpp")
