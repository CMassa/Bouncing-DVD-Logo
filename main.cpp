#include <GL/glew.h>
#include <GLFW/glfw3.h>

const int WIDTH = 1024;
const int HEIGHT = 768;

int main(int argc, char** argv) {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Bouncing DVD Logo", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {

    }
    return 0;
}