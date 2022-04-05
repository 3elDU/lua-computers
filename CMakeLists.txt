cmake_minimum_required(VERSION 3.10)

# set the project name
project(lua_computers)

# add the zd_engine library
add_subdirectory(engine)

# add the zd_emu library
add_subdirectory(emu)

# add executables
add_executable(lua_computers main.cpp)

target_link_libraries(lua_computers PUBLIC zd_engine)
target_link_libraries(lua_computers PUBLIC zd_emu)

# add includes
target_include_directories(lua_computers PUBLIC
                           ${CMAKE_BINARY_DIR}
                          )

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)