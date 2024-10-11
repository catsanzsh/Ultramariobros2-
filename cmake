 cmake_minimum_required(VERSION 3.10)

# Project name
project(UltraMarioBros2)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/60fps.asm
    src/b3313_2.0_lightning.c
    src/b3313_render_ft.c
    src/compilev0.c
    src/file_menu.c
    src/hackersm64v0.1_hypercam_base.asm
    src/mermaid-testnpc.c
    src/program.c
    src/texture.cpp
    src/texture_api.cpp
)

# Include directories
include_directories(include)

# Add executable
add_executable(UltraMarioBros2 ${SOURCES})

# Link libraries (if any)
# target_link_libraries(UltraMarioBros2 <library_name>)
