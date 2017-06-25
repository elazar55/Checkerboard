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

int main(int argc, char** argv)
{
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
    Grid grid(16, 12, program.GetID());

    // Loop
    GLuint    vao;
    SDL_Event event;
    Mouse mouse;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while (window.IsRunning())
    {
        mouse.Update();

        grid.HandleMouse(mouse);
        grid.Render();

        window.HandleInput(event);
        window.RenderPresent();
    }

    return 0;
}
