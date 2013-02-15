#include "game.hpp"

GLuint Game::program;
GLuint Game::viewUniform;
Ship *Game::player;



GLvoid Game::initialize() {
  const GLfloat HALF_WIDTH = (GLfloat)WIDTH / 2.f;
  const GLfloat HALF_HEIGHT = (GLfloat)HEIGHT / 2.f;
  const glm::mat4 projection = glm::ortho(-HALF_WIDTH, HALF_WIDTH, -HALF_HEIGHT, HALF_HEIGHT, -1.f, 1.f);
  GLuint projectionUniform;

  // Initialize shaders.
  program = Display::shaders("render.vert", "render.frag");

  // Initialize entity.
  Entity::initialize();
  player = new Ship();

  // Initialize uniforms.
  viewUniform =       glGetUniformLocation(program, "view");
  projectionUniform = glGetUniformLocation(program, "projection");
  
  // Apply uniforms.
  glUseProgram(program);
  glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, glm::value_ptr(projection));
  glUseProgram(0);

  // Initialize render settings.
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



GLvoid Game::deinitialize() {
}



GLvoid Game::update() {
  static GLuint ticks = SDL_GetTicks();
  const GLuint delta = SDL_GetTicks() - ticks;
  ticks = SDL_GetTicks();

  if (Keyboard::isKeyDown(KEY_A)) { player->rotateLeft(delta); }
  if (Keyboard::isKeyDown(KEY_D)) { player->rotateRight(delta); }
  if (Keyboard::isKeyDown(KEY_S)) { player->reverse(delta); }
  if (Keyboard::isKeyDown(KEY_W)) { player->thrust(delta); }

  player->update(delta);
}



GLvoid Game::render() {
  glm::mat4 view(1.f);
  // view = glm::translate(view, -camera.position);

  glClearColor(0.f, 0.f, 0.0, 1.f);
  glClearDepth(1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  // glEnable(GL_CULL_FACE);
  // glEnable(GL_TEXTURE_2D);

  glUseProgram(program);

  glUniformMatrix4fv(viewUniform,      1, GL_FALSE, glm::value_ptr(view));

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  player->render(program);
  // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glUseProgram(0);
}
