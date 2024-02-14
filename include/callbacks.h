#pragma once

#include <cstdio>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "settings.h"

void toggleFullScreen(GLFWwindow* window);

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void glfwErrorCallback(int error, const char* description);

void glfwFramebufferSizeCallback(GLFWwindow* window, int width, int height);