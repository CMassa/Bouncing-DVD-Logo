#include "../include/shader_utilities.h"

int createShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {

    // Compile shaders and link program
    unsigned int vertexShader = compileShader(vertexShaderPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);
    unsigned int shaderProgram = linkProgram(vertexShader, fragmentShader);

    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int compileShader(const char* shaderPath, GLenum type) {
    std::ifstream shaderFile;
    std::stringstream shaderStream;
    try {
        shaderFile.open(shaderPath);
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        std::cout << shaderStream.str() << std::endl;
    } catch(std::ifstream::failure e) {
        std::cout << "Error reading shader file " << shaderPath << std::endl;
    }
    const char* shaderSource = shaderStream.str().c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Compile shader " << type << " failed\n" << infoLog << std::endl;
    }
    return shader;
}

int linkProgram(const int vertexShader, const int fragmentShader) {
    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "Link program failed\n" << infoLog << std::endl;
    }
    return program;
}