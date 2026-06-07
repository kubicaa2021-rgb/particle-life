#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <settings.h>

class windowHelper {
public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  int setup();
};

inline int windowHelper::setup() {
  SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "wayland");
  window =
      SDL_CreateWindow("Particle Life", Settings::WIDTH, Settings::HEIGHT, 0);

  if (!window) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s",
                 SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, nullptr);
  if (!renderer) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s",
                 SDL_GetError());
    return 1;
  }
  return 0;
}
