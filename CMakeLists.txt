# Project properties
cmake_minimum_required(VERSION 3.25)
project(Bouncing-DVD-Logo)

# Find packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Create executable
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${OPENGL_LIBRARIES}
    glfw GLEW::GLEW
)