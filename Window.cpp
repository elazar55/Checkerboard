#include "Window.h"

Window::Window()
{
    // Parameters
    window_width_value  = 800;
    window_height_value = 600;
    x_position          = 200;
    y_position          = 200;
    quit                = false;
    string title        = "Checkerboard";
    Uint32 flags        = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    // Attributes
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

    // Creates and initializes window and contexts
    window  = SDL_CreateWindow(title.c_str(),        // Title
                               x_position,           // X
                               y_position,           // Y
                               window_width_value,   // Width
                               window_height_value,  // Height
                               flags);               // Flags
    context = SDL_GL_CreateContext(window);
}

Window::~Window()
{
}

void Window::HandleInput(SDL_Event& event)
{
    if (event.type == SDL_QUIT) quit = true;
}

bool Window::IsRunning()
{
    if (quit == false) return true;
                       return false;
}

SDL_Window* Window::GetID()
{
    return window;
}

void Window::RenderPresent()
{
    SDL_GL_SwapWindow(window);
}

int Window::GetWidth()
{
    return window_width_value;
}

int Window::GetHeight()
{
    return window_height_value;
}
