#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <windowHelper.h>
int main(int argc, char *argv[]) {
  windowHelper win;
  win.setup();

  bool done = false;
  SDL_Event event;
  while (!done) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }

    SDL_SetRenderDrawColor(win.renderer, 0, 0, 0, 255);
    SDL_RenderClear(win.renderer);

    SDL_RenderPresent(win.renderer);
  }

  SDL_DestroyRenderer(win.renderer);
  SDL_DestroyWindow(win.window);
  SDL_Quit();

  return 0;
}
