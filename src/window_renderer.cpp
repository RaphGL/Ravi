#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "window_renderer.hpp"

constexpr int default_width = 1024;
constexpr int default_height = 768;
constexpr int default_fontsize = 20;

WindowRenderer::WindowRenderer() : bg_r{0x19}, bg_g{0x19}, bg_b{0x1D}
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    TTF_Init();
    window = SDL_CreateWindow("Ravi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, default_width, default_height, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    font = TTF_OpenFont("./JetBrainsMono-Regular.ttf", default_fontsize);

    // Get the width and height of the specified font
    SDL_Surface *text_surface = TTF_RenderGlyph_Solid(font, 'a', SDL_Color{});
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_QueryTexture(text_texture, NULL, NULL, &char_width, &char_height);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

WindowRenderer::~WindowRenderer()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void WindowRenderer::present() {
    SDL_GetWindowSize(window, &width, &height);
    SDL_RenderPresent(renderer);
}

void WindowRenderer::clear() {
    SDL_SetRenderDrawColor(renderer, bg_r, bg_g, bg_b, 0xFF);
    SDL_RenderClear(renderer);
}
