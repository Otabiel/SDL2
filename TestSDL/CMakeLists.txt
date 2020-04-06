cmake_minimum_required(VERSION 3.15)
project(TestSDL)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR})

add_executable(TestSDL main.cpp Game.cpp Game.h)

target_link_libraries(TestSDL ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lSDL2 -lSDL2_IMAGE)