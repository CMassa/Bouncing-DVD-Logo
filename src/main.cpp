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

std::map<std::string, GLuint> loadTextures() {
    std::map<std::string, GLuint> textures = std::map<std::string, GLuint>();
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "assets/dvd.jpg")));
    return textures;
}

void display(GLFWwindow* window, const Mesh& mesh, const std::map<std::string, GLuint>& textures, const int& shaderProgram) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);

        glBindTexture(GL_TEXTURE_2D, textures.find("DVD_LOGO")->second);
        drawMesh(mesh);

        glfwSwapBuffers(window);
        glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);

    // Prepare DVD vertices
    std::vector<Vertex> vertices = {
        Vertex( // Top left
            glm::vec3(-0.5f, 0.5f, 0.0f),
            glm::vec3( 1.0f, 0.0f, 0.0f),
            glm::vec2( 0.0f, 1.0f)
        ),
        Vertex( // Top right
            glm::vec3(0.5f, 0.5f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f)
        ),
        Vertex( // Bottom left
            glm::vec3(-0.5f, -0.5f, 0.0f),
            glm::vec3( 0.0f,  0.0f, 1.0f),
            glm::vec2( 0.0f,  0.0f)
        ),
        Vertex( // Bottom right
            glm::vec3(0.5f, -0.5f, 0.0f),
            glm::vec3(1.0f,  1.0f, 0.0f),
            glm::vec2(1.0f,  0.0f)
        )
    };
    std::vector<GLint> indexes = { 0, 1, 2, 1, 2, 3 };

    // Create shader program
    std::string vertexShaderPath = "shaders/vertex.glsl";
    std::string fragmentShaderPath = "shaders/fragment.glsl";
    int shaderProgram = createShaderProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    // Load DVD texture and mesh
    std::map<std::string, GLuint> textures = loadTextures();
    Mesh mesh = loadMesh(vertices, indexes);

    while (!glfwWindowShouldClose(window)) {
        display(window, mesh, textures, shaderProgram);
    }
    unloadTexture(textures.find("DVD_LOGO")->second);
    unloadMesh(mesh);
    destroyWindow(window);
}
