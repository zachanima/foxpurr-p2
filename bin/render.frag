#version 140
 
in vec2 vertexPosition;
in vec2 vertexTexture;

out vec4 color;

uniform sampler2D sampler;
uniform int sprite;

void main(void) {
  color = texture2D(sampler, vertexTexture + vec2(sprite, 0.f) / 24.f);
}
