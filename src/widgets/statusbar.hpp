#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <SDL2/SDL.h>
#include "../window_renderer.hpp"

class StatusBar
{
    SDL_Rect statusbar;
    WindowRenderer &wrenderer;

public:
    StatusBar(WindowRenderer &wrenderer); 

    void draw();
};

#endif
