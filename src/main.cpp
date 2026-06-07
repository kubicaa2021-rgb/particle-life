#include "particle.h"
#include "physics.h"
#include "settings.h"
#include <cstdint>
#include <windowHelper.h>
int main(int argc, char *argv[]) {
  WindowHelper win;
  PhysicsHandler ph;
  if (win.setup() == 1) {
    return 1;
  }

  Particle test;
  test.weight = 500000000000000;
  test.pos = {100, 100};
  test.speed = {0, 30};

  Particle test2;
  test2.weight = 500000000000000;
  test2.pos = {125, 125};

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
    Variables::deltaTime = ((float)(currentTime - lastTime) / (float)frequency);
    lastTime = currentTime;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }
    // Draw background
    SDL_SetRenderDrawColor(win.renderer, Variables::bg.r, Variables::bg.g,
                           Variables::bg.b, Variables::bg.a);
    SDL_RenderClear(win.renderer);

    PhysicsHandler::updateForces(&test, &test2);

    PhysicsHandler::applyForce(&test);
    PhysicsHandler::applyForce(&test2);

    PhysicsHandler::applySpeed(&test);
    PhysicsHandler::applySpeed(&test2);

    test.draw(win.renderer);
    test2.draw(win.renderer);

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
