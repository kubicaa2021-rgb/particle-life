#include "particle.h"
#include "settings.h"
#include <SDL3/SDL_pixels.h>
#include <windowHelper.h>
int main(int argc, char *argv[]) {
  WindowHelper win;
  if (win.setup() == 1) {
    return 1;
  }

  Particle p = Particle();
  p.pos = {100, 100};

  bool done = false;
  SDL_Event event;
  while (!done) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }
    // Draw background
    SDL_SetRenderDrawColor(win.renderer, Settings::bg.r, Settings::bg.g,
                           Settings::bg.b, Settings::bg.a);
    SDL_RenderClear(win.renderer);

    p.draw(win.renderer);

    SDL_RenderPresent(win.renderer);
  }

  SDL_DestroyRenderer(win.renderer);
  SDL_DestroyWindow(win.window);
  SDL_Quit();

  return 0;
}
