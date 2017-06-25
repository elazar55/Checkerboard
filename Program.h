#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <glew.h>
#include "Framework.h"

using namespace std;

class Program
{
  public:
    Program();
    ~Program();

    void   AddShader(const char* path, GLenum type);
    void   Link();
    GLuint GetID();

  private:
    vector<GLuint> shaders;
    GLuint         program;
};

#endif // PROGRAM_H
