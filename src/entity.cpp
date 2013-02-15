#include "entity.hpp"

GLuint Entity::ibo;
GLuint Entity::vbo;
Texture *Entity::texture;



Entity::Entity() :
  angularVelocity(0.f),
  rotation(0.f) {
}



Entity::Entity(glm::vec2 &position) :
  angularVelocity(0.f),
  position(position),
  rotation(0.f) {
}



Entity::~Entity() {
}



GLvoid Entity::initialize() {
  const GLfloat offset = 1.f / 24.f; // Texture offset.
  Vertex vs[4];
  vs[0].r = glm::vec2(-.5f, -.5f); vs[0].t = glm::vec2(0.f, 1.f);
  vs[1].r = glm::vec2(-.5f,  .5f); vs[1].t = glm::vec2(0.f, 0.f);
  vs[2].r = glm::vec2( .5f, -.5f); vs[2].t = glm::vec2(offset, 1.f);
  vs[3].r = glm::vec2( .5f,  .5f); vs[3].t = glm::vec2(offset, 0.f);

  // Assign indices.
  GLuint is[4] = { 0, 1, 2, 3 };

  // Initialize texture.
  texture = new Texture("ship.png");

  // Initialize vertex buffer object.
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vs, GL_STATIC_DRAW);

  // Initialize index buffer object.
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), is, GL_STATIC_DRAW);
}



GLvoid Entity::render(GLuint program) {
  const static GLuint modelUniform = glGetUniformLocation(program, "model");
  const static GLuint samplerUniform = glGetUniformLocation(program, "sampler");
  const static GLuint spriteUniform = glGetUniformLocation(program, "sprite");
  const glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.f), glm::vec3(position, 0.f)), glm::vec3(16.f));

  glUniformMatrix4fv(modelUniform, 1, GL_FALSE, glm::value_ptr(model));
  glUniform1i(samplerUniform, 0);
  glUniform1i(spriteUniform, (int)(24.f * rotation / 6.283185307179586f));

  glBindTexture(GL_TEXTURE_2D, texture->texture);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, r));
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, t));

  glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (GLvoid *)0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}



GLvoid Entity::update(GLuint delta) {
}
