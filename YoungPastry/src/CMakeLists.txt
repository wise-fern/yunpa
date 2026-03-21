target_sources(
  ${PROJECT_NAME}
  PRIVATE "main.cpp" "Scenes/Title.cpp"
  PRIVATE FILE_SET CXX_MODULES FILES "YoungPastry.cppm" "Scenes/Title.cppm")
