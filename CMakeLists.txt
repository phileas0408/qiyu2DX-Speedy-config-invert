cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

if(DEFINED CONTROLLER_SIDE)
add_compile_definitions(CONTROLLER_SIDE=${CONTROLLER_SIDE})
endif()

project(Pico_Game_Controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(src)
