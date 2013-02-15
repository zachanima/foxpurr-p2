#ifndef SHIP_HPP
#define SHIP_HPP

#include "entity.hpp"

class Ship : public Entity {
  public:
    Ship();
    Ship(glm::vec2 &);
    void reverse(GLuint);
    void rotateLeft(GLuint);
    void rotateRight(GLuint);
    void thrust(GLuint);
    void update(GLuint);

  private:
    glm::vec2 velocity;
    GLfloat acceleration;
    GLfloat reverseAcceleration;
    GLfloat rotationalAcceleration;
};

#endif // SHIP_HPP
