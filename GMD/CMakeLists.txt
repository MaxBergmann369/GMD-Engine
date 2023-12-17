# NAMES TO SET 
# !! Make sure to also set the folders the same name
set(PRJECT_NAME GMD-Engine)
set(CORE_NAME 3D-Renderer)
set(APPLICATON_NAME Editor)

cmake_minimum_required(VERSION 3.10)
project(${PRJECT_NAME})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the subprojects
add_subdirectory(${CORE_NAME})
add_subdirectory(${APPLICATON_NAME})
