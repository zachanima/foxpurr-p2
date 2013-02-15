#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "lwcppgl/display.hpp"
#include "lwcppgl/texture.hpp"

#include "vertex.hpp"

class Entity {
  public:
    Entity();
    Entity(glm::vec2 &);
    ~Entity();
    static GLvoid initialize();
    GLvoid update(GLuint);
    GLvoid render(GLuint);

  protected:
    GLfloat angularVelocity;
    glm::vec2 position;
    GLfloat rotation;

  private:
    static GLuint ibo;
    static GLuint vbo;
    static Texture *texture;
};

#endif // ENTITY_HPP
