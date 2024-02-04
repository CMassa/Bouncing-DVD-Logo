#include "../include/callbacks.h"

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

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        toggle_full_screen(window);
    }
}

void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
    exit(EXIT_FAILURE);
}

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}