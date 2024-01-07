#include <GL/gl.h>
#include <glad/glad.h>
#include <map>
#include "glfw_utilities.h"
#include "image_utilities.h"

std::map<std::string, GLuint> textures;

void loadTextures() {
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "dvd.jpg")));
}

void display(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);
    loadTextures();
    while (!glfwWindowShouldClose(window)) {
        display(window);
    }
    destroyWindow(window);
}