cmake_minimum_required(VERSION 3.10)
project(bulwark)

set(CMAKE_CXX_STANDARD 11)

add_executable(bulwark src/main.cpp src/vendor/json.h src/GameDetails.cpp src/GameDetails.h src/GameMap.cpp src/GameMap.h src/Player.cpp src/Player.h src/State.cpp src/State.h)