#include "ship.hpp"



Ship::Ship() : Entity(),
  acceleration(256.f),
  reverseAcceleration(256.f),
  rotationalAcceleration(4.f) {
}



Ship::Ship(glm::vec2 &position) :
  Entity(position),
  acceleration(256.f),
  reverseAcceleration(256.f),
  rotationalAcceleration(4.f) {
}



void Ship::reverse(GLuint delta) {
  velocity -= glm::vec2(glm::cos(rotation), glm::sin(rotation)) *
    reverseAcceleration * (GLfloat)delta * .001f;
}



void Ship::rotateLeft(GLuint delta) {
  angularVelocity += rotationalAcceleration * (GLfloat)delta * .001f;
}



void Ship::rotateRight(GLuint delta) {
  angularVelocity -= rotationalAcceleration * (GLfloat)delta * .001f;
}



void Ship::thrust(GLuint delta) {
  velocity += glm::vec2(glm::cos(rotation), glm::sin(rotation)) *
    acceleration * (GLfloat)delta * .001f;
}



void Ship::update(GLuint delta) {
  position += velocity * (GLfloat)delta * .001f;
  rotation += angularVelocity * (GLfloat)delta * .001f;
}
