#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "window_renderer.hpp"
#include <iostream>

constexpr int default_width = 1024;
constexpr int default_height = 768;
constexpr int default_fontsize = 18;

WindowRenderer::WindowRenderer() : bg_r{0x19}, bg_g{0x19}, bg_b{0x1D}
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) 
    {
        std::cout << SDL_GetError() << std::endl;
        std::exit(1);
    }

    if (TTF_Init() < 0) {
        std::cerr << TTF_GetError() << std::endl;
        std::exit(1);
    }

    window = SDL_CreateWindow("Ravi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, default_width, default_height, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Could not create window." << std::endl;
        std::exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Could not create renderer context for the window." << std::endl;
    }

    font = TTF_OpenFont("./JetBrainsMono-Regular.ttf", default_fontsize);
    if (!font) {
        std::cerr << "Could not load font." << std::endl;
        std::exit(1);
    }

    // Get the width and height of the specified font
    auto *text_surface = TTF_RenderGlyph_Solid(font, 'a', SDL_Color{});
    auto *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_QueryTexture(text_texture, nullptr, nullptr, &char_width, &char_height);
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
