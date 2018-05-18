cmake_minimum_required(VERSION 3.10)
project(bulwark)

set(CMAKE_CXX_STANDARD 11)

add_executable(bulwark src/main.cpp src/vendor/json.h src/State.cpp src/State.h src/Agent.cpp src/Agent.h)