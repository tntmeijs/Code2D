#version 330 core

in vec2 v_TextureCoordinate;

uniform sampler2D u_Texture;

void main()
{
    gl_FragColor = texture2D(u_Texture, v_TextureCoordinate);
}
