#ifndef CURSOR_HPP
#define CURSOR_HPP

#include <SDL2/SDL.h>
#include "../window_renderer.hpp"
#include <tuple>

class Cursor
{
    int x;
    int y;
    SDL_Rect cursor;
    const WindowRenderer &wrenderer;

public:
    int lower_limit;
    Cursor(WindowRenderer &wrenderer, int lower_limit);
    std::tuple<int, int> get_coordinates();

    void draw();

    void move_to(int x, int y);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
};

#endif
