#version 140
 
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texture;

out vec2 vertexPosition;
out vec2 vertexTexture;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void) {
  gl_Position = projection * view * model * vec4(position, 0.f, 1.f);
  vertexPosition = position;
  vertexTexture = texture;
}
