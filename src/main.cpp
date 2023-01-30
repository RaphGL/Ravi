#include "window_renderer.hpp"
#include "widgets/statusbar.hpp"
#include "widgets/cursor.hpp"

int main()
{
    WindowRenderer wrenderer{};
    StatusBar statusbar{wrenderer};
    Cursor cursor{wrenderer};

    SDL_Event e;
    for (;;)
    {
        wrenderer.clear();
        statusbar.draw();
        cursor.draw();
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_h:
                    cursor.move_left();
                    break;
                case SDLK_l:
                    cursor.move_right();
                    break;
                case SDLK_j:
                    cursor.move_down();
                    break;
                case SDLK_k:
                    cursor.move_up();
                    break;
                }
                break;
            case SDL_QUIT:
                return 0;
                break;
            }
        }
        wrenderer.present();
    }
    return 0;
}