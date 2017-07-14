#version 330 core

in layout(location = 0) vec3 a_VertexCoordinate;

void main()
{
    gl_Position = vec4(a_VertexCoordinate, 1.0);
}
