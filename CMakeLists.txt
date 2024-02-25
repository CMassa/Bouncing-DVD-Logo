# Project properties
cmake_minimum_required(VERSION 3.28.1)
project(Bouncing-DVD-Logo)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
set(GLAD_PROFILE "core")
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(glm REQUIRED)

# Create executable
file(GLOB SRC_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})

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
    glm::glm
)