#include <SDL2/SDL.h>
#include <string>
#include "statusbar.hpp"
#include "../window_renderer.hpp"
#include <iostream>

StatusBar::StatusBar(WindowRenderer &wrenderer) : wrenderer{wrenderer} {}


void StatusBar::draw()
{
    statusbar.w = wrenderer.width;
    statusbar.h = wrenderer.char_height * 1.5;
    statusbar.x = 0;
    statusbar.y = wrenderer.height - statusbar.h * 2;
    SDL_SetRenderDrawColor(wrenderer.renderer, 0x44, 0x47, 0x5A, 0xFF);
    SDL_RenderFillRect(wrenderer.renderer, &statusbar);

    const int text_centered_y = statusbar.y + wrenderer.char_height / 6;
    SDL_Color text_color = {0xFF, 0xFF, 0xFF, 0xFF};

    // Current Mode text
    auto mode_surface = TTF_RenderText_Blended(wrenderer.font, curr_mode.c_str(), text_color);
    auto mode_texture = SDL_CreateTextureFromSurface(wrenderer.renderer, mode_surface);
    SDL_Rect mode_rect;
    SDL_QueryTexture(mode_texture, nullptr, nullptr, &mode_rect.w, &mode_rect.h);
    mode_rect.x = wrenderer.char_width * 2;
    mode_rect.y = text_centered_y;
    SDL_RenderCopy(wrenderer.renderer, mode_texture, nullptr, &mode_rect);

    // Opened File text  
    SDL_Rect file_rect;
    auto file_surface = TTF_RenderText_Blended(wrenderer.font, opened_file.c_str(), text_color);
    auto file_texture = SDL_CreateTextureFromSurface(wrenderer.renderer, file_surface);
    SDL_QueryTexture(file_texture, nullptr, nullptr, &file_rect.w, &file_rect.h);

    file_rect.x = mode_rect.x * 2 + mode_rect.w;
    file_rect.y = text_centered_y;
    SDL_RenderCopy(wrenderer.renderer, file_texture, nullptr, &file_rect);

    // Line Number text
    SDL_Rect linenum_rect;
    auto linenum_surface = TTF_RenderText_Blended(wrenderer.font, linenum.c_str(), text_color);
    auto linenum_texture = SDL_CreateTextureFromSurface(wrenderer.renderer, linenum_surface);
    SDL_QueryTexture(linenum_texture, nullptr, nullptr, &linenum_rect.w, &linenum_rect.h);

    linenum_rect.x =  wrenderer.width - linenum_rect.w - wrenderer.char_width * 2;
    linenum_rect.y = text_centered_y;
    SDL_RenderCopy(wrenderer.renderer, linenum_texture, nullptr, &linenum_rect);

    SDL_DestroyTexture(file_texture);
    SDL_DestroyTexture(mode_texture);
    SDL_DestroyTexture(linenum_texture);
    SDL_FreeSurface(file_surface);
    SDL_FreeSurface(mode_surface);
    SDL_FreeSurface(linenum_surface);
}

void StatusBar::set_linenum(int row, int col)
{
    std::string line_number{};
    line_number = std::to_string(col) + ":" + std::to_string(row);
    linenum = line_number;
}

void StatusBar::set_opened_file(std::string filename)
{
    opened_file = filename;
}

void StatusBar::set_mode(std::string mode) {
    curr_mode = mode;
}