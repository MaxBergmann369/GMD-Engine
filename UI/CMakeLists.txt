# Editor/CMakeLists.txt

set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/3D-Renderer/Source/Libs)

file(GLOB_RECURSE UI_SOURCE
    "Source/*.cpp"
    "Source/*.h"
)

add_executable(UI
    ${UI_SOURCE})

# Link the 3D Renderer library
target_link_libraries(UI PRIVATE 3D-Renderer)

target_link_libraries(UI PRIVATE
    $<$<CONFIG:Debug>:${PATH_LIBRARIES}/GLFW/glfw3.lib>
)


target_link_options(UI PRIVATE /NODEFAULTLIB:MSVCRT)


include_directories(${CMAKE_SOURCE_DIR}/UI/Source/Libs/ImGui)
include_directories(${CMAKE_SOURCE_DIR}/3D-Renderer/Source)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${UI_SOURCE})