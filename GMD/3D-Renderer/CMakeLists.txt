# Core/CMakeLists.txt

# Set the path to libraries
set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/3D-Renderer/Source/Libs)

# Globbing source files
file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
)

# Define the library
add_library(3D-Renderer STATIC ${RENDERER_SOURCE_FILES})

# Link libraries
target_link_libraries(3D-Renderer PUBLIC
    ${PATH_LIBRARIES}/GLEW/glew32s.lib
    ${PATH_LIBRARIES}/GLFW/glfw3.lib
    opengl32.lib
)

# Linker options
target_link_options(3D-Renderer PUBLIC /NODEFAULTLIB:MSVCRT)
target_compile_definitions(3D-Renderer PUBLIC GLEW_STATIC)

# Include directories
target_include_directories(3D-Renderer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

# Group source files in IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RENDERER_SOURCE_FILES})
