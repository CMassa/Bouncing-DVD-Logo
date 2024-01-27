#pragma once

void toggle_full_screen(GLFWwindow* window);

static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

static void glfw_error_callback(int error, const char* description);