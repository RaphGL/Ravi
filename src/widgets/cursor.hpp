#ifndef CURSOR_HPP
#define CURSOR_HPP

#include <SDL2/SDL.h>
#include "../window_renderer.hpp"

class Cursor
{
    SDL_Rect cursor;
    WindowRenderer &wrenderer;

public:
    Cursor(WindowRenderer &wrenderer);

    void draw();

    void move_to(int x, int y);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
};

#endif
