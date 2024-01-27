#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include <vector>

#include "include/glfw_utilities.h"
#include "include/image_utilities.h"
#include "include/settings.h"
#include "include/vertex.h"

std::map<std::string, GLuint> textures;

void loadTextures() {
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "dvd.jpg")));
}

void display(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, textures.at("DVD_LOGO"));

    std::vector<Vertex> vertices = {
        Vertex(-1.0f, -1.0f, 0.0f),
        Vertex( 1.0f, -1.0f, 0.0f),
        Vertex( 1.0f,  1.0f, 0.0f),

        Vertex(-1.0f, -1.0f, 0.0f),
        Vertex( 1.0f,  1.0f, 0.0f),
        Vertex(-1.0f,  1.0f, 0.0f)
    };
    GLint elems[] = { 0, 1, 2, 0, 2, 3 };

    // Vertex Array Object (VAO) / Vertex Buffer Object (VBO) / Element Buffer Object (EBO)
    uint32_t VAO, VBO, EBO; 

    // Setup VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Setup VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 5 * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (const GLvoid*) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Setup EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elems), elems, GL_STATIC_DRAW);

    // Cleanup
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // Draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    loadTextures();
    while (!glfwWindowShouldClose(window)) {
        display(window);
    }
    destroyWindow(window);
}