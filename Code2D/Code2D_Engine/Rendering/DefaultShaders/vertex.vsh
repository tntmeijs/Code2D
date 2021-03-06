#version 330 core

in layout(location = 0) vec2 a_VertexCoordinate;
in layout(location = 1) vec2 a_TextureCoordinate;

uniform mat4 u_MVP;

out vec2 v_TextureCoordinate;

void main()
{
    gl_Position = u_MVP * vec4(a_VertexCoordinate, 0.0, 1.0);

    // These coordinates have already been flipped in Y on the CPU!
    v_TextureCoordinate = a_TextureCoordinate;
}
