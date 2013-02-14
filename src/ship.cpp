#include "ship.hpp"



Ship::Ship() : Entity(), acceleration(256.f) {
}



Ship::Ship(glm::vec2 &position) : Entity(position), acceleration(256.f) {
}



void Ship::update(GLuint delta) {
  position += velocity * (GLfloat)delta * .001f;
}



void Ship::thrust(GLuint delta) {
  velocity += glm::vec2(glm::cos(-rotation), glm::sin(-rotation)) *
    acceleration * (GLfloat)delta * .001f;
}
