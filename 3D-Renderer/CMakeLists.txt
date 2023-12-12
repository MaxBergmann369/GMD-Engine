# Core/CMakeLists.txt
file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "Source/*.h"
    "Source/*.cpp"
)

# Define the library
add_library(3D-Renderer STATIC ${RENDERER_SOURCE_FILES})

# Include directories if needed
target_include_directories(3D-Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/3D-Renderer/Libs)