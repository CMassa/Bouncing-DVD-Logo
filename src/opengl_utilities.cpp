#include "../include/opengl_utilities.h"

Mesh loadMesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t> indexes) {
    // Vertex Array Object (VAO) / Vertex Buffer Object (VBO) / Element Buffer Object (EBO)
    uint32_t VAO, VBO, EBO; 

    // Setup VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Setup VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Setup EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes.data(), GL_STATIC_DRAW);

    // Cleanup
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    return Mesh(VAO, indexes.size());
}

void unloadMesh(const Mesh& mesh) {
    glDeleteBuffers(1, &mesh.vao);
}

void drawMesh(const Mesh& mesh) {
    glBindVertexArray(mesh.vao);
    glDrawElements(GL_TRIANGLES, mesh.numberOfIndexes, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}