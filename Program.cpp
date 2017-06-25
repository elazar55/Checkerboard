#include "Program.h"

Program::Program()
{
    program = glCreateProgram();
}

Program::~Program()
{
}

void Program::AddShader(const char* path, GLenum type)
{
    // Opens file
    const char* src = FileAsString(path);

    // Creates and compiles shader from the file
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    // Length of debug message log
    GLint log_length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

    // Appropriately sized buffer
    GLchar infolog[log_length] = "";
    glGetShaderInfoLog(shader, log_length + 1, nullptr, infolog);

    // Prints if it's not empty
    if (strcmp(infolog, "") != 0) cout << infolog << endl;

    // Exits if it didn't compile
    GLint params = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &params);
    if (params != GL_TRUE) exit(glGetError());

    // Adds the compiled shader ID
    shaders.push_back(shader);
}

void Program::Link()
{
    // Attaches all the shaders to the program
    for (size_t i = 0; i < shaders.size(); i++)
        glAttachShader(program, shaders[i]);

    // Links the OpenGL shaders in the program
    glLinkProgram(program);
    // Gets the length of the debug log
    GLint log_length;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);

    // Appropriately sized buffer
    GLchar infolog[log_length] = "";
    glGetProgramInfoLog(program, log_length + 1, nullptr, infolog);

    // Prints if it's not empty
    if (strcmp(infolog, "") != 0) cout << infolog << endl;

    // Exits completely if linking failed
    GLint param = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &param);
    if (param != GL_TRUE) exit(glGetError());
}

GLuint Program::GetID()
{
    return program;
}
