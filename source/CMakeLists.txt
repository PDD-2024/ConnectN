add_library(source credits.cpp settings.cpp game.cpp menu.cpp piece.cpp player.cpp position.cpp board.cpp scene_manager.cpp program_manager.cpp)

target_include_directories(source PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include"
                          )
