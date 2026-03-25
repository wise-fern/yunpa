target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "Core.cppm"
         "EventManager.cppm"
         "Scene.cppm"
         "SceneManager.cppm"
  PRIVATE "Core.cpp" "EventManager.cpp" "Scene.cpp" "SceneManager.cpp")
