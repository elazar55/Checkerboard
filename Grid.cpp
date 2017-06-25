#include "Grid.h"

Grid::Grid(int x_divisions, int y_divisions, GLuint program_ID)
{
    this->x_divisions = x_divisions;
    this->y_divisions = y_divisions;

    grid_data.resize(x_divisions * y_divisions * 3, 0);
    srand(time(NULL));
    GLubyte color_r = rand() % 200;
    GLubyte color_g = rand() % 200;
    GLubyte color_b = rand() % 200;
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
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, grid_data.size() / 3, 0, GL_RGB, GL_UNSIGNED_BYTE, grid_data.data());
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Grid::~Grid()
{
}

void Grid::Render()
{
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, grid_data.size() / 3, 0, GL_RGB, GL_UNSIGNED_BYTE, grid_data.data()); // Fix this

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Grid::HandleMouse(Mouse& mouse)
{
    int x_seperator = (800 / x_divisions);
    int y_seperator = (600 / y_divisions);

    int index = (mouse.GetX() / x_seperator) + (x_divisions * ((y_divisions - 1) - // Inverted Y Axis
                (mouse.GetY() / y_seperator)));

    int ix = index % x_divisions;
    int iy = index / x_divisions;

    index *= 3;

    grid_data = grid_copy;
    grid_copy = grid_data;

    if (mouse.LeftClick())
    {
        cout << ix << " " << iy << endl;
        // Center
        grid_data[index + 0] = ~grid_data[index + 0];
        grid_data[index + 1] = ~grid_data[index + 1];
        grid_data[index + 2] = ~grid_data[index + 2];

        // Top
        if (index + x_divisions * 3 < (x_divisions * y_divisions) * 3)
        {
            grid_data[index + x_divisions * 3 + 0] = ~grid_data[index + x_divisions * 3 + 0];
            grid_data[index + x_divisions * 3 + 1] = ~grid_data[index + x_divisions * 3 + 1];
            grid_data[index + x_divisions * 3 + 2] = ~grid_data[index + x_divisions * 3 + 2];
        }

        // Bottom
        if (index - x_divisions * 3 > 0)
        {
            grid_data[index - x_divisions * 3 + 0] = ~grid_data[index - x_divisions * 3 + 0];
            grid_data[index - x_divisions * 3 + 1] = ~grid_data[index - x_divisions * 3 + 1];
            grid_data[index - x_divisions * 3 + 2] = ~grid_data[index - x_divisions * 3 + 2];
        }

        // Left
        if (index - 1 > 0)
        {
        grid_data[index - 1] = ~grid_data[index - 1];
        grid_data[index - 2] = ~grid_data[index - 2];
        grid_data[index - 3] = ~grid_data[index - 3];
        }

        // Right
        if (index + 3 < (x_divisions * y_divisions) * 3)
        {
            grid_data[index + 3] = ~grid_data[index + 3];
            grid_data[index + 4] = ~grid_data[index + 4];
            grid_data[index + 5] = ~grid_data[index + 5];
        }

        grid_copy = grid_data;
    }
    else
    {
        // Center
        grid_data[index + 0] = grid_copy[index + 0] + 10;
        grid_data[index + 1] = grid_copy[index + 1] + 10;
        grid_data[index + 2] = grid_copy[index + 2] + 10;

        // Top
        if (index + x_divisions * 3 + 0 < (x_divisions * y_divisions) * 3)
        {
            grid_data[index + x_divisions * 3 + 0] = grid_copy[index + x_divisions * 3 + 0] + 10;
            grid_data[index + x_divisions * 3 + 1] = grid_copy[index + x_divisions * 3 + 1] + 10;
            grid_data[index + x_divisions * 3 + 2] = grid_copy[index + x_divisions * 3 + 2] + 10;
        }

        // Bottom
        if (index - x_divisions * 3 + 0 > 0)
        {
            grid_data[index - x_divisions * 3 + 0] = grid_copy[index - x_divisions * 3 + 0] + 10;
            grid_data[index - x_divisions * 3 + 1] = grid_copy[index - x_divisions * 3 + 1] + 10;
            grid_data[index - x_divisions * 3 + 2] = grid_copy[index - x_divisions * 3 + 2] + 10;
        }

        // Left
        if (index - 1 > 0)
        {
            grid_data[index - 1] = grid_data[index - 1] + 10;
            grid_data[index - 2] = grid_data[index - 2] + 10;
            grid_data[index - 3] = grid_data[index - 3] + 10;
        }

        // Right
        if (index + 3 < (x_divisions * y_divisions) * 3)
        {
            grid_data[index + 3] = grid_data[index + 3] + 10;
            grid_data[index + 4] = grid_data[index + 4] + 10;
            grid_data[index + 5] = grid_data[index + 5] + 10;
        }
    }
}
