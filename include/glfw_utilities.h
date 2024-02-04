#pragma once

#include <glad/glad.h>
#include "callbacks.h"

void initGlfw();

GLFWwindow* createWindow(const char* title, int width, int height);

void destroyWindow(GLFWwindow* window);