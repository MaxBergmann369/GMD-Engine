# Core/CMakeLists.txt
set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/3D-Renderer/Source/Libs)

file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "Source/*.h"
    "Source/*.cpp"
)

# Define the library
add_library(3D-Renderer STATIC ${RENDERER_SOURCE_FILES})

target_link_libraries(3D-Renderer PRIVATE
    ${PATH_LIBRARIES}/GLFW/glfw3.lib
    ${PATH_LIBRARIES}/GLEW/glew32s.lib
    opengl32.lib
)

target_link_options(3D-Renderer PRIVATE /NODEFAULTLIB:MSVCRT)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RENDERER_SOURCE_FILES})