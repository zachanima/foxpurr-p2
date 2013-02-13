#ifndef OCTREE_HPP
#define OCTREE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "lwcppgl/display.hpp"
#include "vertex.hpp"

class Entity {
  public:
    Entity();
    Entity(glm::vec2 &);
    ~Entity();
    static GLvoid initialize();
    GLvoid update(GLuint);
    GLvoid render(GLuint);

  private:
    glm::vec2 position;
    static GLuint ibo;
    static GLuint vbo;
};

#endif // OCTREE_HPP
