# Editor/CMakeLists.txt

# Define the executable
add_executable(UI 
    Editor.cpp)

# Link the Core library
target_link_libraries(UI PRIVATE 3D-Renderer)
