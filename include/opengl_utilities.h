#pragma once

#include <glad/glad.h>
#include <vector>
#include "mesh.h"
#include "vertex.h"
#include "vertex.h"
#include "mesh.h"

Mesh loadMesh(const std::vector<Vertex>& vertices, const std::vector<GLint> indexs);

void unloadMesh(const Mesh& mesh);

void drawMesh(const Mesh& mesh);