# Project properties
cmake_minimum_required(VERSION 3.28.1)
project(Bouncing-DVD-Logo)

add_definitions(-DSTB_IMAGE_IMPLEMENTATION)

# Find packages
set(GLAD_PROFILE "core")
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(Stb REQUIRED)

# Create executable
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${Stb_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${OPENGL_LIBRARIES}
    glfw
    glad::glad
)