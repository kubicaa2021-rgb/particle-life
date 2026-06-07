#pragma once
#include <SDL3/SDL_pixels.h>
/// Basic windows settings
/// and deltaTime variable
class Settings {
public:
  static constexpr int WIDTH = 1000;
  static constexpr int HEIGHT = 600;
  static constexpr SDL_Color bg = {0, 0, 0, 255};
  inline static float deltaTime;
};
