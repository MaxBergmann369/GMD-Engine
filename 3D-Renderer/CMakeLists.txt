# Core/CMakeLists.txt
file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "Source/*.h"
    "Source/*.cpp"
)

# Define the library
add_library(3D-Renderer STATIC ${RENDERER_SOURCE_FILES})

# Include directories if needed
target_include_directories(3D-Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RENDERER_SOURCE_FILES})