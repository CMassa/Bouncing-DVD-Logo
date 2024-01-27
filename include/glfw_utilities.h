#pragma once

void initGlfw();

GLFWwindow* createWindow(const char* title, int width, int height);

void destroyWindow(GLFWwindow* window);