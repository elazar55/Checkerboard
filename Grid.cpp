#include "Grid.h"

Grid::Grid(int x_divisions, int y_divisions, GLuint program_ID)
{
    this->x_divisions = x_divisions;
    this->y_divisions = y_divisions;

    grid_data.resize(x_divisions * y_divisions * 3, 0);
    GLubyte color_r = (rand() % 230) + 10;
    GLubyte color_g = (rand() % 230) + 10;
    GLubyte color_b = (rand() % 230) + 10;

    for (size_t i = 0; i < grid_data.size(); i += 3)
    {
        if (rand() % 2)
        {
            grid_data[i + 0] = color_r;
            grid_data[i + 1] = color_g;
            grid_data[i + 2] = color_b;
        }
        else
        {
            grid_data[i + 0] = ~color_r;
            grid_data[i + 1] = ~color_g;
            grid_data[i + 2] = ~color_b;
        }
    }

    grid_copy = grid_data;

    x_divisions_location = glGetUniformLocation(program_ID, "x_divisions");
    y_divisions_location = glGetUniformLocation(program_ID, "y_divisions");

    glUniform1iv(x_divisions_location, 1, &x_divisions);
    glUniform1iv(y_divisions_location, 1, &y_divisions);

    glGenTextures(1, &grid_texture);
    glBindTexture(GL_TEXTURE_1D, grid_texture);

    glTexImage1D(GL_TEXTURE_1D,         // Target
                 0,                     // Level
                 GL_RGB,                // Internal Format
                 grid_data.size() / 3,  // Width
                 0,                     // Border
                 GL_RGB,                // Format
                 GL_UNSIGNED_BYTE,      // Type
                 grid_data.data());     // Pixels

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Grid::~Grid() { glDeleteTextures(1, &grid_texture); }

void Grid::Render()
{
    glTexSubImage1D(GL_TEXTURE_1D,         // Target
                    0,                     // Level
                    0,                     // Offset
                    grid_data.size() / 3,  // Width
                    GL_RGB,                // Format
                    GL_UNSIGNED_BYTE,      // Type
                    grid_data.data());     // Pixels

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Grid::HandleMouse(Mouse& mouse)
{
    int x_seperator = (800 / x_divisions);
    int y_seperator = (600 / y_divisions);

    int index = (mouse.GetX() / x_seperator) +
                (x_divisions * ((y_divisions - 1) -  // Inverted Y Axis
                (mouse.GetY() / y_seperator)));

    int ix = index % x_divisions;
    int iy = index / x_divisions;

    index *= 3;

    grid_data = grid_copy;
    grid_copy = grid_data;

    if (mouse.LeftClick())
    {
        cout << "X: " << ix << endl << "Y: " << iy << endl;
        // Center
        grid_data[index + 0] = ~grid_data[index + 0];
        grid_data[index + 1] = ~grid_data[index + 1];
        grid_data[index + 2] = ~grid_data[index + 2];

        // Top
        if (iy < y_divisions - 1)
        {
            grid_data[index + x_divisions * 3 + 0] = ~grid_data[index + x_divisions * 3 + 0];
            grid_data[index + x_divisions * 3 + 1] = ~grid_data[index + x_divisions * 3 + 1];
            grid_data[index + x_divisions * 3 + 2] = ~grid_data[index + x_divisions * 3 + 2];
        }

        // Bottom
        if (iy > 0)
        {
            grid_data[index - x_divisions * 3 + 0] = ~grid_data[index - x_divisions * 3 + 0];
            grid_data[index - x_divisions * 3 + 1] = ~grid_data[index - x_divisions * 3 + 1];
            grid_data[index - x_divisions * 3 + 2] = ~grid_data[index - x_divisions * 3 + 2];
        }

        // Left
        if (ix > 0)
        {
            grid_data[index - 1] = ~grid_data[index - 1];
            grid_data[index - 2] = ~grid_data[index - 2];
            grid_data[index - 3] = ~grid_data[index - 3];
        }

        // Right
        if (ix < x_divisions - 1)
        {
            grid_data[index + 3] = ~grid_data[index + 3];
            grid_data[index + 4] = ~grid_data[index + 4];
            grid_data[index + 5] = ~grid_data[index + 5];
        }

        grid_copy = grid_data;
    }
    // Hovering over a square
    else
    {
        // Center
        grid_data[index + 0] = grid_copy[index + 0] + 10;
        grid_data[index + 1] = grid_copy[index + 1] + 10;
        grid_data[index + 2] = grid_copy[index + 2] + 10;

        // Top
        if (iy < y_divisions - 1)
        {
            grid_data[index + x_divisions * 3 + 0] = grid_copy[index + x_divisions * 3 + 0] + 10;
            grid_data[index + x_divisions * 3 + 1] = grid_copy[index + x_divisions * 3 + 1] + 10;
            grid_data[index + x_divisions * 3 + 2] = grid_copy[index + x_divisions * 3 + 2] + 10;
        }

        // Bottom
        if (iy > 0)
        {
            grid_data[index - x_divisions * 3 + 0] = grid_copy[index - x_divisions * 3 + 0] + 10;
            grid_data[index - x_divisions * 3 + 1] = grid_copy[index - x_divisions * 3 + 1] + 10;
            grid_data[index - x_divisions * 3 + 2] = grid_copy[index - x_divisions * 3 + 2] + 10;
        }

        // Left
        if (ix > 0)
        {
            grid_data[index - 1] = grid_data[index - 1] + 10;
            grid_data[index - 2] = grid_data[index - 2] + 10;
            grid_data[index - 3] = grid_data[index - 3] + 10;
        }

        // Right
        if (ix < x_divisions - 1)
        {
            grid_data[index + 3] = grid_data[index + 3] + 10;
            grid_data[index + 4] = grid_data[index + 4] + 10;
            grid_data[index + 5] = grid_data[index + 5] + 10;
        }
    }
}

bool Grid::IsSolved()
{
    for (size_t i = 0; i < grid_data.size() - 3; i +=3 )
    {
        GLubyte color_r = grid_data[i + 0];
        GLubyte color_g = grid_data[i + 1];
        GLubyte color_b = grid_data[i + 2];

        GLubyte next_color_r = grid_data[i + 3];
        GLubyte next_color_g = grid_data[i + 4];
        GLubyte next_color_b = grid_data[i + 5];

        if (color_r != next_color_r)
        if (color_g != next_color_g)
        if (color_b != next_color_b)
        {
            return false;
        }
    }

    return true;
}
