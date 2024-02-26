#version 460 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D textureSampler;
uniform vec3 textureColor;

void main() {
    FragColor = texture(textureSampler, texCoord) * vec4(textureColor, 1.0);
}
