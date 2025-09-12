#!/bin/bash

set -e

mkdir -p lib
if [ ! -d lib/pico-sdk ]; then
    git clone https://github.com/raspberrypi/pico-sdk lib/pico-sdk --recurse-submodules
fi

rm -fv build/src/Pico_Game_Controller.* build/CMakeCache.txt
cmake -B build -S . -DPICO_SDK_PATH=lib/pico-sdk -DCONTROLLER_SIDE=1
cmake --build build
mv -v build_uf2/Pico_Game_Controller.uf2 build_uf2/p1.uf2

rm -fv build/src/Pico_Game_Controller.* build/CMakeCache.txt
cmake -B build -S . -DPICO_SDK_PATH=lib/pico-sdk -DCONTROLLER_SIDE=2
cmake --build build
mv -v build_uf2/Pico_Game_Controller.uf2 build_uf2/p2.uf2