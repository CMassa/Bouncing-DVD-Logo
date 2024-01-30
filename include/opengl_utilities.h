#pragma once

Mesh loadMesh(const std::vector<Vertex>& vertices, const std::vector<GLint> indexs);

void unloadMesh(const Mesh& mesh);

void drawMesh(const Mesh& mesh);