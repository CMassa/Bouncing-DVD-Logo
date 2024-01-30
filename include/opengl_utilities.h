#pragma once

Mesh loadMesh(const std::vector<Vertex>& vertices, const std::vector<GLint> indexs);

void drawMesh(const Mesh& mesh);