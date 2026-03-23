target_sources(
  ${PROJECT_NAME}
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         "Core.cppm"
         "Scene.cppm"
         "SceneManager.cppm"
         "TermManager.cppm"
  PRIVATE "Core.cpp" "Scene.cpp" "SceneManager.cpp")
