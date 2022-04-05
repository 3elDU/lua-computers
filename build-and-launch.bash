#! /usr/bin/env bash

# if the build directory doesn't exist, creating
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# configure for the release
cmake -DCMAKE_BUILD_TYPE=Release ..

# build the executable
cmake --build . -j$(nproc)

# go back to the root directory
cd ..

# run the executable
./build/lua_computers
