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

const std::vector<Vertex> vertices = {
    Vertex( // Top left
        glm::vec3(-DVD_WIDTH / 2, DVD_HEIGHT / 2, 0.0f),
        glm::vec3( 1.0f, 0.0f, 0.0f),
        glm::vec2( 0.0f, 1.0f)
    ),
    Vertex( // Top right
        glm::vec3(DVD_WIDTH / 2, DVD_HEIGHT / 2, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f)
    ),
    Vertex( // Bottom left
        glm::vec3(-DVD_WIDTH / 2, -DVD_HEIGHT / 2, 0.0f),
        glm::vec3( 0.0f, 0.0f, 1.0f),
        glm::vec2( 0.0f, 0.0f)
    ),
    Vertex( // Bottom right
        glm::vec3(DVD_WIDTH / 2, -DVD_HEIGHT / 2, 0.0f),
        glm::vec3(1.0f, 1.0f, 0.0f),
        glm::vec2(1.0f, 0.0f)
    )
};

const std::vector<GLint> indexes = { 
    0, 1, 2, // First triangle
    1, 2, 3  // Second triangle
};

std::map<std::string, GLuint> loadTextures() {
    std::map<std::string, GLuint> textures = std::map<std::string, GLuint>();
    textures.insert(std::make_pair("DVD_LOGO", loadTexture( "assets/dvd.png")));
    return textures;
}

void updateLogoPosition(const uint32_t& logoTransformLocation, glm::vec2& dvdLogoPosition, const glm::vec2& velocity, float deltaTime) {
    dvdLogoPosition.x += velocity.x * deltaTime;
    dvdLogoPosition.y += velocity.y * deltaTime;
    glUniform2f(logoTransformLocation, dvdLogoPosition.x, dvdLogoPosition.y);
}

bool updateDirectionOnCollision(const glm::vec2& dvdLogoPosition, glm::vec2& velocity) {
    float widthBound = 1 - DVD_WIDTH / 2;
    float heightBound = 1 - DVD_HEIGHT / 2;
    bool touchesRightOrLeft = dvdLogoPosition.x >= widthBound || dvdLogoPosition.x <= -widthBound;
    bool touchesUpperOrLower = dvdLogoPosition.y <= -heightBound || dvdLogoPosition.y >= heightBound;

    if (touchesRightOrLeft || touchesUpperOrLower) {
        if (touchesRightOrLeft) velocity.x *= -1;
        if (touchesUpperOrLower) velocity.y *= -1;
        return true;
    }
    return false;
}

void updateLogoColor(const uint32_t& logoColorLocation) {
    float r = get_random_between(0, 1);
    float g = get_random_between(0, 1);
    float b = get_random_between(0, 1);
    glUniform3f(logoColorLocation, r, g, b);
}

int main(int argc, char** argv) {
    initGlfw();
    GLFWwindow* window = createWindow(WINDOW_TITLE, WIDTH, HEIGHT);

    // Create shader program
    int shaderProgramId = createShaderProgram("shaders/vertex.glsl", "shaders/fragment.glsl");

    // Activate shader and get uniforms
    glUseProgram(shaderProgramId);
    unsigned int logoColorLocation = glGetUniformLocation(shaderProgramId, "textureColor");
    unsigned int logoTransformLocation = glGetUniformLocation(shaderProgramId, "transform");

    // Get dvd logo texture id and load mesh
    std::map<std::string, GLuint> textures = loadTextures();
    unsigned int dvdLogoTextureId = textures.find("DVD_LOGO")->second;
    Mesh mesh = loadMesh(vertices, indexes);

    // Set initial color and position
    glUniform3f(logoColorLocation, 1.0f, 1.0f, 1.0f);
    glm::vec2 dvdLogoPosition = glm::vec2(0.f, 0.f);
    glm::vec2 velocity = glm::vec2(DVD_SPEED, DVD_SPEED);

    float deltaTime, lastTime = 0.0f;
    while (!glfwWindowShouldClose(window)) {
        // Clean color buffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Calculate delta time
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Update logo position
        updateLogoPosition(logoTransformLocation, dvdLogoPosition, velocity, deltaTime);

        // Check if there is any collision and update color accordingly
        bool hasCollided = updateDirectionOnCollision(dvdLogoPosition, velocity);
        if (hasCollided) updateLogoColor(logoColorLocation);
        
        // Bind and render
        glBindTexture(GL_TEXTURE_2D, dvdLogoTextureId);
        drawMesh(mesh);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Cleanup
    unloadTexture(dvdLogoTextureId);
    unloadMesh(mesh);
    destroyWindow(window);
}
