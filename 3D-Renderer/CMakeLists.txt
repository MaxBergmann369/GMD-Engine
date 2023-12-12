# Core/CMakeLists.txt

# Define the library
add_library(3D-Renderer STATIC
    Source/Core.h
    Source/Core.cpp)

# Include directories if needed
target_include_directories(3D-Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})