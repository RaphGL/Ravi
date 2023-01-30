#include <SDL2/SDL.h>
#include "statusbar.hpp"
#include "../window_renderer.hpp"

StatusBar::StatusBar(WindowRenderer &wrenderer) : wrenderer{wrenderer} {}

void StatusBar::draw()
{
    statusbar.w = wrenderer.width;
    statusbar.h = wrenderer.char_height + 10;
    statusbar.x = 0;
    statusbar.y = wrenderer.height - 2 * wrenderer.char_height;
    SDL_SetRenderDrawColor(wrenderer.renderer, 0x44, 0x47, 0x5A, 0xFF);
    SDL_RenderFillRect(wrenderer.renderer, &statusbar);
}