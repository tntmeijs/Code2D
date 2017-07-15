#version 330 core

in layout(location = 0) vec2 a_VertexCoordinate;

out vec4 DebugColor;

void main()
{
    gl_Position = vec4(a_VertexCoordinate, 0.0, 1.0);

    DebugColor = vec4(a_VertexCoordinate, 0.0, 1.0);
}
