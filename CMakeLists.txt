cmake_minimum_required(VERSION 3.10)
project(GMD-Engine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the subprojects
add_subdirectory(3D-Renderer)
add_subdirectory(UI)

