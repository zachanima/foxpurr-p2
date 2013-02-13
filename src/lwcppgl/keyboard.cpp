#include "keyboard.hpp"

bool Keyboard::key[KEYS];

void Keyboard::update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_ESCAPE: key[KEY_ESCAPE] = true; break;
        case SDLK_LEFT: key[KEY_LEFT] = true; break;
        case SDLK_RIGHT: key[KEY_RIGHT] = true; break;
        case SDLK_UP: key[KEY_UP] = true; break;
        case SDLK_DOWN: key[KEY_DOWN] = true; break;
        case SDLK_a: key[KEY_A] = true; break;
        case SDLK_d: key[KEY_D] = true; break;
        case SDLK_e: key[KEY_E] = true; break;
        case SDLK_f: key[KEY_F] = true; break;
        case SDLK_q: key[KEY_Q] = true; break;
        case SDLK_r: key[KEY_R] = true; break;
        case SDLK_s: key[KEY_S] = true; break;
        case SDLK_w: key[KEY_W] = true; break;
        default: break;
      }
    }
    if (event.type == SDL_KEYUP) {
      switch(event.key.keysym.sym) {
        case SDLK_ESCAPE: key[KEY_ESCAPE] = false; break;
        case SDLK_LEFT: key[KEY_LEFT] = false; break;
        case SDLK_RIGHT: key[KEY_RIGHT] = false; break;
        case SDLK_UP: key[KEY_UP] = false; break;
        case SDLK_DOWN: key[KEY_DOWN] = false; break;
        case SDLK_a: key[KEY_A] = false; break;
        case SDLK_d: key[KEY_D] = false; break;
        case SDLK_e: key[KEY_E] = false; break;
        case SDLK_f: key[KEY_F] = false; break;
        case SDLK_q: key[KEY_Q] = false; break;
        case SDLK_r: key[KEY_R] = false; break;
        case SDLK_s: key[KEY_S] = false; break;
        case SDLK_w: key[KEY_W] = false; break;
        default: break;
      }
    }
  }
}

bool Keyboard::isKeyDown(int code) {
  return key[code];
}
