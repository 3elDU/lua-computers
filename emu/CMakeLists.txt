add_library(zd_emu emulator.cpp library.cpp)

find_package(Lua54 REQUIRED)

# link with lua
target_link_libraries(zd_emu PRIVATE ${LUA_LIBRARIES})

# include headers
target_include_directories(zd_emu INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${LUA_INCLUDE_DIRS})