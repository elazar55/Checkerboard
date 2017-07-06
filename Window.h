#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <string>

using namespace std;

class Window
{
  public:
    Window();
    ~Window();

    void        RenderPresent();
    bool        IsRunning();
    SDL_Window* GetID();
    int         GetWidth();
    int         GetHeight();
    void        HandleInput(SDL_Event& event);

  private:
    bool          quit;
    int           window_width_value;
    int           window_height_value;
    int           x_position;
    int           y_position;
    SDL_Window*   window;
    SDL_GLContext context;
};

#endif  // WINDOW_H
