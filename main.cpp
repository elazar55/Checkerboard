#include <windows.h>
#include <glew.h>
#include "Grid.h"
#include "Program.h"
#include "Window.h"
#include "Mouse.h"

using namespace std;

void APIENTRY gl_callback(GLenum        source,
                          GLenum        type,
                          GLuint        id,
                          GLenum        severity,
                          GLsizei       length,
                          const GLchar* msg,
                          const void*   user_param)
{
    cout << msg << endl;
    if (severity == GL_DEBUG_SEVERITY_HIGH) exit(id);
}


void HandleKeys(SDL_Event& event, Grid* grid, GLuint program_ID, Mouse& mouse)
{
    if (event.key.keysym.sym == SDLK_r && event.key.state  == SDL_PRESSED)
    {
        delete grid;
        grid = new Grid(16, 12, program_ID);
    }
    if (mouse.LeftClick())
    {
        if (grid->IsSolved())
        {
            cout << "Solved!" << endl;

            delete grid;
            grid = new Grid(16, 12, program_ID);
        }
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    Window window;

    // Gets all the functions for OpenGL
    glewInit();
    glDebugMessageCallback(&gl_callback, nullptr);

    // OpenGL shaders
    Program program;
    program.AddShader("../main.vert", GL_VERTEX_SHADER);
    program.AddShader("../main.frag", GL_FRAGMENT_SHADER);
    program.Link();
    glUseProgram(program.GetID());

    // Uniforms for the program
    GLuint window_width_uniform  = glGetUniformLocation(program.GetID(), "window_width");
    GLuint window_height_uniform = glGetUniformLocation(program.GetID(), "window_height");
    glUniform1i(window_width_uniform,  window.GetWidth());
    glUniform1i(window_height_uniform, window.GetHeight());

    // Grid
    Grid* grid = new Grid(16, 12, program.GetID());

    // Input objects
    Mouse     mouse;
    SDL_Event event;

    GLuint    vao;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Loop
    while (window.IsRunning())
    {
        // Polls all the inputs once, here
        mouse.Update();
        SDL_PollEvent(&event);

        grid->HandleMouse(mouse);
        grid->Render();

        window.HandleInput(event);
        window.RenderPresent();

        HandleKeys(event, grid, program.GetID(), mouse);
    }

    return 0;
}
