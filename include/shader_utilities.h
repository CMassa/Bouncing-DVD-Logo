#pragma once

#include <glad/glad.h>
#include <iostream>

int createShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);

int compileShader(const char* shaderPath, GLenum type);

int linkProgram(const int vertexShader, const int fragmentShader);