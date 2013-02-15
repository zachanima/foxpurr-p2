#ifndef GAME_HPP
#define GAME_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "lwcppgl/display.hpp"
#include "lwcppgl/texture.hpp"

#include "entity.hpp"
#include "ship.hpp"

#define WIDTH (1280)
#define HEIGHT (720)

class Game {
  public:
    static GLvoid initialize();
    static GLvoid deinitialize();
    static GLvoid update();
    static GLvoid render();

  private:
    static GLuint viewUniform;
    static GLuint program;
    static Ship *player;
};

#endif // GAME_HPP
