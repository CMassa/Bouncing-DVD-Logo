#include <cstdio>
#include <cstdlib>
#include "settings.h"

void toggle_full_screen(GLFWwindow* window) {
    if (full_screen) {
        glfwSetWindowMonitor(window, nullptr, 100, 100, WIDTH, HEIGHT, GLFW_DONT_CARE);
    } else {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);    
    }
    full_screen = !full_screen;
}

static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        toggle_full_screen(window);
    }
}

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
    exit(EXIT_FAILURE);
}