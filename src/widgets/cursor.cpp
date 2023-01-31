#include <SDL2/SDL.h>
#include "../window_renderer.hpp"
#include "cursor.hpp"
#include <tuple>

Cursor::Cursor(WindowRenderer &wrenderer) : wrenderer{wrenderer}
{
    cursor.h = wrenderer.char_height;
    cursor.w = wrenderer.char_width;
    cursor.x = 0;
    cursor.y = 0;
}

std::tuple<int, int> Cursor::get_coordinates()
{
    return std::make_tuple(cursor.x / cursor.w, cursor.y / cursor.h);
}

void Cursor::draw()
{
    SDL_SetRenderDrawColor(wrenderer.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(wrenderer.renderer, &cursor);
}

// TODO make it change with offset cursor.w and cursor.h
void Cursor::move_to(int x, int y)
{
    cursor.x = x * cursor.w;
    cursor.y = y * cursor.h;
}

void Cursor::move_left()
{
    if (cursor.x > 0)
        cursor.x -= cursor.w;
}

void Cursor::move_right()
{
    if (cursor.x < wrenderer.width - cursor.w * 2)
        cursor.x += cursor.w;
}

void Cursor::move_up()
{
    if (cursor.y > 0)
        cursor.y -= cursor.h;
}

void Cursor::move_down()
{
    if (cursor.y < wrenderer.height - cursor.h)
        cursor.y += cursor.h;
}
