#pragma once

#include <cstdio>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "settings.h"

void toggle_full_screen(GLFWwindow* window);

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void glfw_error_callback(int error, const char* description);

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height);