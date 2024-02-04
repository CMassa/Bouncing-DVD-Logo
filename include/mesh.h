#pragma once

struct Mesh {

    uint32_t vao = 0;
    uint32_t numberOfIndexes = 0;

    Mesh(uint32_t v, uint32_t i) {
        vao = v;
        numberOfIndexes = i;
    };
};