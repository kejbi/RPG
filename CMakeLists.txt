cmake_minimum_required(VERSION 3.9)
project(RPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(RPG creature.cpp creature.h character.cpp character.h catch.h tests.cpp)