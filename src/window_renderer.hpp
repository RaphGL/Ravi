#ifndef WINDOW_RENDERER_H
#define WINDOW_RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class WindowRenderer
{
private:
    int bg_r, bg_g, bg_b;
    SDL_Window *window;
public:
    SDL_Renderer *renderer;
    int width;
    int height;
    int char_height;
    int char_width;

    TTF_Font *font;

    WindowRenderer();
    ~WindowRenderer();

    void present();
    void clear();
};

#endif