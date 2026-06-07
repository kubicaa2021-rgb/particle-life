#include "particle.h"
#include "physics.h"
#include "settings.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <cstdint>
#include <vector>
#include <windowHelper.h>
int main(int argc, char *argv[]) {
  WindowHelper win;
  PhysicsHandler ph;
  if (win.setup() == 1) {
    return 1;
  }

  std::vector<Particle> particles(2, Particle());
  Particle test;
  test.weight = 100;
  test.pos = {100, 100};
  test.force = {100, 0};

  particles[1].weight = 500;
  particles[1].pos = {500, 500};

  // Time setup - FPS deltaTime
  const uint_fast32_t TARGET_FRAME_TIME = 1000 / 60;
  uint_fast64_t lastTime = SDL_GetPerformanceCounter();
  uint_fast64_t frequency = SDL_GetPerformanceFrequency();

  bool done = false;
  SDL_Event event;
  while (!done) {
    // Get start time
    uint_fast32_t frameStart = SDL_GetTicks();

    // Delta time
    uint_fast64_t currentTime = SDL_GetPerformanceCounter();
    Settings::deltaTime = (float)(currentTime - lastTime) / (float)frequency;
    lastTime = currentTime;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }
    // Draw background
    SDL_SetRenderDrawColor(win.renderer, Settings::bg.r, Settings::bg.g,
                           Settings::bg.b, Settings::bg.a);
    SDL_RenderClear(win.renderer);

    PhysicsHandler::applyForce(&test);
    PhysicsHandler::applySpeed(&test);
    test.draw(win.renderer);

    SDL_RenderPresent(win.renderer);

    // FPS capping
    uint_fast32_t frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < TARGET_FRAME_TIME) {
      SDL_Delay(TARGET_FRAME_TIME - frameTime);
    }
  }

  SDL_DestroyRenderer(win.renderer);
  SDL_DestroyWindow(win.window);
  SDL_Quit();

  return 0;
}
