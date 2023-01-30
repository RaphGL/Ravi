#include <SDL2/SDL.h>
#include "../window_renderer.hpp"
#include "cursor.hpp"

Cursor::Cursor(WindowRenderer &wrenderer) : wrenderer{wrenderer}
{
    cursor.h = wrenderer.char_height;
    cursor.w = wrenderer.char_width;
    cursor.x = 0;
    cursor.y = 0;
}

void Cursor::draw()
{
    SDL_SetRenderDrawColor(wrenderer.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(wrenderer.renderer, &cursor);
}

// TODO make it change with offset cursor.w and cursor.h
void Cursor::move_to(int x, int y)
{
    cursor.x = x;
    cursor.y = y;
}

void Cursor::move_left()
{
    if (cursor.x > 0)
        cursor.x -= cursor.w;
}

void Cursor::move_right()
{
    if (cursor.x < wrenderer.width - cursor.w)
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