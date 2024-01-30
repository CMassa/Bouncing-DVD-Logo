#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include <vector>

#include "include/glfw_utilities.h"
#include "include/image_utilities.h"
#include "include/settings.h"
#include "include/vertex.h"
#include "include/mesh.h"
#include "include/opengl_utilities.h"

std::map<std::string, GLuint> textures;

void loadTextures() {
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "dvd.jpg")));
}

void display(GLFWwindow* window, const Mesh& mesh) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw
    /*
    glBindTexture(GL_TEXTURE_2D, textures.at("DVD_LOGO"));
    */
    drawMesh(mesh);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    loadTextures();

    std::vector<Vertex> vertices = {
        Vertex(-1.0f, -1.0f, 0.0f),
        Vertex( 1.0f, -1.0f, 0.0f),
        Vertex( 1.0f,  1.0f, 0.0f),

        Vertex(-1.0f, -1.0f, 0.0f),
        Vertex( 1.0f,  1.0f, 0.0f),
        Vertex(-1.0f,  1.0f, 0.0f)
    };
    std::vector<GLint> indexes = { 0, 1, 2, 0, 2, 3 };

    Mesh mesh = loadMesh(vertices, indexes);

    while (!glfwWindowShouldClose(window)) {
        display(window, mesh);
    }
    destroyWindow(window);
}