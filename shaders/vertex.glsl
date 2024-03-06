#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoord;

out vec2 texCoord;

uniform vec2 transform;

void main() {
    gl_Position = vec4(aPos.xy + transform, aPos.z, 1.0);
    texCoord = aTexCoord;
}
