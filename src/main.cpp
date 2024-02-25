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
#include "../include/random_utilities.h"

std::map<std::string, GLuint> loadTextures() {
    std::map<std::string, GLuint> textures = std::map<std::string, GLuint>();
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "assets/dvd.png")));
    return textures;
}

void display(GLFWwindow* window, const Mesh& mesh, const std::map<std::string, GLuint>& textures, const int& shaderProgramId) {
        // Clean color buffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate shader
        glUseProgram(shaderProgramId);

        // Update logo color and position
        float time = glfwGetTime();
        int logoColorLocation = glGetUniformLocation(shaderProgramId, "textureColor");
        //float color = get_random_between(0.2, 1);
        //glUniform3f(logoColorLocation, 0.0f, 0.0f, 0.0f);

        // Bind and render
        glBindTexture(GL_TEXTURE_2D, textures.find("DVD_LOGO")->second);
        drawMesh(mesh);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);

    // Prepare DVD vertices
    constexpr float dvdHeight = 0.1f;
    constexpr float dvdWidth = dvdHeight * 2;
    std::vector<Vertex> vertices = {
        Vertex( // Top left
            glm::vec3(-dvdWidth, dvdHeight, 0.0f),
            glm::vec3( 1.0f, 0.0f, 0.0f),
            glm::vec2( 0.0f, 1.0f)
        ),
        Vertex( // Top right
            glm::vec3(dvdWidth, dvdHeight, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f)
        ),
        Vertex( // Bottom left
            glm::vec3(-dvdWidth, -dvdHeight, 0.0f),
            glm::vec3( 0.0f, 0.0f, 1.0f),
            glm::vec2( 0.0f, 0.0f)
        ),
        Vertex( // Bottom right
            glm::vec3(dvdWidth, -dvdHeight, 0.0f),
            glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec2(1.0f, 0.0f)
        )
    };
    std::vector<GLint> indexes = { 0, 1, 2, 1, 2, 3 };

    // Create shader program
    std::string vertexShaderPath = "shaders/vertex.glsl";
    std::string fragmentShaderPath = "shaders/fragment.glsl";
    int shaderProgramId = createShaderProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    // Load DVD texture and mesh
    std::map<std::string, GLuint> textures = loadTextures();
    Mesh mesh = loadMesh(vertices, indexes);

    while (!glfwWindowShouldClose(window)) {
        display(window, mesh, textures, shaderProgramId);
    }
    unloadTexture(textures.find("DVD_LOGO")->second);
    unloadMesh(mesh);
    destroyWindow(window);
}
