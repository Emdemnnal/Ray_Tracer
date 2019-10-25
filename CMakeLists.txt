cmake_minimum_required(VERSION 2.6)
project(Ray_Tracer)

include_directories(
  src
)

add_library(MCG
  src/MCG/MCG.h
  src/MCG/MCG_GFX_Lib.h
  src/MCG/MCG_GFX_Lib.cpp
)

target_link_libraries(MCG SDL2 opengl32 glew32)

add_executable(Ray_Tracer
  src/Application/Main.cpp
)

target_link_libraries(Ray_Tracer MCG)
