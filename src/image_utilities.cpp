#include "../include/image_utilities.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint loadTexture(const char* imagePath) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);

    int width, height, nrChannels;
    unsigned char* image = stbi_load(imagePath, &width, &height, &nrChannels, STBI_rgb);
    if (!image) {
        std::cerr << "Error loading image: " << stbi_failure_reason() << std::endl;
        exit(EXIT_FAILURE);
    } 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, textureID);

    return textureID;
}

void unloadTexture(GLuint textureID) {
    glDeleteTextures(1, &textureID);
}