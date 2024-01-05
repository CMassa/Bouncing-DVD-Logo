#include "callbacks.h"
#include "utilities.h"

void loadTextures() {
    textures.insert(std::make_pair("DVD_LOGO", loadTexture("dvd.jpg")));
}

int main(int argc, char** argv) {
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    GLFWwindow* window = createWindow();
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, glfw_key_callback);

    loadTextures();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}