add_library(zd_engine engine.cpp helpers.cpp texture.cpp)

# link with sdl
target_link_libraries(zd_engine PRIVATE SDL2 SDL2_image)

# include headers
target_include_directories(zd_engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})