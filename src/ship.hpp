#ifndef SHIP_HPP
#define SHIP_HPP

#include "entity.hpp"

class Ship : public Entity {
  public:
    Ship();
    Ship(glm::vec2 &);
    void update(GLuint);
    void thrust(GLuint);

  private:
    glm::vec2 velocity;
    GLfloat acceleration;
};

#endif // SHIP_HPP
