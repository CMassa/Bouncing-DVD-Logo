#pragma once

struct Mesh {

    uint32_t vao = 0;
    uint32_t numberOfIndexes = 0;

    Mesh(uint32_t vao, uint32_t numberOfIndexes) {
        vao = vao;
        numberOfIndexes = numberOfIndexes;
    };
};