#pragma once
#include "drawUtils.h"
#include "vector2.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <cstdint>
#include <vector>

class Particle {
public:
  vector2 pos;
  vector2 force;
  vector2 speed;

  uint_fast16_t weight;
  uint_fast8_t typeNum = 0;
  static std::vector<SDL_Color> colors;

  Particle() = default;
  void draw(SDL_Renderer *rn);
};

/// Draws particle
inline void Particle::draw(SDL_Renderer *rn) {
  DrawUtils::drawCircle(rn, &pos, &colors[typeNum]);
}

inline std::vector<SDL_Color> Particle::colors = {{255, 0, 0, 255},
                                                  {0, 0, 255, 255}};
