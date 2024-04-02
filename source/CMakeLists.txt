add_library(source credits.cpp settings.cpp)

target_include_directories(source PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include"
                          )
