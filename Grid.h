#ifndef GRID_H
#define GRID_H

#include <glew.h>
#include <GL/gl.h>
#include <SDL.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>
#include "Mouse.h"
using namespace std;

class Grid
{
  public:
    Grid(int x_divisions, int y_divisions, GLuint program_ID);
    ~Grid();

    void Render();
    void HandleMouse(Mouse& mouse);

  private:
    int x_divisions;
    int y_divisions;

    GLuint x_divisions_location;
    GLuint y_divisions_location;
    GLuint grid_texture;

    vector<GLubyte> grid_data;
    vector<GLubyte> grid_copy;
};

#endif  // GRID_H
