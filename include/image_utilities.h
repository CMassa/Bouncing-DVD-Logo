#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

GLuint loadTexture(const char* imagePath);

void unloadTexture(GLuint textureID);