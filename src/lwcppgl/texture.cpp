#include "texture.hpp"

Texture::Texture(const char *filename) {
  SDL_Surface *image = IMG_Load(filename);

  GLuint colors = image->format->BytesPerPixel;
  GLenum format = colors == 4 ? GL_RGBA : GL_RGB;

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, colors, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);

  SDL_FreeSurface(image);
}



Texture::~Texture() {
  glDeleteTextures(1, &texture);
}
