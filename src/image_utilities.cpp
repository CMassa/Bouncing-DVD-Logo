#include "../include/image_utilities.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint loadTexture(const char* imagePath) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);

    int width, height, channels;
    unsigned char* image = stbi_load(imagePath, &width, &height, &channels, STBI_rgb);
    if (image) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    } else {
        std::cerr << "Error loading image: " << stbi_failure_reason() << std::endl;
        exit(EXIT_FAILURE);
    }
    stbi_image_free(image);

    return textureID;
}