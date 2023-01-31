#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <SDL2/SDL.h>
#include "../window_renderer.hpp"
#include <string>

class StatusBar
{
private:
    SDL_Rect statusbar;
    WindowRenderer &wrenderer;
    std::string curr_mode;
    std::string opened_file;
    std::string linenum;

public:
    StatusBar(WindowRenderer &wrenderer);

    void draw();

    void set_linenum(int row, int col);
    void set_opened_file(std::string filename);
    void set_mode(std::string mode);
};

#endif
