# Lua computers

This is a small project, I'm working on.
C++ hosts lua interepreter, while providing custom standard library to lua.
We're writing our own library, so lua can't access the host filesystem.
So you can consider these as "sandboxed" applications.

You can write your own graphics frontend for it, see `emu/graphics.hpp`

Currently under development. More features and documentation will be added.

## Dependencies
If using default frontend ( supplied with this project ), you need to have SDL2 and SDL2_image installed.<br>
Of course, lua also needs to be installed.<br>
If build fails, try changing the lua version in `emu/CMakeLists.txt`

## Building
- ### Autoumated
    - There's a script called `build-and-launch.bahs` in the root directory.
- ### Manual
    - `mkdir build`
    - `cd build`
    - `cmake -DCMAKE_BUILD_TYPE=Release ..`
    - `make -j$(nproc)`
    - `./lua_computers`

Currently, it's only working on Linux. Maybe it will work for macOS ( haven't tested ).
Clearly, it won't work for windows ( and I don't plan to support it ).