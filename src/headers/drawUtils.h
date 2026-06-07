#pragma once
#include "vector2.h"
#include <SDL3/SDL.h>
class DrawUtils {
public:
  static void drawCircle(SDL_Renderer *rn, vector2 *pos, SDL_Color *color);
};

inline void DrawUtils::drawCircle(SDL_Renderer *rn, vector2 *pos,
                                  SDL_Color *color) {
  SDL_FRect rec = {pos->x, pos->y, 5, 5};
  SDL_SetRenderDrawColor(rn, color->r, color->g, color->b, color->a);
  SDL_RenderFillRect(rn, &rec);
}
