#version 440 core

void main()
{
    vec3 quad[] =
    {
        vec3(-1, -1, 0), // Bottom Left
        vec3(-1,  1, 0), // Top Left
        vec3( 1,  1, 0), // Top Right
        vec3( 1,  1, 0), // Top Right
        vec3(-1, -1, 0), // Bottom Left
        vec3( 1, -1, 0)  // Bottom Right
    };

    gl_Position = vec4(quad[gl_VertexID], 1);
}
