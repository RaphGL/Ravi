#include <SDL2/SDL.h>
#include "../window_renderer.hpp"
#include "cursor.hpp"
#include <tuple>

Cursor::Cursor(WindowRenderer &wrenderer, int lower_limit) : x{0}, y{0}, wrenderer{wrenderer}, lower_limit{lower_limit}
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
    this->lower_limit = lower_limit - cursor.h;

    // Make cursor shrink to screen width and height when shrinking window
    {
        int maxx = wrenderer.width / cursor.w;
        int maxy = (wrenderer.height - (wrenderer.height - lower_limit)) / cursor.h;

        if (x >= maxx)
        {
            x = maxx;
        }
        if (y >= maxy)
        {
            y = maxy;
        }
        move_to(x, y);
    }

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
    if (x > 0)
    {
        --x;
    }
}

void Cursor::move_right()
{
    if (x < wrenderer.width / cursor.w)
    {
        ++x;
    }
}

void Cursor::move_up()
{
    if (cursor.y > 0)
    {
        --y;
    }
}

void Cursor::move_down()
{
    if (cursor.y < lower_limit)
    {
        ++y;
    }
}
