#version 440 core

out vec4 output_color;
//
uniform int x_divisions;
uniform int y_divisions;
uniform int window_width;
uniform int window_height;
//
uniform sampler1D grid_sampler;

void main()
{
    int x_divide = (window_width  / x_divisions) + 0;
    int y_divide = (window_height / y_divisions) + 0;

    int index    = (int(gl_FragCoord.x) / x_divide) + (x_divisions *
                   (int(gl_FragCoord.y) / y_divide));

    vec3 value = texelFetch(grid_sampler, index, 0).xyz;

         if (int(gl_FragCoord.x) % x_divide == 0) output_color = vec4(0);
    else if (int(gl_FragCoord.y) % y_divide == 0) output_color = vec4(0);
    else                                          output_color = vec4(value, 1);
}
