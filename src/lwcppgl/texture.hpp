#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <SDL/SDL_image.h>

class Texture {
  public:
    Texture(const char *);
    ~Texture();
    GLuint texture;
};

#endif // TEXTURE_HPP
