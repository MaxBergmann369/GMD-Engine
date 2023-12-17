# Core/CMakeLists.txt

set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/${CORE_NAME}/Source/Libs)

# Globbing source files
file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
)

find_package(OpenGL REQUIRED)

# Define the library
add_library(${CORE_NAME} STATIC ${RENDERER_SOURCE_FILES})

target_compile_definitions(${CORE_NAME} PRIVATE GLEW_STATIC)

# Include directories
target_include_directories(${CORE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

target_link_directories(${CORE_NAME} PUBLIC
	${PATH_LIBRARIES}/GLEW
	${PATH_LIBRARIES}/GLFW
)

# Link libraries
target_link_libraries(${CORE_NAME} PRIVATE
    $<$<CONFIG:Debug>:Debug/glfw3>
    $<$<CONFIG:Release>:Release/glfw3>
    glew32s
    opengl32
    glu32
)

# Group source files in IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RENDERER_SOURCE_FILES})
