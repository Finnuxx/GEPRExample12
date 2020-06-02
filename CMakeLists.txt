cmake_minimum_required(VERSION 3.16)
project(GEPRExample12)

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

add_executable(GEPRExample12 main.cpp)