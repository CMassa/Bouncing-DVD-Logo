#pragma once

struct Vertex {
    
    Vertex(float x, float y, float z, float t1, float t2) {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        t[0] = t1;
        t[1] = t2;
    }
    float c[3] = {0.f, 0.f, 0.f};
    float t[2] = {0.f, 0.f};
};