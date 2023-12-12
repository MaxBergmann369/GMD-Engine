# Editor/CMakeLists.txt

file(GLOB_RECURSE UI_SOURCE
    "Source/*.cpp"
    "Source/*.h"
)

add_executable(UI
    ${UI_SOURCE})

# Link the Core library
target_link_libraries(UI PRIVATE 3D-Renderer)


include_directories(${CMAKE_SOURCE_DIR}/UI/Libs/ImGui)