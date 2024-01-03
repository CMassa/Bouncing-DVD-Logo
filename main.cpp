#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <vector>

const int WIDTH = 1024;
const int HEIGHT = 768;

std::vector<GLuint> textures;

GLuint loadTexture(const char *imagePath) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);

    int width, height, channels;
    unsigned char* image = stbi_load(imagePath, &width, &height, &channels, STBI_rgb);
    if (image) {
        std::cout << width << " " << height << std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Error loading image: " << stbi_failure_reason() << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(image);

    return textureID;
}

void loadTextures() {
    textures.push_back(loadTexture("dvd.jpg"));
}

int main(int argc, char** argv) {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Bouncing DVD Logo", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    loadTextures();

    while (!glfwWindowShouldClose(window)) {

    }
    return 0;
}