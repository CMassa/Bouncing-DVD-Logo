#include <string>
#include <map>
#include <vector>

#include "../include/glfw_utilities.h"
#include "../include/image_utilities.h"
#include "../include/settings.h"
#include "../include/vertex.h"
#include "../include/mesh.h"
#include "../include/opengl_utilities.h"
#include "../include/shader_utilities.h"

std::map<std::string, GLuint> textures;

void loadTextures() {
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "assets/dvd.jpg")));
}

void display(GLFWwindow* window, const Mesh& mesh, const int& shaderProgram) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        drawMesh(mesh);

        glfwSwapBuffers(window);
        glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);

    std::string vertexShaderPath = "shaders/vertex.glsl";
    std::string fragmentShaderPath = "shaders/fragment.glsl";
    int shaderProgram = createShaderProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    std::vector<Vertex> vertices = {
        Vertex(-0.5f,  0.5f, 0.0f, 1.0f, 1.0f),
        Vertex( 0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f),
        Vertex( 0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
    };
    std::vector<uint32_t> indexes = { 0, 1, 2, 1, 2, 3 };

    loadTextures();
    Mesh mesh = loadMesh(vertices, indexes);
    while (!glfwWindowShouldClose(window)) {
        display(window, mesh, shaderProgram);
    }
    unloadMesh(mesh);
    destroyWindow(window);
}
