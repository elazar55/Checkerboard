#version 440 core

out vec4 output_color;
uniform sampler2D texture_sampler;

void main()
{
    output_color = texelFetch(texture_sampler, ivec2(gl_FragCoord.x, gl_FragCoord.y), 0);
}
